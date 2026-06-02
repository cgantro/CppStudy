#include <iostream>


bool nearly_equal(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}
int main(){
    double a = 0.1 + 0.2;
    std::cout << std::boolalpha;
    std::cout << "a == 0.3: " << (a == 0.3) << "\n"; // false
    std::cout << "a nearly equals 0.3: " << nearly_equal(a, 0.3) << "\n"; // true
}