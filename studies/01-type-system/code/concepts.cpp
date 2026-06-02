#include<concepts>
#include <iostream>

// C++20 Concepts: 템플릿 매개변수에 대한 제약 조건을 명시적으로 표현하는 기능
// std::integral: T가 정수형 타입인지 검사하는 개념
template<std::integral T>
T add(T a, T b) {
    return a + b;
}

// 직접 만들 수 있음
template<typename T>
concept HasSize = requires(T a) {
    { a.size() } -> std::convertible_to<std::size_t>;
};

template<HasSize T>
void printSize(const T& container) {
    std::cout << "Size: " << container.size() << "\n";
}

int main () {
    std::cout << add(1, 2) << "\n"; // OK
    // std::cout << add(1.5, 2.5) << "\n"; // 컴파일 에러: double은 integral이 아님
}