#include <variant>
#include <string>
#include <iostream>

using Event = std::variant<int,std::string>;
void handle(const Event& e){
    std::visit([](const auto & value){
        std::cout << value << '\n';
    }, e);
}

int main() {
    Event e1 = 42;
    Event e2 = std::string("Hello, Variant!");

    handle(e1); // 42 출력
    handle(e2); // "Hello, Variant!" 출력
}