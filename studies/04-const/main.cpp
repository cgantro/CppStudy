#include <iostream>
#include <array>

// const: 런타임 상수 (변경 불가, 초기값 불필요)
// constexpr: 컴파일 타임 상수 (반드시 컴파일 타임에 결정)
// consteval: 반드시 컴파일 타임에만 호출 가능 (C++20)
// constinit: 정적 초기화 보장, 상수는 아님 (C++20)

constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// consteval: 런타임 호출 시 컴파일 오류
consteval int square(int n) { return n * n; }

// constinit: 초기화 순서 문제(static initialization order fiasco)를 방지
constinit static int global_val = factorial(5);  // 컴파일 타임 초기화 보장

// constexpr 클래스
struct Vec2 {
    double x, y;
    constexpr Vec2(double x, double y) : x(x), y(y) {}
    constexpr Vec2 operator+(Vec2 o) const { return {x+o.x, y+o.y}; }
    constexpr double dot(Vec2 o)     const { return x*o.x + y*o.y; }
};

int main() {
    std::cout << "=== constexpr ===\n";
    constexpr int f5 = factorial(5);  // 컴파일 타임
    static_assert(f5 == 120, "factorial(5) must be 120");
    std::cout << "factorial(5) = " << f5 << "\n";

    // constexpr 배열 크기
    constexpr std::array<int, factorial(4)> arr{};
    std::cout << "array size = " << arr.size() << "\n";

    std::cout << "\n=== consteval ===\n";
    constexpr int sq = square(7);  // OK: 컴파일 타임
    std::cout << "square(7) = " << sq << "\n";
    // int x = 7; square(x);  // 컴파일 오류: consteval은 런타임 불가

    std::cout << "\n=== constinit ===\n";
    std::cout << "global_val = " << global_val << "\n";
    global_val = 999;  // constinit은 const가 아니므로 변경 가능
    std::cout << "after modify = " << global_val << "\n";

    std::cout << "\n=== constexpr class ===\n";
    constexpr Vec2 a{1.0, 2.0}, b{3.0, 4.0};
    constexpr Vec2 c = a + b;
    constexpr double d = a.dot(b);
    static_assert(d == 11.0);
    std::cout << "a+b = (" << c.x << "," << c.y << ")\n";
    std::cout << "a·b = " << d << "\n";
}
