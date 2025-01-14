

#include <iostream>
#include <exception>

#include <iostream>
#include <exception>

template <class T>
class my_unique_ptr {
private:
    T* ptr = nullptr;

public:
    // Default constructor
    my_unique_ptr() : ptr(nullptr) {}

    // Overloaded constructor
    explicit my_unique_ptr(T* ptr) : ptr(ptr) {}

    // Deleted copy constructor
    my_unique_ptr(const my_unique_ptr& obj) = delete;

    // Move constructor
    my_unique_ptr(my_unique_ptr&& obj) noexcept {
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }

    // Deleted copy assignment operator
    my_unique_ptr& operator=(const my_unique_ptr& obj) = delete;

    // Move assignment operator
    my_unique_ptr& operator=(my_unique_ptr&& obj) noexcept {
        if (this != &obj) {
            __cleanup__();
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }

    // Destructor
    ~my_unique_ptr() {
        __cleanup__();
    }

    // Access underlying pointer
    T* operator->() const {
        return ptr;
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

private:
    void __cleanup__() {
        if (ptr != nullptr) {
            delete ptr;
            ptr = nullptr;
        }
    }
};

// Specialization for arrays
template <class T>
class my_unique_ptr<T[]> {
private:
    T* ptr = nullptr;

public:
    // Default constructor
    my_unique_ptr() : ptr(nullptr) {}

    // Overloaded constructor
    explicit my_unique_ptr(T* ptr) : ptr(ptr) {}

    // Deleted copy constructor
    my_unique_ptr(const my_unique_ptr& obj) = delete;

    // Move constructor
    my_unique_ptr(my_unique_ptr&& obj) noexcept {
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }

    // Deleted copy assignment operator
    my_unique_ptr& operator=(const my_unique_ptr& obj) = delete;

    // Move assignment operator
    my_unique_ptr& operator=(my_unique_ptr&& obj) noexcept {
        if (this != &obj) {
            __cleanup__();
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }

    // Destructor
    ~my_unique_ptr() {
        __cleanup__();
    }

    // Access array elements
    T& operator[](std::size_t index) const {
        if (index < 0) {
            throw std::out_of_range("Index cannot be negative");
        }
        return ptr[index];
    }

private:
    void __cleanup__() {
        if (ptr != nullptr) {
            delete[] ptr;
            ptr = nullptr;
        }
    }
};
