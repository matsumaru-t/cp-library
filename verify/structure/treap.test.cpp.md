---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cplib/structure/treap.hpp
    title: cplib/structure/treap.hpp
  - icon: ':heavy_check_mark:'
    path: cplib/template.hpp
    title: cplib/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/structure/treap.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 1 \"cplib/template.hpp\"\n#include <bits/stdc++.h>\n#include <atcoder/all>\n\
    \nusing namespace std;\nusing namespace atcoder;\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\ntypedef vector<int> vi;\ntypedef vector<ll> vll;\ntypedef vector<ld>\
    \ vld;\ntypedef vector<vi> vvi;\ntypedef vector<vll> vvll;\n\n#define _overload3(_1,_2,_3,name,...)\
    \ name\n#define _rep(i,n) repi(i,0,n)\n#define repi(i,a,b) for(int i=int(a);i<int(b);++i)\n\
    #define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)\n#define _rrep(i,n)\
    \ rrepi(i,n-1,-1)\n#define rrepi(i,a,b) for(int i=int(a);i>int(b);--i)\n#define\
    \ rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep)(__VA_ARGS__)\n\n#define all(x)\
    \ (x).begin(),(x).end()\n#define SORT(x) sort(all(x))\n#define REVERSE(x) reverse(all(x))\n\
    \ntemplate<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; }\
    \ return 0; }\ntemplate<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b;\
    \ return 1; } return 0; }\n\nostream& operator<<(ostream& os, const modint998244353&\
    \ a) { return os << a.val(); }\nostream& operator<<(ostream& os, const modint1000000007&\
    \ a) { return os << a.val(); }\n\ntemplate<class T> istream& operator>>(istream&\
    \ is, vector<T>& vec) { for (T& x : vec) is >> x; return is; }\ntemplate<class\
    \ T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (const T& x\
    \ : vec) os << x << ' '; return os; }\n#line 1 \"cplib/structure/treap.hpp\"\n\
    template<class T, auto op, auto e> class Treap {\npublic:\n    static unsigned\
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
    \ size(node->left) - 1);\n    }\n};\n#line 5 \"verify/structure/treap.test.cpp\"\
    \n\nint op(int a, int b) { return min(a, b); }\nint e() { return 1000000005; }\n\
    \nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n   \
    \ cin >> a;\n\n    Treap<int, op, e> t(a);\n    rep(i, Q) {\n        int l, r;\n\
    \        cin >> l >> r;\n        cout << t.prod(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../cplib/template.hpp\"\n#include \"../../cplib/structure/treap.hpp\"\n\
    \nint op(int a, int b) { return min(a, b); }\nint e() { return 1000000005; }\n\
    \nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n   \
    \ cin >> a;\n\n    Treap<int, op, e> t(a);\n    rep(i, Q) {\n        int l, r;\n\
    \        cin >> l >> r;\n        cout << t.prod(l, r) << endl;\n    }\n}\n"
  dependsOn:
  - cplib/template.hpp
  - cplib/structure/treap.hpp
  isVerificationFile: true
  path: verify/structure/treap.test.cpp
  requiredBy: []
  timestamp: '2024-05-11 18:50:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/structure/treap.test.cpp
layout: document
redirect_from:
- /verify/verify/structure/treap.test.cpp
- /verify/verify/structure/treap.test.cpp.html
title: verify/structure/treap.test.cpp
---