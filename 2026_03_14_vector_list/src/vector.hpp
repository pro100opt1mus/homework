#pragma once

#include <cstddef>

namespace biv {

template <typename T>
class Vector {
private:
    static const std::size_t START_CAPACITY;

    T* arr;
    std::size_t capacity;
    std::size_t size;

    void increase_capacity();

public:
    Vector();
    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;
    ~Vector();

    std::size_t get_size() const noexcept;
    bool has_item(const T& value) const noexcept;
    bool insert(std::size_t position, const T& value);
    void print() const noexcept;
    void push_back(const T& value);
    bool remove_first(const T& value);
};

}
