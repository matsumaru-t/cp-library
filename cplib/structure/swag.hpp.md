---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/structure/swag.hpp\"\ntemplate<class S, auto op, auto\
    \ e>\nclass swag {\n    public:\n        swag() { topfold.push(e()); bottomfold.push(e());\
    \ }\n        void push_back(S x) { _pushbottom(x); }\n        void push_front(S\
    \ x) { _pushtop(x); }\n        S fold() { return op(topfold.top(), bottomfold.top());\
    \ }\n        S pop_front() {\n            if (top.empty()) {\n               \
    \ vector<S> st;\n                while (!bottom.empty()) st.push_back(_popbottom());\n\
    \                int n = st.size();\n                for (int i = n/2; i < n;\
    \ i++) _pushtop(st[i]);\n                for (int i = n/2-1; i >= 0; i--) _pushbottom(st[i]);\n\
    \            }\n            if (top.empty()) return e();\n            else return\
    \ _poptop();\n        }\n        S pop_back() {\n            if (bottom.empty())\
    \ {\n                vector<S> st;\n                while (!top.empty()) st.push_back(_poptop());\n\
    \                int n = st.size();\n                for (int i = n/2-1; i >=\
    \ 0; i--) _pushtop(st[i]);\n                for (int i = n/2; i < n; i++) _pushbottom(st[i]);\n\
    \            }\n            if (bottom.empty()) return e();\n            else\
    \ return _popbottom();\n        }\n\n    private:\n        stack<S> top, bottom,\
    \ topfold, bottomfold;\n        void _pushbottom(S x) {\n            bottom.push(x);\n\
    \            bottomfold.push(op(bottomfold.top(), x));\n        }\n        S _popbottom()\
    \ {\n            bottomfold.pop();\n            S x = bottom.top();\n        \
    \    bottom.pop();\n            return x;\n        }\n        void _pushtop(S\
    \ x) {\n            top.push(x);\n            topfold.push(op(x, topfold.top()));\n\
    \        }\n        S _poptop() {\n            topfold.pop();\n            S x\
    \ = top.top();\n            top.pop();\n            return x;\n        }\n};\n"
  code: "template<class S, auto op, auto e>\nclass swag {\n    public:\n        swag()\
    \ { topfold.push(e()); bottomfold.push(e()); }\n        void push_back(S x) {\
    \ _pushbottom(x); }\n        void push_front(S x) { _pushtop(x); }\n        S\
    \ fold() { return op(topfold.top(), bottomfold.top()); }\n        S pop_front()\
    \ {\n            if (top.empty()) {\n                vector<S> st;\n         \
    \       while (!bottom.empty()) st.push_back(_popbottom());\n                int\
    \ n = st.size();\n                for (int i = n/2; i < n; i++) _pushtop(st[i]);\n\
    \                for (int i = n/2-1; i >= 0; i--) _pushbottom(st[i]);\n      \
    \      }\n            if (top.empty()) return e();\n            else return _poptop();\n\
    \        }\n        S pop_back() {\n            if (bottom.empty()) {\n      \
    \          vector<S> st;\n                while (!top.empty()) st.push_back(_poptop());\n\
    \                int n = st.size();\n                for (int i = n/2-1; i >=\
    \ 0; i--) _pushtop(st[i]);\n                for (int i = n/2; i < n; i++) _pushbottom(st[i]);\n\
    \            }\n            if (bottom.empty()) return e();\n            else\
    \ return _popbottom();\n        }\n\n    private:\n        stack<S> top, bottom,\
    \ topfold, bottomfold;\n        void _pushbottom(S x) {\n            bottom.push(x);\n\
    \            bottomfold.push(op(bottomfold.top(), x));\n        }\n        S _popbottom()\
    \ {\n            bottomfold.pop();\n            S x = bottom.top();\n        \
    \    bottom.pop();\n            return x;\n        }\n        void _pushtop(S\
    \ x) {\n            top.push(x);\n            topfold.push(op(x, topfold.top()));\n\
    \        }\n        S _poptop() {\n            topfold.pop();\n            S x\
    \ = top.top();\n            top.pop();\n            return x;\n        }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cplib/structure/swag.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/structure/swag.hpp
layout: document
redirect_from:
- /library/cplib/structure/swag.hpp
- /library/cplib/structure/swag.hpp.html
title: cplib/structure/swag.hpp
---
