#pragma once

class Fraction {
   int numerator_, denominator_;

   public:
    Fraction(int counter = 0, int denominator = 1);
    Fraction(int num);

    int numerator() const;
    int denominator() const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;

    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    Fraction& operator+=(int num);
    Fraction& operator-=(int num);
    Fraction& operator*=(int num);
    Fraction& operator/=(int num);

    Fraction operator-() const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    Fraction operator+(int num) const;
    Fraction operator-(int num) const;
    Fraction operator*(int num) const;
    Fraction operator/(int num) const;

    template <typename FloatType>
    FloatType approximate() const {
        return numerator_ / static_cast<FloatType>(denominator_);
    }

   private:
    void reduce();
};