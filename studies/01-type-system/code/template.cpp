#include <iostream>
#include <type_traits>

template <typename T>
void printCategory(){
    if constexpr (std::is_integral_v<T>){
        std::cout << "Integral\n";
    } else if constexpr(std::is_floating_point_v<T>){
        std::cout << "floating point\n";
    }else std:: cout << "other\n";
}

int main() {
    printCategory<int>();
    printCategory<double>();
    printCategory<std::string>();
}