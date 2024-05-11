---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/structure/treap.test.cpp
    title: verify/structure/treap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/structure/treap.hpp\"\ntemplate<class T, auto op,\
    \ auto e> class Treap {\npublic:\n    static unsigned long xor128() {\n      \
    \  static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\
    \        unsigned long t = x ^ (x << 11);\n        x = y; y = z; z = w;\n    \
    \    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n    }\n    struct Node {\n\
    \        T val, prod;\n        unsigned priority, size;\n        Node *left, *right;\n\
    \        Node(): val(e()), prod(e()), priority(xor128()), size(1), left(nullptr),\
    \ right(nullptr) {}\n        Node(T val): val(val), prod(val), priority(xor128()),\
    \ size(1), left(nullptr), right(nullptr) {}\n    };\n\n    Treap() : root(nullptr)\
    \ {}\n    Treap(Node *root) : root(root) {}\n    Treap(vector<T> &v) { root =\
    \ build(v); }\n    Treap(int n) { vector<T> v(n, e()); root = build(v);}\n   \
    \ unsigned size() { return size(root); }\n    void insert(int k, T val) { root\
    \ = insert(root, k, val); }\n    void erase(int k) { root = erase(root, k); }\n\
    \    void merge(Treap &t) { root = merge(root, t.root); }\n    pair<Treap, Treap>\
    \ split(int k) { auto [l, r] = split(root, k); return {Treap(l), Treap(r)}; }\n\
    \    T get(int k) { return get(root, k)->val; }\n    void set(int k, T val) {\
    \ erase(k); insert(k, val); }\n    T prod(int l, int r) {\n        auto [left,\
    \ rest] = split(root, l);\n        auto [mid, right] = split(rest, r - l);\n \
    \       T res = prod(mid);\n        root = merge(merge(left, mid), right);\n \
    \       return res;\n    }\nprivate:\n    Node *root;\n    unsigned size(Node\
    \ *node) { return node ? node->size : 0; }\n    T prod(Node *node) { return node\
    \ ? node->prod : e(); }\n    Node *update(Node *node) {\n        node->size =\
    \ size(node->left) + size(node->right) + 1;\n        node->prod = op(op(prod(node->left),\
    \ node->val), prod(node->right));\n        return node;\n    }\n    Node *build(vector<T>\
    \ &v) {\n        Node *node = nullptr;\n        for (auto val: v) node = merge(node,\
    \ new Node(val));\n        return node;\n    }\n    Node *merge(Node *left, Node\
    \ *right) {\n        if (!left || !right) return left ? left : right;\n      \
    \  if (left->priority > right->priority) {\n            left->right = merge(left->right,\
    \ right);\n            return update(left);\n        } else {\n            right->left\
    \ = merge(left, right->left);\n            return update(right);\n        }\n\
    \    }\n    pair<Node*, Node*> split(Node *node, int k) {\n        if (!node)\
    \ return {nullptr, nullptr};\n        if (k <= (int)size(node->left)) {\n    \
    \        auto [left, right] = split(node->left, k);\n            node->left =\
    \ right;\n            return {left, update(node)};\n        } else {\n       \
    \     auto [left, right] = split(node->right, k - size(node->left) - 1);\n   \
    \         node->right = left;\n            return {update(node), right};\n   \
    \     }\n    }\n    Node *insert(Node *node, int k, T val) {\n        auto [left,\
    \ right] = split(node, k);\n        return merge(merge(left, new Node(val)), right);\n\
    \    }\n    Node *erase(Node *node, int k) {\n        auto [left, right] = split(node,\
    \ k);\n        auto [one, right_others] = split(right, 1);\n        delete one;\n\
    \        return merge(left, right_others);\n    }\n    Node *get(Node *node, int\
    \ k) {\n        if (k < size(node->left)) return get(node->left, k);\n       \
    \ if (k == size(node->left)) return node;\n        return get(node->right, k -\
    \ size(node->left) - 1);\n    }\n};\n"
  code: "template<class T, auto op, auto e> class Treap {\npublic:\n    static unsigned\
    \ long xor128() {\n        static unsigned long x = 123456789, y = 362436069,\
    \ z = 521288629, w = 88675123;\n        unsigned long t = x ^ (x << 11);\n   \
    \     x = y; y = z; z = w;\n        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n\
    \    }\n    struct Node {\n        T val, prod;\n        unsigned priority, size;\n\
    \        Node *left, *right;\n        Node(): val(e()), prod(e()), priority(xor128()),\
    \ size(1), left(nullptr), right(nullptr) {}\n        Node(T val): val(val), prod(val),\
    \ priority(xor128()), size(1), left(nullptr), right(nullptr) {}\n    };\n\n  \
    \  Treap() : root(nullptr) {}\n    Treap(Node *root) : root(root) {}\n    Treap(vector<T>\
    \ &v) { root = build(v); }\n    Treap(int n) { vector<T> v(n, e()); root = build(v);}\n\
    \    unsigned size() { return size(root); }\n    void insert(int k, T val) { root\
    \ = insert(root, k, val); }\n    void erase(int k) { root = erase(root, k); }\n\
    \    void merge(Treap &t) { root = merge(root, t.root); }\n    pair<Treap, Treap>\
    \ split(int k) { auto [l, r] = split(root, k); return {Treap(l), Treap(r)}; }\n\
    \    T get(int k) { return get(root, k)->val; }\n    void set(int k, T val) {\
    \ erase(k); insert(k, val); }\n    T prod(int l, int r) {\n        auto [left,\
    \ rest] = split(root, l);\n        auto [mid, right] = split(rest, r - l);\n \
    \       T res = prod(mid);\n        root = merge(merge(left, mid), right);\n \
    \       return res;\n    }\nprivate:\n    Node *root;\n    unsigned size(Node\
    \ *node) { return node ? node->size : 0; }\n    T prod(Node *node) { return node\
    \ ? node->prod : e(); }\n    Node *update(Node *node) {\n        node->size =\
    \ size(node->left) + size(node->right) + 1;\n        node->prod = op(op(prod(node->left),\
    \ node->val), prod(node->right));\n        return node;\n    }\n    Node *build(vector<T>\
    \ &v) {\n        Node *node = nullptr;\n        for (auto val: v) node = merge(node,\
    \ new Node(val));\n        return node;\n    }\n    Node *merge(Node *left, Node\
    \ *right) {\n        if (!left || !right) return left ? left : right;\n      \
    \  if (left->priority > right->priority) {\n            left->right = merge(left->right,\
    \ right);\n            return update(left);\n        } else {\n            right->left\
    \ = merge(left, right->left);\n            return update(right);\n        }\n\
    \    }\n    pair<Node*, Node*> split(Node *node, int k) {\n        if (!node)\
    \ return {nullptr, nullptr};\n        if (k <= (int)size(node->left)) {\n    \
    \        auto [left, right] = split(node->left, k);\n            node->left =\
    \ right;\n            return {left, update(node)};\n        } else {\n       \
    \     auto [left, right] = split(node->right, k - size(node->left) - 1);\n   \
    \         node->right = left;\n            return {update(node), right};\n   \
    \     }\n    }\n    Node *insert(Node *node, int k, T val) {\n        auto [left,\
    \ right] = split(node, k);\n        return merge(merge(left, new Node(val)), right);\n\
    \    }\n    Node *erase(Node *node, int k) {\n        auto [left, right] = split(node,\
    \ k);\n        auto [one, right_others] = split(right, 1);\n        delete one;\n\
    \        return merge(left, right_others);\n    }\n    Node *get(Node *node, int\
    \ k) {\n        if (k < size(node->left)) return get(node->left, k);\n       \
    \ if (k == size(node->left)) return node;\n        return get(node->right, k -\
    \ size(node->left) - 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cplib/structure/treap.hpp
  requiredBy: []
  timestamp: '2024-05-11 18:50:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/structure/treap.test.cpp
documentation_of: cplib/structure/treap.hpp
layout: document
redirect_from:
- /library/cplib/structure/treap.hpp
- /library/cplib/structure/treap.hpp.html
title: cplib/structure/treap.hpp
---
