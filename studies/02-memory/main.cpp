#include <iostream>
#include <cstdlib>
#include <new>
#include <memory>

// 스택: 자동 해제, 크기 제한, 빠른 접근
// 힙:  수동 관리, 크기 유연, 느린 접근 (malloc/new)

struct Aligned {
    alignas(64) char data[64]; // 캐시 라인 정렬
};

// placement new: 이미 할당된 메모리에 객체 생성
struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {
        std::cout << "  Point(" << x << "," << y << ") constructed at " << this << "\n";
    }
    ~Point() { std::cout << "  Point destroyed at " << this << "\n"; }
};

void stack_vs_heap() {
    std::cout << "=== Stack vs Heap ===\n";
    int stack_var = 42;
    int* heap_var = new int(42);
    std::cout << "stack addr: " << &stack_var << "\n";
    std::cout << "heap  addr: " << heap_var   << "\n";
    delete heap_var;
}

void placement_new_demo() {
    std::cout << "\n=== Placement new ===\n";
    alignas(alignof(Point)) char buf[sizeof(Point)];
    std::cout << "buffer addr: " << static_cast<void*>(buf) << "\n";

    Point* p = new(buf) Point(1.0, 2.0);  // 버퍼에 직접 생성
    std::cout << "p->x=" << p->x << " p->y=" << p->y << "\n";
    p->~Point();  // placement new는 명시적 소멸자 호출 필요
}

void array_new_demo() {
    std::cout << "\n=== Array new/delete ===\n";
    // new[]와 delete[]는 반드시 쌍으로
    int* arr = new int[5]{1,2,3,4,5};
    for (int i = 0; i < 5; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
    delete[] arr;
}

void nothrow_demo() {
    std::cout << "\n=== nothrow new ===\n";
    // 할당 실패 시 예외 대신 nullptr 반환
    void* p = operator new(1024ULL * 1024 * 1024 * 100, std::nothrow);
    if (!p) std::cout << "100GB allocation failed (expected)\n";
}

int main() {
    stack_vs_heap();
    placement_new_demo();
    array_new_demo();
    nothrow_demo();

    std::cout << "\n=== Alignment ===\n";
    std::cout << "Aligned size:  " << sizeof(Aligned)  << "\n";
    std::cout << "Aligned align: " << alignof(Aligned) << "\n";
}
