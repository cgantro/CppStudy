#include <iostream>
#include <string>
#include <stdexcept>

class BankAccount {
public:
    // 생성자 위임 (C++11)
    BankAccount(std::string owner, double balance)
        : owner_(std::move(owner)), balance_(balance)
    {
        if (balance_ < 0) throw std::invalid_argument("balance cannot be negative");
    }

    explicit BankAccount(std::string owner) : BankAccount(std::move(owner), 0.0) {}

    // const 멤버 함수: 객체 상태 변경 불가
    double balance() const { return balance_; }
    const std::string& owner() const { return owner_; }

    void deposit(double amount) {
        if (amount <= 0) throw std::invalid_argument("amount must be positive");
        balance_ += amount;
        log("deposit", amount);
    }

    void withdraw(double amount) {
        if (amount > balance_) throw std::runtime_error("insufficient funds");
        balance_ -= amount;
        log("withdraw", amount);
    }

    // 정적 멤버: 인스턴스 없이 접근 가능
    static int total_accounts() { return s_count_; }

private:
    std::string owner_;
    double      balance_;
    inline static int s_count_ = 0; // C++17: inline static 멤버

    void log(const char* op, double amount) const {
        std::cout << "[" << owner_ << "] " << op << " " << amount
                  << " -> balance=" << balance_ << "\n";
    }

    // friend: 특정 함수/클래스에 private 접근 허용
    friend std::ostream& operator<<(std::ostream& os, const BankAccount& acc);
};

std::ostream& operator<<(std::ostream& os, const BankAccount& acc) {
    return os << "Account{owner=" << acc.owner_ << ", balance=" << acc.balance_ << "}";
}

// struct: 기본 접근 지정자가 public
struct Point {
    double x = 0, y = 0;
    double length() const { return x*x + y*y; } // 제곱 거리
};

int main() {
    std::cout << "=== BankAccount ===\n";
    BankAccount acc("Alice", 1000.0);
    acc.deposit(500.0);
    acc.withdraw(200.0);
    std::cout << acc << "\n";

    std::cout << "\n=== explicit constructor ===\n";
    // BankAccount b = "Bob";  // 컴파일 오류: explicit
    BankAccount b("Bob");
    std::cout << b << "\n";

    std::cout << "\n=== Exception from constructor ===\n";
    try {
        BankAccount bad("Eve", -100);
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << "\n";
    }

    std::cout << "\n=== struct Point ===\n";
    Point p{3.0, 4.0};
    std::cout << "length^2 = " << p.length() << "\n";
}
