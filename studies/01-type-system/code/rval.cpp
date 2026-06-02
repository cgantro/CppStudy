#include <iostream>
#include <string>
#include <utility>

struct Buffer{
    std::string data;

    Buffer(std::string d) : data(std::move(d)){}

    // 복사 생성자
    Buffer(const Buffer& other) : data(other.data) {
        std::cout << "Copy constructor called\n";
    }

    // 이동 생성자
    Buffer(Buffer&& other) : data(std::move(other.data)) {
        std::cout << "Move constructor called\n";
    }
};

int main() {
    Buffer buf1("Hello, World!");
    Buffer buf2 = buf1; // 복사 생성자 호출
    Buffer buf3 = std::move(buf1); // 이동 생성자 호출

    std::cout << "buf1: " << buf1.data << "\n"; // 빈 문자열
    std::cout << "buf2: " << buf2.data << "\n"; // "Hello, World!"
    std::cout << "buf3: " << buf3.data << "\n"; // "Hello, World!"
}