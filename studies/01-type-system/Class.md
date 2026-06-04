## 클래스 타입

데이터와 동작을 함께 묶는 사용자 정의 타입이다.  
중요한 것은 **값 타입 / 소유 타입 / 참조 타입** 중 무엇인지를 설계 시 분명히 하는 것이다.

```cpp
#include <string>

class User {
public:
    User(std::string name, int age)
        : name_(std::move(name)), age_(age) {}

    const std::string& name() const { return name_; }
    int age() const { return age_; }

private:
    std::string name_;
    int age_;
};
```

---

### `struct` vs `class`

기술적 차이는 기본 접근 지정자뿐이다.

| | `struct` | `class` |
|---|---|---|
| 기본 접근 지정자 | `public` | `private` |
| 관례 | 데이터 위주의 단순 집합체 | 불변식을 캡슐화하는 타입 |

---

### 값 타입 (Value Type)

복사되어도 의미가 유지된다. 각 복사본은 독립적이다.

```cpp
struct Vec2 {
    float x, y;
};

Vec2 add(Vec2 a, Vec2 b) {
    return Vec2{a.x + b.x, a.y + b.y};
}
```

좌표, 색상, 설정값, ID 래퍼 등에 적합하다.

---

### 소유 타입 (Owning Type)

자원(힙 메모리, 파일 핸들 등)의 수명을 관리한다. 복사 · 이동 정책을 명확히 해야 한다.

```cpp
class NonCopyableBuffer {
public:
    explicit NonCopyableBuffer(std::size_t size)
        : data_(std::make_unique<char[]>(size)), size_(size) {}

    NonCopyableBuffer(const NonCopyableBuffer&)            = delete;
    NonCopyableBuffer& operator=(const NonCopyableBuffer&) = delete;

    NonCopyableBuffer(NonCopyableBuffer&&) noexcept            = default;
    NonCopyableBuffer& operator=(NonCopyableBuffer&&) noexcept = default;

private:
    std::unique_ptr<char[]> data_;
    std::size_t size_;
};
```

---

### 참조 타입 (Reference/Observer Type)

소유하지 않고 다른 객체를 관찰하거나 접근만 한다. 원본보다 수명이 짧아야 한다.

```cpp
class BufferView {
public:
    explicit BufferView(const char* data, std::size_t size)
        : data_(data), size_(size) {}

    std::size_t size() const { return size_; }
    char operator[](std::size_t i) const { return data_[i]; }

private:
    const char* data_;  // 소유하지 않음
    std::size_t size_;
};
```

`std::string_view`, `std::span` 등이 표준 라이브러리의 참조 타입 예시다.

---

### Rule of Zero / Rule of Five

**Rule of Zero**: 소멸자, 복사/이동 생성자, 복사/이동 대입 연산자 5가지를 직접 정의하지 않는다.  
자원 관리를 `std::unique_ptr`, `std::vector` 등 RAII 타입에 맡기면 컴파일러가 5가지를 올바르게 자동 생성한다.

```cpp
class Good {
    std::unique_ptr<int> ptr_;  // 자동으로 Rule of Five 처리됨
    std::vector<int> data_;
};
```

**Rule of Five**: 소멸자를 직접 정의하면 나머지 4개도 명시적으로 정의해야 한다.  
컴파일러가 자동 생성하는 복사/이동이 의도대로 동작하지 않을 수 있기 때문이다.

```cpp
class FileHandle {
public:
    explicit FileHandle(const char* path) : fd_(open(path)) {}
    ~FileHandle() { close(fd_); }  // 소멸자 정의

    // 소멸자를 정의했으므로 나머지 4개도 명시해야 함
    FileHandle(const FileHandle&)            = delete;
    FileHandle& operator=(const FileHandle&) = delete;
    FileHandle(FileHandle&& other) noexcept : fd_(other.fd_) { other.fd_ = -1; }
    FileHandle& operator=(FileHandle&& other) noexcept {
        if (this != &other) { close(fd_); fd_ = other.fd_; other.fd_ = -1; }
        return *this;
    }
private:
    int fd_;
    int open(const char*);
    void close(int);
};
```
