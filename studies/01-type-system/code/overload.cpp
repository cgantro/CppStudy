#include <iostream>

void log(int)

void log(double)

void log(const char*)

int main() {
    log(42);          // log(int) 호출
    log(3.14);        // log(double) 호출
    log("Hello");     // log(const char*) 호출
}