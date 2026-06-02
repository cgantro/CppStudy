#include<iostream>
#include<memory>

struct Animal{
    // 가상 소멸자: 다형성에서 올바른 소멸을 보장하기 위해 필요
    // 만약 Animal* ptr = new Dog(); delete ptr; 할 때, Dog의 소멸자가 호출되도록 보장
    virtual ~Animal() = default; 

    virtual void speak() const {
        std::cout << "Animal speaks\n";
    }
};

struct Dog : Animal{
    void speak() const override {
        std::cout << "Woof!\n";
    }
};

// Virtual이 없으면 정적 타입 기준으로 호출함
struct Base{
    void f() const{
        std::cout << "Base::f()\n";
    }
};

struct Derived : Base{
    void f() const{
        std::cout << "Derived::f()\n";
    }
};

int main() {
    std::unique_ptr<Animal> pet = std::make_unique<Dog>();
    pet->speak(); // "Woof!" 출력
    // pet이 범위를 벗어나면 Dog의 소멸자가 호출되어 메모리가 올바르게 해제됨

    Derived d;
    Base* b = &d;
    b->f(); // Base::f() 출력 (Virtual이 없어서 정적 타입 기준으로 호출)    
    // b->f()가 Derived::f()를 호출하려면 Base::f()를 virtual로 선언해야 함
}