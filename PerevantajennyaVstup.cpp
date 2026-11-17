#include <iostream>
#include <numeric>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        if (denominator == 0) return;
        int common = std::gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) {
        numerator = num;
        denominator = den != 0 ? den : 1;
        simplify();
    }

    void input() {
        std::cout << "Введіть чисельник: ";
        std::cin >> numerator;
        std::cout << "Введіть знаменник: ";
        std::cin >> denominator;
        if (denominator == 0) {
            denominator = 1;
        }
        simplify();
    }

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator,
            denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator,
            denominator * other.numerator);
    }
};

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    void input() {
        std::cout << "Введіть дійсну частину: ";
        std::cin >> real;
        std::cout << "Введіть уявну частину: ";
        std::cin >> imag;
    }

    void print() const {
        if (imag >= 0) {
            std::cout << real << " + " << imag << "i" << std::endl;
        }
        else {
            std::cout << real << " - " << -imag << "i" << std::endl;
        }
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }
};

int main() {
    system("chcp 1251>null");
    std::cout << "=== Тестування класу Fraction ===\n";
    Fraction f1(1, 2);
    Fraction f2(1, 3);

    Fraction f_sum = f1 + f2;
    Fraction f_diff = f1 - f2;
    Fraction f_prod = f1 * f2;
    Fraction f_quot = f1 / f2;

    std::cout << "Дріб 1: "; f1.print();
    std::cout << "Дріб 2: "; f2.print();
    std::cout << "Сума: "; f_sum.print();
    std::cout << "Різниця: "; f_diff.print();
    std::cout << "Добуток: "; f_prod.print();
    std::cout << "Частка: "; f_quot.print();

    std::cout << "\n=== Тестування класу Complex ===\n";
    Complex c1(3.0, 2.0);
    Complex c2(1.0, 4.0);

    Complex c_sum = c1 + c2;
    Complex c_diff = c1 - c2;
    Complex c_prod = c1 * c2;
    Complex c_quot = c1 / c2;

    std::cout << "Комплексне 1: "; c1.print();
    std::cout << "Комплексне 2: "; c2.print();
    std::cout << "Сума: "; c_sum.print();
    std::cout << "Різниця: "; c_diff.print();
    std::cout << "Добуток: "; c_prod.print();
    std::cout << "Частка: "; c_quot.print();

    return 0;
}
