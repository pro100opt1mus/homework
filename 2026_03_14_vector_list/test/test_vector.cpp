#include <gtest/gtest.h>

#include <iostream>
#include <sstream>
#include <string>

#include "vector.hpp"

using biv::Vector;

static std::string to_string(const Vector<int>& vector) {
    std::stringstream ss;
    std::streambuf* old_buf = std::cout.rdbuf(ss.rdbuf());
    vector.print();
    std::cout.rdbuf(old_buf);
    return ss.str();
}

TEST(Vector, DefaultIsEmpty) {
    Vector<int> vector;

    EXPECT_EQ(vector.get_size(), 0);
    EXPECT_EQ(to_string(vector), "\n");
}

TEST(Vector, PushBackStoresValues) {
    Vector<int> vector;

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);

    EXPECT_EQ(vector.get_size(), 3);
    EXPECT_TRUE(vector.has_item(10));
    EXPECT_TRUE(vector.has_item(20));
    EXPECT_TRUE(vector.has_item(30));
    EXPECT_EQ(to_string(vector), "10 20 30\n");
}

TEST(Vector, InsertWorksInMiddle) {
    Vector<int> vector;

    vector.push_back(1);
    vector.push_back(3);

    EXPECT_TRUE(vector.insert(1, 2));
    EXPECT_EQ(vector.get_size(), 3);
    EXPECT_EQ(to_string(vector), "1 2 3\n");
}

TEST(Vector, InsertWrongPositionReturnsFalse) {
    Vector<int> vector;

    vector.push_back(5);

    EXPECT_FALSE(vector.insert(2, 7));
    EXPECT_EQ(vector.get_size(), 1);
    EXPECT_EQ(to_string(vector), "5\n");
}

TEST(Vector, RemoveFirstRemovesOnlyOneValue) {
    Vector<int> vector;

    vector.push_back(4);
    vector.push_back(7);
    vector.push_back(4);

    EXPECT_TRUE(vector.remove_first(4));
    EXPECT_EQ(vector.get_size(), 2);
    EXPECT_EQ(to_string(vector), "7 4\n");
    EXPECT_FALSE(vector.remove_first(10));
}

TEST(Vector, PushBackWorksAfterResize) {
    Vector<int> vector;

    for (int i = 1; i <= 6; ++i) {
        vector.push_back(i);
    }

    EXPECT_EQ(vector.get_size(), 6);
    EXPECT_EQ(to_string(vector), "1 2 3 4 5 6\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
