#include <iostream>
#include <type_traits>

// 배열과 포인터는 다르다.
void printLine() {
    std::cout << "=====================\n";
}
void p1(){
    printLine();
    int arr[3] = {1,2,3};

    std::cout << std::boolalpha;
    std::cout << std::is_same_v<decltype(arr), int[3]> << '\n'; // true
    std::cout << std::is_same_v<decltype(arr), int (*)[3]> << '\n'; // false
}

// 함수 인자로 배열을 받으면 포인터로 조정된다.
void p2(int arr[3]){
    printLine();
    // arr는 실제로 int* 타입이다.
    std::cout << sizeof(arr) << '\n'; // 8 (포인터 크기)
}

// 배열 크기를 보존하려면 참조를 사용한다.
void p3(int (&arr)[3]){
    printLine();
    std::cout << sizeof(arr) << '\n'; // 12 (배열 크기)
}
int main() {
    p1();
    int arr[3] = {4,5,6};
    std::cout << sizeof(arr) << '\n'; // 12 (배열 크기)
    p2(arr);
    p3(arr);
}