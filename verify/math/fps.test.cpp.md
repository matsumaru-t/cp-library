---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cplib/math/fps.hpp
    title: cplib/math/fps.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"verify/math/fps.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#line 1 \"cplib/template.hpp\"\n#include <bits/stdc++.h>\n#include <atcoder/all>\n\
    \nusing namespace std;\nusing namespace atcoder;\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\ntypedef vector<int> vi;\ntypedef vector<ll> vll;\ntypedef vector<ld>\
    \ vld;\ntypedef vector<vi> vvi;\ntypedef vector<vll> vvll;\n\ntemplate <class\
    \ T> using Vec = vector<T>;\ntemplate <class T> using Graph = Vec<Vec<T>>;\n\n\
    #define _overload3(_1,_2,_3,name,...) name\n#define _rep(i,n) repi(i,0,n)\n#define\
    \ repi(i,a,b) for(int i=int(a);i<int(b);++i)\n#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)\n\
    #define _rrep(i,n) rrepi(i,n-1,-1)\n#define rrepi(i,a,b) for(int i=int(a);i>int(b);--i)\n\
    #define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep)(__VA_ARGS__)\n\n#define\
    \ all(x) (x).begin(),(x).end()\n#define SORT(x) sort(all(x))\n#define REVERSE(x)\
    \ reverse(all(x))\n\ntemplate<class T>bool chmax(T &a, const T &b) { if (a<b)\
    \ { a=b; return 1; } return 0; }\ntemplate<class T>bool chmin(T &a, const T &b)\
    \ { if (b<a) { a=b; return 1; } return 0; }\n\nostream& operator<<(ostream& os,\
    \ const modint998244353& a) { return os << a.val(); }\nostream& operator<<(ostream&\
    \ os, const modint1000000007& a) { return os << a.val(); }\n#line 1 \"cplib/math/fps.hpp\"\
    \ntemplate<typename mint>\nstruct FormalPowerSeries: vector<mint> {\n    using\
    \ fps = FormalPowerSeries;\n    using vector<mint>::vector;\n\n    fps& operator+=(const\
    \ fps& g) {\n        if (this->size() < g.size()) this->resize(g.size());\n  \
    \      for (int i = 0; i < g.size(); i++) (*this)[i] += g[i];\n        return\
    \ *this;\n    }\n    fps& operator+=(const mint& a) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += a;\n        return *this;\n    }\n \
    \   fps& operator-=(const fps& g) {\n        if (this->size() < g.size()) this->resize(g.size());\n\
    \        for (int i = 0; i < g.size(); i++) (*this)[i] -= g[i];\n        return\
    \ *this;\n    }\n    fps& operator-=(const mint& a) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= a;\n        return *this;\n    }\n \
    \   fps& operator*=(const fps& g) {\n        vector<mint> h = convolution(*this,\
    \ g);\n        return *this = fps(h.begin(), h.end());\n    }\n    fps& operator*=(const\
    \ mint& a) {\n        for (int i = 0; i < this->size(); i++) (*this)[i] *= a;\n\
    \        return *this;\n    }\n\n    fps operator+(const fps& g) const { return\
    \ fps(*this) += g; }\n    fps operator+(const mint& a) const { return fps(*this)\
    \ += a; }\n    fps operator-(const fps& g) const { return fps(*this) -= g; }\n\
    \    fps operator-(const mint& a) const { return fps(*this) -= a; }\n    fps operator-()\
    \ const { return fps(*this) *= -1; }\n    fps operator*(const fps& g) const {\
    \ return fps(*this) *= g; }\n    fps operator*(const mint& a) const { return fps(*this)\
    \ *= a; }\n\n    fps inv(int n) {\n        assert((*this)[0] != 0);\n        fps\
    \ res = {(*this)[0].inv()};\n        for (int d = 1; d < n; d <<= 1) {\n     \
    \       res = res * 2 - *this * res * res;\n            res.resize(d << 1);\n\
    \        }\n        return res.resize(n), res;\n    }\n    fps& operator/=(const\
    \ fps& g) {\n        assert(!g.empty() && g[0] != 0);\n        return *this *=\
    \ g.inv(this->size());\n    }\n    fps& operator/=(const mint& a) {\n        assert(a\
    \ != 0);\n        return *this *= a.inv();\n    }\n};\n#line 5 \"verify/math/fps.test.cpp\"\
    \n\nint main() {\n    using mint = modint998244353;\n    using fps = FormalPowerSeries<mint>;\n\
    \n    int N;\n    cin >> N;\n    vi A(N);\n    rep(i, N) cin >> A[i];\n\n    fps\
    \ f(A.begin(), A.end());\n    f = f.inv(N);\n\n    for (auto &x: f) cout << x\
    \ << \" \";\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#include \"../../cplib/template.hpp\"\n#include \"../../cplib/math/fps.hpp\"\
    \n\nint main() {\n    using mint = modint998244353;\n    using fps = FormalPowerSeries<mint>;\n\
    \n    int N;\n    cin >> N;\n    vi A(N);\n    rep(i, N) cin >> A[i];\n\n    fps\
    \ f(A.begin(), A.end());\n    f = f.inv(N);\n\n    for (auto &x: f) cout << x\
    \ << \" \";\n    cout << endl;\n}"
  dependsOn:
  - cplib/template.hpp
  - cplib/math/fps.hpp
  isVerificationFile: true
  path: verify/math/fps.test.cpp
  requiredBy: []
  timestamp: '2024-05-05 15:00:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/fps.test.cpp
layout: document
redirect_from:
- /verify/verify/math/fps.test.cpp
- /verify/verify/math/fps.test.cpp.html
title: verify/math/fps.test.cpp
---
