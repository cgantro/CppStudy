#include <iostream>
#include <cstdint>
#include <type_traits>

// lvalue: 식별자가 있고 주소를 취할 수 있는 식
// prvalue: 임시 값, 주소 없음
// xvalue: 이동될 수 있는 lvalue ("expired value")

int global = 42;
int& get_lvalue()  { return global; }
int  get_prvalue() { return 42; }
int&& get_xvalue() { return std::move(global); }

template<typename T>
constexpr const char* category() {
    if constexpr (std::is_lvalue_reference_v<T>) return "lvalue-ref";
    else if constexpr (std::is_rvalue_reference_v<T>)  return "rvalue-ref";
    else return "value";
}

// universal reference: T&& in template context
template<typename T>
void inspect(T&& arg) {
    std::cout << "  deduced T = " << category<T>() << "\n";
    (void)arg;
}

// decltype 규칙
// decltype(name)   -> 선언된 타입 그대로
// decltype((expr)) -> 식의 값 카테고리 반영 (lvalue -> T&)
static_assert(std::is_same_v<decltype(global),   int>);
static_assert(std::is_same_v<decltype((global)),  int&>);
static_assert(std::is_same_v<decltype(42),        int>);

int main() {
    int x = 10;

    std::cout << "=== Value Categories ===\n";
    std::cout << "x (lvalue):        "; inspect(x);
    std::cout << "42 (prvalue):      "; inspect(42);
    std::cout << "move(x) (xvalue):  "; inspect(std::move(x));

    std::cout << "\n=== Type Traits ===\n";
    std::cout << "is_integral<int>     : " << std::is_integral_v<int>      << "\n";
    std::cout << "is_pointer<int*>     : " << std::is_pointer_v<int*>       << "\n";
    std::cout << "is_const<const int>  : " << std::is_const_v<const int>   << "\n";
    std::cout << "is_same<int,int32_t> : " << std::is_same_v<int,int32_t>  << "\n";

    std::cout << "\n=== sizeof / alignof ===\n";
    std::cout << "char  : " << sizeof(char)   << " / " << alignof(char)   << "\n";
    std::cout << "int   : " << sizeof(int)    << " / " << alignof(int)    << "\n";
    std::cout << "double: " << sizeof(double) << " / " << alignof(double) << "\n";
    std::cout << "void* : " << sizeof(void*)  << " / " << alignof(void*)  << "\n";
}
