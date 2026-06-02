#include <iostream>

int main(){
    int a = 10;
    int b = 20;

    const int* p1 = &a;
    // *p1 = 30; // 에러
    p1 = &b; // 가능
    std::cout << "*p1: " << *p1 << "\n";

    int* const p2 = &a;
    *p2 = 30; // 가능
    // p2 = &b; // 에러
    std::cout << "*p2: " << *p2 << "\n";
}