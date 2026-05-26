#pragma once

#include <cstddef>

namespace biv {

template <typename T>
class DoublyLinkedList {
private:
    class Node {
    public:
        T value;
        Node* prev;
        Node* next;

        Node(const T& value)
            : value(value), prev(nullptr), next(nullptr) {}

        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
    };

    Node* begin;
    Node* end;

public:
    DoublyLinkedList() noexcept;
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
    ~DoublyLinkedList();

    std::size_t get_size() const noexcept;
    bool has_item(const T& value) const noexcept;
    void print() const noexcept;
    void push_back(const T& value);
    bool remove_first(const T& value) noexcept;
};

}
