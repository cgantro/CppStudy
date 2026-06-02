#include <iostream>
#include <span>
#include <cstring>

// 포인터 산술: 포인터 + n은 sizeof(T)*n 바이트 이동
void pointer_arithmetic() {
    std::cout << "=== Pointer Arithmetic ===\n";
    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr;
    std::cout << "arr[0]=" << *p << "  addr=" << p << "\n";
    p += 2;
    std::cout << "arr[2]=" << *p << "  addr=" << p << "\n";
    std::cout << "diff (elements): " << (p - arr) << "\n";
}

// 함수 포인터: 함수를 값처럼 다루기
int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

void function_pointer_demo() {
    std::cout << "\n=== Function Pointers ===\n";
    using BinOp = int(*)(int, int);
    BinOp ops[] = {add, mul};
    const char* names[] = {"add", "mul"};
    for (int i = 0; i < 2; ++i)
        std::cout << names[i] << "(3,4) = " << ops[i](3, 4) << "\n";
}

// void*: 타입 정보 없는 포인터 (C 스타일)
void void_ptr_demo() {
    std::cout << "\n=== void* ===\n";
    int x = 42;
    void* vp = &x;
    // *vp는 불가능 — 타입을 알아야 역참조 가능
    int* ip = static_cast<int*>(vp);
    std::cout << "via void*: " << *ip << "\n";
}

// std::span: 배열/벡터의 비소유 뷰 (C++20)
void span_demo() {
    std::cout << "\n=== std::span (C++20) ===\n";
    int data[] = {1, 2, 3, 4, 5};
    std::span<int> s{data};          // 전체
    std::span<int> sub = s.subspan(1, 3); // [1..3]
    for (int v : sub) std::cout << v << " ";
    std::cout << "\n";
    std::cout << "size=" << s.size() << "  data addr=" << s.data() << "\n";
}

// const 포인터 vs 포인터 to const
void const_ptr_demo() {
    std::cout << "\n=== const Pointer Variants ===\n";
    int a = 1, b = 2;
    const int* ptr_to_const = &a;  // 가리키는 값 변경 불가
    int* const const_ptr    = &a;  // 포인터 자체 변경 불가

    ptr_to_const = &b;             // OK: 포인터는 바꿀 수 있음
    *const_ptr   = 99;             // OK: 값은 바꿀 수 있음
    (void)ptr_to_const;
    std::cout << "a=" << a << "\n";
}

int main() {
    pointer_arithmetic();
    function_pointer_demo();
    void_ptr_demo();
    span_demo();
    const_ptr_demo();
}
