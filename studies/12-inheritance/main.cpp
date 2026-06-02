#include <iostream>
#include <memory>
#include <vector>

// 가상 함수 테이블(vtable): 각 클래스마다 하나, 객체에는 vptr(포인터) 포함
class Shape {
public:
    Shape(const char* name) : name_(name) {}
    virtual ~Shape() = default;  // 파생 클래스 소멸자도 올바르게 호출되도록 virtual

    virtual double area()     const = 0;
    virtual double perimeter() const = 0;

    // 비가상 함수: 정적 디스패치
    void describe() const {
        std::cout << name_ << ": area=" << area() << " perimeter=" << perimeter() << "\n";
    }

    const char* name() const { return name_; }

private:
    const char* name_;
};

class Circle : public Shape {
public:
    explicit Circle(double r) : Shape("Circle"), r_(r) {}

    double area()      const override { return 3.14159 * r_ * r_; }
    double perimeter() const override { return 2 * 3.14159 * r_; }

private:
    double r_;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape("Rectangle"), w_(w), h_(h) {}

    double area()      const override { return w_ * h_; }
    double perimeter() const override { return 2 * (w_ + h_); }

private:
    double w_, h_;
};

// final: 더 이상 상속 불가
class Square final : public Rectangle {
public:
    explicit Square(double s) : Rectangle(s, s) {}
};

// 다중 상속
struct Printable {
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

class Label : public Shape, public Printable {
public:
    Label(const char* text) : Shape("Label"), text_(text) {}
    double area()      const override { return 0; }
    double perimeter() const override { return 0; }
    void print()       const override { std::cout << "Label: " << text_ << "\n"; }
private:
    const char* text_;
};

int main() {
    std::cout << "=== Virtual Dispatch ===\n";
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Square>(3.0));

    for (const auto& s : shapes) s->describe();

    std::cout << "\n=== vptr size overhead ===\n";
    struct Plain    { int x; };
    struct Virtual  { int x; virtual ~Virtual() = default; };
    std::cout << "Plain size:   " << sizeof(Plain)   << "\n";
    std::cout << "Virtual size: " << sizeof(Virtual) << " (includes vptr)\n";

    std::cout << "\n=== Multiple Inheritance ===\n";
    Label lbl("Hello");
    lbl.describe();
    lbl.print();
}
