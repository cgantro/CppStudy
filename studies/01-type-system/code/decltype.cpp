#include <type_traits>
#include <utility>
#include <iostream>

// decltype: 식의 타입을 추론하는 연산자
// decltype(expr) -> expr의 타입을 반환
void printLine() {
    std::cout << "=====================\n";
}
void p1(){
    printLine();
    int x = 10;
    static_assert(std::is_same_v<decltype(x), int>);
    static_assert(std::is_same_v<decltype((x)), int&>);
}

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// c++ 14 이후에는 간단히 쓸 수 있음
template<typename T, typename U>
auto add_auto(T a, U b) {
    return a + b;
}  


int global = 42;
int& getRef() { return global; }
auto f1() { return getRef(); } // 반환 타입은 int (값으로 반환)
// 반환 타입을 보존해야 할 때>
decltype(auto) f2() {
    return getRef();
}


int main(){
    p1();

    // f1() = 100; // f1()은 int 반환, 값으로 반환되므로 global이 변경되지 않음
    std::cout << "global after f1(): " << global << "\n"; // error 발생
    f2() = 200; // f2()은 int& 반환, 참조로 반환되므로 global이 변경됨
    std::cout << "global after f2(): " << global << "\n"; // 200
}