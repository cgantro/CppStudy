## 클래스 타입

데이터와 동작을 함께 묶는 사용자 정의 타입

```cpp
// 중요한 것은 값, 소유, 참조 타입인지 분명히 하는 것
#include <string>

class User {
public:
    User(std::string name, int age)
        : name_(std::move(name)), age_(age) {}

    const std::string& name() const {
        return name_;
    }

    int age() const {
        return age_;
    }

private:
    std::string name_;
    int age_;
};
```

### 값 타입

값 타입은 복사되어도 의미가 유지된다.

- 좌표, 색상, 설정ㄱ밧, ID 래퍼 등에 적합하다.

```cpp
struct Vec2{
    float x;
    float y;
};

Vec2 add(Vec2 a, Vec2 b){
    return Vec2{a.x + b.x, a.y + b.y};
}
```

### 소유 타입

소유 타입은 복사, 이동 정책을 명확히 해야 한다.

```cpp
#include <memory>
#include <vector>

class Buffer{
public:
    explicit Buffer(std::size_t size):
        data_(std::make_unique<char[]>(size), size_(size)){}
private:
    std::unique_ptr<char[]> data_;
    std::size_t size_;
}

// 복사 불가 버퍼
// 복사는 안되고, 소유권이 변하는 이동 연산은 소유권 및 성능에 무리가 없음
class NonCopyableBuffer {
public:
    explicit NonCopyableBuffer(std::size_t size) // explicit은 암시적 형변환을 막아주는 안전 장치
        : data_(std::make_unique<char[]>(size)), size_(size) {}

    NonCopyableBuffer(const NonCopyableBuffer&) = delete; // 복사 생성자 금지
    NonCopyableBuffer& operator=(const NonCopyableBuffer&) = delete; // 복사 대입 금지

    NonCopyableBuffer(NonCopyableBuffer&&) noexcept = default; // 이동 생성자 자동 생성
    NonCopyableBuffer& operator= (NonCopyableBuffer&&) noexcept = default; // 이동 대입 연산자 자동 생성

private:
    std::unique_ptr<char[]> data_; // 소유권이 단 하나만 존재하는 스마트 포인터
    // 복사가 불가능하고, 이동만 가능한 객체
    std::size_t size_;
};
```
