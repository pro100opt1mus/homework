#include <gtest/gtest.h>

#include <iostream>
#include <sstream>
#include <string>

#include "doubly_linked_list.hpp"

using biv::DoublyLinkedList;

static std::string to_string(const DoublyLinkedList<int>& list) {
    std::stringstream ss;
    std::streambuf* old_buf = std::cout.rdbuf(ss.rdbuf());
    list.print();
    std::cout.rdbuf(old_buf);
    return ss.str();
}

TEST(DoublyLinkedList, DefaultIsEmpty) {
    DoublyLinkedList<int> list;

    EXPECT_EQ(list.get_size(), 0);
    EXPECT_EQ(to_string(list), "\n");
}

TEST(DoublyLinkedList, PushBackStoresOrder) {
    DoublyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.get_size(), 3);
    EXPECT_EQ(to_string(list), "10 20 30\n");
}

TEST(DoublyLinkedList, HasItemFindsValue) {
    DoublyLinkedList<int> list;

    list.push_back(5);
    list.push_back(8);

    EXPECT_TRUE(list.has_item(5));
    EXPECT_TRUE(list.has_item(8));
    EXPECT_FALSE(list.has_item(10));
}

TEST(DoublyLinkedList, RemoveFirstWorksInMiddle) {
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_TRUE(list.remove_first(2));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_EQ(to_string(list), "1 3\n");
}

TEST(DoublyLinkedList, RemoveFirstWorksForHeadAndTail) {
    DoublyLinkedList<int> list;

    list.push_back(4);
    list.push_back(5);
    list.push_back(6);

    EXPECT_TRUE(list.remove_first(4));
    EXPECT_EQ(to_string(list), "5 6\n");
    EXPECT_TRUE(list.remove_first(6));
    EXPECT_EQ(to_string(list), "5\n");
    EXPECT_FALSE(list.remove_first(10));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
