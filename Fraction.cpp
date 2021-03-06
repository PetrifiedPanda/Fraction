#include "Fraction.h"

#include <algorithm>
#include <stdexcept>

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a < b)
        std::swap(a, b);

    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

Fraction::Fraction(int counter, int denominator) : numerator_(counter), denominator_(denominator) {
    if (denominator == 0)
        throw std::runtime_error("Denominator may not be 0");
    reduce();
}

Fraction::Fraction(int num) : numerator_(num), denominator_(1) {}

int Fraction::numerator() const {
    return numerator_;
}

int Fraction::denominator() const {
    return denominator_;
}

// Comparision operators

bool Fraction::operator==(const Fraction& other) const {
    int dLcm = lcm(denominator_, other.denominator_);
    return numerator_ * (dLcm / denominator_) == other.numerator_ * (dLcm / other.denominator_);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    int dLcm = lcm(denominator_, other.denominator_);
    return numerator_ * (dLcm / denominator_) < other.numerator_ * (dLcm / other.denominator_);
}

bool Fraction::operator<=(const Fraction& other) const {
    int dLcm = lcm(denominator_, other.denominator_);
    return numerator_ * (dLcm / denominator_) <= other.numerator_ * (dLcm / other.denominator_);
}

bool Fraction::operator>(const Fraction& other) const {
    int dLcm = lcm(denominator_, other.denominator_);
    return numerator_ * (dLcm / denominator_) > other.numerator_ * (dLcm / other.denominator_);
}

bool Fraction::operator>=(const Fraction& other) const {
    int dLcm = lcm(denominator_, other.denominator_);
    return numerator_ * (dLcm / denominator_) >= other.numerator_ * (dLcm / other.denominator_);
}

// Arithmetic operations

Fraction& Fraction::operator+=(const Fraction& other) {
    int dLcm = lcm(denominator_, other.denominator_);
    numerator_ = numerator_ * (dLcm / denominator_) + other.numerator_ * (dLcm / other.denominator_);
    denominator_ = dLcm;
    reduce();

    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    int dLcm = lcm(denominator_, other.denominator_);
    numerator_ = numerator_ * (dLcm / denominator_) - other.numerator_ * (dLcm / other.denominator_);
    denominator_ = dLcm;
    reduce();

    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    numerator_ *= other.numerator_;
    denominator_ *= other.denominator_;
    reduce();

    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    numerator_ *= other.denominator_;
    denominator_ *= other.numerator_;
    reduce();

    return *this;
}


Fraction& Fraction::operator+=(int num) {
    numerator_ = numerator_ + num * denominator_;
    reduce();

    return *this;
}

Fraction& Fraction::operator-=(int num) {
    numerator_ = numerator_ - num * denominator_;
    reduce();

    return *this;
}

Fraction& Fraction::operator*=(int num) {
    numerator_ *= num;
    reduce();

    return *this;
}

Fraction& Fraction::operator/=(int num) {
    denominator_ *= num;
    reduce();

    return *this;
}

Fraction Fraction::operator-() const {
    return *this * (-1);
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result(*this);
    result += other;
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result(*this);
    result -= other;
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result(*this);
    result *= other;
    return result;

}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction result(*this);
    result /= other;
    return result;
}


Fraction Fraction::operator+(int num) const {
    Fraction result(*this);
    result += num;
    return result;
}

Fraction Fraction::operator-(int num) const {
    Fraction result(*this);
    result -= num;
    return result;
}

Fraction Fraction::operator*(int num) const {
    Fraction result(*this);
    result *= num;
    return result;
}

Fraction Fraction::operator/(int num) const {
    Fraction result(*this);
    result /= num;
    return result;
}

void Fraction::reduce() {
    int div = gcd(numerator_, denominator_);
    numerator_ /= div;
    denominator_ /= div;
}