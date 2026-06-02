#include <iostream>
#include <cstring>
#include <utility>

// Rule of 5: 소멸자/복사/이동 중 하나라도 정의하면 나머지도 명시적으로 관리
class Buffer {
public:
    explicit Buffer(std::size_t n)
        : data_(new char[n]), size_(n)
    {
        std::memset(data_, 0, size_);
        std::cout << "  Buffer(" << size_ << ") constructed\n";
    }

    // 1. 소멸자
    ~Buffer() {
        std::cout << "  ~Buffer(" << size_ << ") destroyed\n";
        delete[] data_;
    }

    // 2. 복사 생성자 (깊은 복사)
    Buffer(const Buffer& other)
        : data_(new char[other.size_]), size_(other.size_)
    {
        std::memcpy(data_, other.data_, size_);
        std::cout << "  Buffer copy-constructed from size=" << size_ << "\n";
    }

    // 3. 복사 대입 연산자 (copy-and-swap idiom)
    Buffer& operator=(Buffer other) noexcept {
        swap(*this, other);
        std::cout << "  Buffer copy/move assigned, size=" << size_ << "\n";
        return *this;
    }

    // 4. 이동 생성자
    Buffer(Buffer&& other) noexcept
        : data_(other.data_), size_(other.size_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        std::cout << "  Buffer move-constructed, size=" << size_ << "\n";
    }

    // 5. 이동 대입은 copy-and-swap으로 커버됨 (위 3번)

    std::size_t size() const { return size_; }

    friend void swap(Buffer& a, Buffer& b) noexcept {
        using std::swap;
        swap(a.data_, b.data_);
        swap(a.size_, b.size_);
    }

private:
    char*       data_;
    std::size_t size_;
};

// Rule of Zero: 자원을 직접 관리하지 않으면 특수 멤버를 정의하지 않아도 됨
class Config {
public:
    std::string name;
    int value = 0;
    // 컴파일러가 자동 생성하는 복사/이동/소멸자로 충분
};

Buffer make_buffer(std::size_t n) {
    return Buffer(n);  // RVO(Return Value Optimization)로 복사 없음
}

int main() {
    std::cout << "=== Construction ===\n";
    Buffer b1(64);

    std::cout << "\n=== Copy ===\n";
    Buffer b2 = b1;   // 복사 생성자

    std::cout << "\n=== Move ===\n";
    Buffer b3 = std::move(b1);  // 이동 생성자, b1은 비워짐

    std::cout << "\n=== Assignment ===\n";
    b2 = Buffer(128);  // 이동 대입

    std::cout << "\n=== RVO ===\n";
    Buffer b4 = make_buffer(32);  // 복사 없이 직접 생성

    std::cout << "\n=== Rule of Zero ===\n";
    Config c1{"test", 42};
    Config c2 = c1;
    c2.name = "copy";
    std::cout << "c1.name=" << c1.name << "  c2.name=" << c2.name << "\n";

    std::cout << "\n=== Destruction ===\n";
}
