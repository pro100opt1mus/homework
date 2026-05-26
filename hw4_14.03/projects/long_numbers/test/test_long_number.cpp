#include <gtest/gtest.h>
#include "long_number.hpp"
#include <sstream>
#include <string>

static std::string to_str(const biv::LongNumber& x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

TEST(LongNumber, DefaultIsNotNegative) {
    biv::LongNumber x;
    EXPECT_FALSE(x.is_negative());
}

TEST(LongNumber, PlusSimple) {
    biv::LongNumber a("123");
    biv::LongNumber b("77");
    EXPECT_EQ(to_str(a + b), "200");
}

TEST(LongNumber, PlusCarry) {
    biv::LongNumber a("999");
    biv::LongNumber b("1");
    EXPECT_EQ(to_str(a + b), "1000");
}

TEST(LongNumber, PlusDifferentLengths) {
    biv::LongNumber a("123456");
    biv::LongNumber b("9");
    EXPECT_EQ(to_str(a + b), "123465");
}

TEST(LongNumber, PlusZero) {
    biv::LongNumber a("0");
    biv::LongNumber b("0");
    EXPECT_EQ(to_str(a + b), "0");
}

TEST(LongNumber, ComparePositive) {
    biv::LongNumber a("10");
    biv::LongNumber b("2");
    EXPECT_TRUE(a > b);
    EXPECT_TRUE(b < a);
}

TEST(LongNumber, CompareNegative) {
    biv::LongNumber a("-10");
    biv::LongNumber b("-2");
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(a < b);
}

TEST(LongNumber, CompareEqual) {
    biv::LongNumber a("123");
    biv::LongNumber b("123");
    EXPECT_FALSE(a > b);
    EXPECT_FALSE(a < b);
    EXPECT_TRUE(a == b);
}

TEST(LongNumber, MinusSimple) {
    biv::LongNumber a("200");
    biv::LongNumber b("77");
    EXPECT_EQ(to_str(a - b), "123");
}

TEST(LongNumber, MultiplySimple) {
    biv::LongNumber a("12");
    biv::LongNumber b("10");
    EXPECT_EQ(to_str(a * b), "120");
}

TEST(LongNumber, DivideSimple) {
    biv::LongNumber a("100");
    biv::LongNumber b("5");
    EXPECT_EQ(to_str(a / b), "20");
}

TEST(LongNumber, ModSimple) {
    biv::LongNumber a("103");
    biv::LongNumber b("10");
    EXPECT_EQ(to_str(a % b), "3");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
