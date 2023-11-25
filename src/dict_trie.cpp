// Store lowercase characters
#include <iostream>
#include <string>

#define nil nullptr

struct Node {
  Node *child[26];
  bool isLeaf = false;

  Node() {
#pragma GCC unroll 26
    for (size_t i = 0; i < 26; ++i)
      child[i] = nil;
  }

  ~Node() {
#pragma GCC unroll 26
    for (size_t i = 0; i < 26; ++i)
      delete child[i];
  }
};

struct Trie {
  Node *root = new Node;

  void put(const std::string &s) noexcept {
    auto ptr = root;

    for (int ch : s) {
      ch -= 'a';

      if (ptr->child[ch] == nil)
        ptr->child[ch] = new Node;

      ptr = ptr->child[ch];
    }

    ptr->isLeaf = true;
  }

  bool find(const std::string &s) const noexcept {
    auto ptr = root;

    for (int ch : s) {
      ptr = ptr->child[ch - 'a'];

      if (ptr == nil)
        return false;
    }

    return ptr->isLeaf;
  }
};

#undef nil

int main() {
  Trie tree;

  tree.put("abc");
  tree.put("bac");
  tree.put("aac");
  tree.put("abb");

  std::cout << tree.find("abc") << ' ' << tree.find("bac") << ' '
            << tree.find("aac") << ' ' << tree.find("abb") << ' '
            << !tree.find("cab");
}
