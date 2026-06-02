#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

// 오버로딩: 이름은 같고 시그니처가 다른 함수
void print(int x)         { std::cout << "int: "    << x << "\n"; }
void print(double x)      { std::cout << "double: " << x << "\n"; }
void print(const char* s) { std::cout << "str: "    << s << "\n"; }

// 기본 인자: 오른쪽에서부터만 가능
void connect(const char* host, int port = 80, bool tls = false) {
    std::cout << "connect " << host << ":" << port << (tls ? " (TLS)" : "") << "\n";
}

// std::function: 함수, 람다, 멤버 함수 등 모두 저장 가능
using Transform = std::function<int(int)>;

int apply(int x, Transform fn) { return fn(x); }

// 람다: [캡처](파라미터) -> 반환타입 { 몸체 }
void lambda_demo() {
    std::cout << "\n=== Lambda ===\n";
    int offset = 10;

    // 값 캡처: 람다 생성 시점의 offset 복사
    auto add_offset_by_val = [offset](int x) { return x + offset; };
    offset = 999;
    std::cout << "by-value capture: " << add_offset_by_val(5) << "\n"; // 15

    // 참조 캡처: 람다 호출 시점의 offset 사용
    auto add_offset_by_ref = [&offset](int x) { return x + offset; };
    std::cout << "by-ref  capture: " << add_offset_by_ref(5) << "\n"; // 1004

    // 제네릭 람다 (C++14)
    auto identity = [](auto x) { return x; };
    std::cout << "generic lambda: " << identity(3.14) << "\n";

    // 즉시 호출 람다 (IIFE)
    int result = [](int a, int b){ return a * b; }(6, 7);
    std::cout << "IIFE result: " << result << "\n";
}

// 고차 함수 패턴
std::vector<int> map(std::vector<int> v, Transform fn) {
    for (auto& x : v) x = fn(x);
    return v;
}

int main() {
    std::cout << "=== Overloading ===\n";
    print(42);
    print(3.14);
    print("hello");

    std::cout << "\n=== Default Args ===\n";
    connect("example.com");
    connect("example.com", 443, true);

    std::cout << "\n=== std::function ===\n";
    Transform double_it = [](int x){ return x * 2; };
    std::cout << "apply(5, double_it) = " << apply(5, double_it) << "\n";

    lambda_demo();

    std::cout << "\n=== Higher-order ===\n";
    auto v = map({1,2,3,4,5}, [](int x){ return x * x; });
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}
