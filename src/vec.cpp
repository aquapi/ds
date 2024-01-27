#include <algorithm>
#include <cstddef>
#include <cstdlib>

template <typename T> struct vec {
  T *ptr;
  size_t len, capacity, growth;

  vec() {
    ptr = new T[1];
    capacity = 1;
    len = 0;
    growth = 1;
  }

  ~vec() { delete[] ptr; }

  // Add a value
  void push(T value) {
    if (len == capacity)
      grow(capacity << growth);

    ptr[len] = value;
    ++len;
  }

  // Grow to a specific capacity
  void grow(size_t size) {
    T *newPtr = new T[size];

    // Move all items to new array and grow capacity
    std::copy(ptr, ptr + capacity, newPtr);
    capacity = size;

    // Delete old array and reassign the pointer
    delete[] ptr;
    ptr = newPtr;
  }

  // Remove an item
  void pop() { --len; }

  // Get the pointer of an element at specific offset
  T *operator+(size_t offset) { return ptr + offset; }

  // Get the ref of the element at an index
  T &operator[](size_t offset) { return ptr[offset]; }
};
