#include <functional>
#include <iostream>

void printLine() {
    std::cout << "=====================\n";
}
int add(int a, int b) {
    return a + b;
}

// 함수 포인터: 함수의 주소를 저장하는 포인터
void p1() {
    printLine();
    int (*fp)(int,int) = add;
    int result = fp(1,2);
    std::cout << result << '\n';
}

// 람다, std::function, auto를 사용하면 더 편리하게 함수 객체를 사용할 수 있다.
void p2(){
    printLine();
    auto lambda = [](int a, int b) { return a + b; };
    std::function<int(int,int)> func = lambda;
    std::cout << func(3,4) << '\n';
}
int main(){
    p1();
    p2();
    return 0;
}