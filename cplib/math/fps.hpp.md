---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/fps.test.cpp
    title: verify/math/fps.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/math/fps.hpp\"\ntemplate<typename mint>\nstruct FormalPowerSeries:\
    \ vector<mint> {\n    using fps = FormalPowerSeries;\n    using vector<mint>::vector;\n\
    \n    fps& operator+=(const fps& g) {\n        if (this->size() < g.size()) this->resize(g.size());\n\
    \        for (int i = 0; i < g.size(); i++) (*this)[i] += g[i];\n        return\
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
    \ != 0);\n        return *this *= a.inv();\n    }\n};\n"
  code: "template<typename mint>\nstruct FormalPowerSeries: vector<mint> {\n    using\
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
    \ != 0);\n        return *this *= a.inv();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/fps.hpp
  requiredBy: []
  timestamp: '2024-05-05 15:00:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/fps.test.cpp
documentation_of: cplib/math/fps.hpp
layout: document
redirect_from:
- /library/cplib/math/fps.hpp
- /library/cplib/math/fps.hpp.html
title: cplib/math/fps.hpp
---
