#include "doubly_linked_list.hpp"

#include <iostream>

using biv::DoublyLinkedList;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() noexcept
    : begin(nullptr), end(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* cur = begin;

    while (cur != nullptr) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }

    begin = nullptr;
    end = nullptr;
}

template <typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
    std::size_t size = 0;
    Node* cur = begin;

    while (cur != nullptr) {
        ++size;
        cur = cur->next;
    }

    return size;
}

template <typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
    Node* cur = begin;

    while (cur != nullptr) {
        if (cur->value == value) {
            return true;
        }

        cur = cur->next;
    }

    return false;
}

template <typename T>
void DoublyLinkedList<T>::print() const noexcept {
    Node* cur = begin;
    bool first = true;

    while (cur != nullptr) {
        if (!first) {
            std::cout << ' ';
        }

        std::cout << cur->value;
        first = false;
        cur = cur->next;
    }

    std::cout << '\n';
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = new Node(value);

    if (begin == nullptr) {
        begin = new_node;
        end = new_node;
        return;
    }

    end->next = new_node;
    new_node->prev = end;
    end = new_node;
}

template <typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
    Node* cur = begin;

    while (cur != nullptr) {
        if (cur->value == value) {
            if (cur->prev != nullptr) {
                cur->prev->next = cur->next;
            } else {
                begin = cur->next;
            }

            if (cur->next != nullptr) {
                cur->next->prev = cur->prev;
            } else {
                end = cur->prev;
            }

            delete cur;
            return true;
        }

        cur = cur->next;
    }

    return false;
}
