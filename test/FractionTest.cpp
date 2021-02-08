#include <gtest/gtest.h>

#include <Fraction.h>

TEST(FractionTests, Arithmetic) {
    Fraction frac(1, 2);
    Fraction result;
    result = frac + Fraction(1, 3);
    EXPECT_EQ(result.numerator(), 5);
    EXPECT_EQ(result.denominator(), 6);

    result = frac - Fraction(1, 3);
    EXPECT_EQ(result.numerator(), 1);
    EXPECT_EQ(result.denominator(), 6);

    result = frac * Fraction(1, 3);
    EXPECT_EQ(result.numerator(), 1);
    EXPECT_EQ(result.denominator(), 6);

    result = frac / Fraction(1, 3);
    EXPECT_EQ(result.numerator(), 3);
    EXPECT_EQ(result.denominator(), 2);

    result = - frac;
    EXPECT_EQ(result.numerator(), -1);
    EXPECT_EQ(result.denominator(), 2);

    result = - result;
    EXPECT_EQ(result.numerator(), 1);
    EXPECT_EQ(result.denominator(), 2);

    result = - Fraction(1, -2);
    EXPECT_EQ(result.numerator(), -1);
    EXPECT_EQ(result.denominator(), -2);
}

TEST(FractionTests, Comparision) {
    Fraction frac1(1, 2);
    Fraction frac2(2, 4);
    EXPECT_TRUE(frac1 == frac2);
    EXPECT_TRUE(frac1 <= frac2);
    EXPECT_TRUE(frac2 <= frac1);
    EXPECT_TRUE(frac1 >= frac2);
    EXPECT_TRUE(frac2 >= frac1);

    frac2 = Fraction(3, 4);
    EXPECT_TRUE(frac1 < frac2);
    EXPECT_FALSE(frac2 < frac1);

    EXPECT_TRUE(frac1 <= frac2);
    EXPECT_FALSE(frac2 <= frac1);

    EXPECT_TRUE(frac2 > frac1);
    EXPECT_FALSE(frac1 > frac2);

    EXPECT_TRUE(frac2 >= frac1);
    EXPECT_FALSE(frac1 >= frac2);
}

TEST(FractionTests, Reduce) {
    Fraction result = Fraction(-1000, 500).reduced();
    EXPECT_EQ(result.numerator(), -2);
    EXPECT_EQ(result.denominator(), 1);

    result.reduce();
    EXPECT_EQ(result.numerator(), -2);
    EXPECT_EQ(result.denominator(), 1);

    result = Fraction(7, 28).reduced();
    EXPECT_EQ(result.numerator(), 1);
    EXPECT_EQ(result.denominator(), 4);

    result.reduce();
    EXPECT_EQ(result.numerator(), 1);
    EXPECT_EQ(result.denominator(), 4);
}

TEST(FractionTests, Approximate) {
    double approx = Fraction(1, 2).approximate<double>();
    EXPECT_EQ(approx, 0.5);

    approx = Fraction(200, 1000).approximate<double>();
    EXPECT_EQ(approx, 0.2);
}

TEST(FractionTests, EdgeCases) {
    EXPECT_THROW(Fraction(1, 0), std::runtime_error);
}