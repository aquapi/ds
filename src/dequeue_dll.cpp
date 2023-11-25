#include <iostream>

#define nil nullptr

// Doubly linked list node
struct Node {
  int data;
  Node *prev, *next;

  Node(int data) : data(data){};
};

struct Dequeue {
  Node *head = nil, *tail = nil;

  // Push front
  void push(int item) {
    auto nw = new Node(item);

    // Nothing has been added
    if (head == nil)
      head = tail = nw;
    else {
      // Head is the next node of the new node
      nw->next = head;
      head = head->prev = nw;
    }
  }

  // Push back
  void append(int item) {
    auto nw = new Node(item);

    // Nothing has been added
    if (tail == nil)
      head = tail = nw;
    else {
      // Tail is the prev node of the new node
      nw->prev = tail;
      tail = tail->next = nw;
    }
  }

  // Pop front
  void shift() noexcept {
    // Ignore if empty
    if (head == nil)
      return;

    auto target = head;

    // Move head to the next pointer
    head = head->next;

    // Only 1 element exists
    if (head == nil)
      tail = nil;

    // Unset the previous node
    else
      head->prev = nil;

    // Delete target pointer
    delete target;
  }

  // Pop back
  void pop() noexcept {
    // Ignore if empty
    if (tail == nil)
      return;

    auto target = tail;

    // Move tail to the previous pointer
    tail = tail->prev;

    // Only 1 element exists
    if (tail == nil)
      head = nil;

    // Unset the next node
    else
      tail->next = nil;

    // Delete target pointer
    delete target;
  }

  int &front() const { return head->data; }
  int &back() const { return tail->data; }
};

std::ostream &operator<<(std::ostream &c, const Dequeue &d) {
  auto nw = d.head;

  while (nw != nullptr) {
    c << nw->data << ' ';
    nw = nw->next;
  }

  return c;
}

#undef nil

// Testing
int main() {
  Dequeue d;

  d.push(1);
  d.append(2);

  std::cout << d << '\n';

  d.push(3);
  d.pop();

  std::cout << d << '\n';

  d.append(4);
  d.shift();

  std::cout << d << '\n';
}
