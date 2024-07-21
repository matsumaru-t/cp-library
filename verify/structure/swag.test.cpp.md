---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"verify/structure/swag.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc298/tasks/abc298_d\"\
    \n\n#line 1 \"cplib/template.hpp\"\n#include <bits/stdc++.h>\n#include <atcoder/all>\n\
    \nusing namespace std;\nusing namespace atcoder;\n\ntypedef long long ll;\ntypedef\
    \ long double ld;\ntypedef pair<int, int> pii;\ntypedef pair<ll, ll> pll;\ntypedef\
    \ vector<int> vi;\ntypedef vector<ll> vll;\ntypedef vector<ld> vld;\ntypedef vector<vi>\
    \ vvi;\ntypedef vector<vll> vvll;\ntypedef vector<string> vs;\n\n#define _overload3(_1,_2,_3,name,...)\
    \ name\n#define _rep(i,n) repi(i,0,n)\n#define repi(i,a,b) for(int i=int(a);i<int(b);++i)\n\
    #define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)\n#define _rrep(i,n)\
    \ rrepi(i,n-1,-1)\n#define rrepi(i,a,b) for(int i=int(a);i>int(b);--i)\n#define\
    \ rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep)(__VA_ARGS__)\n\n#define all(x)\
    \ (x).begin(),(x).end()\n#define SORT(x) sort(all(x))\n#define REVERSE(x) reverse(all(x))\n\
    \n#define dump(x) cerr << #x << \" = \" << (x) << endl\n#define print(x) cout\
    \ << (x) << endl\n#define yes(f) cout << ((f) ? \"Yes\" : \"No\") << endl\n\n\
    #define ge(v, x) (int)(lower_bound(all(v), x) - v.begin())\n#define gt(v, x) (int)(upper_bound(all(v),\
    \ x) - v.begin())\n#define le(v, x) (int)(upper_bound(all(v), x) - v.begin())-1\n\
    #define lt(v, x) (int)(lower_bound(all(v), x) - v.begin())-1\n\ntemplate<class\
    \ T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }\ntemplate<class\
    \ T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }\n\n\
    ostream& operator<<(ostream& os, const modint998244353& a) { return os << a.val();\
    \ }\nostream& operator<<(ostream& os, const modint1000000007& a) { return os <<\
    \ a.val(); }\n\ntemplate<class T> istream& operator>>(istream& is, vector<T>&\
    \ vec) { for (T& x : vec) is >> x; return is; }\ntemplate<class T> ostream& operator<<(ostream&\
    \ os, const vector<T>& vec) { for (const T& x : vec) os << x << ' '; return os;\
    \ }\n#line 1 \"cplib/structure/swag.hpp\"\ntemplate<class S, auto op, auto e>\n\
    class swag {\n    public:\n        swag() { topfold.push(e()); bottomfold.push(e());\
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
    \ = top.top();\n            top.pop();\n            return x;\n        }\n};\n\
    #line 5 \"verify/structure/swag.test.cpp\"\n\nusing S = pair<modint998244353,\
    \ modint998244353>;\nauto op = [](S a, S b) { return S(a.first*b.second+b.first,\
    \ a.second*b.second); };\nauto e = []() { return S(0, 1); };\n\nint main() {\n\
    \    int Q;\n    cin >> Q;\n\n    swag<S, op, e> sg;\n    sg.push_back(S(1, 1));\n\
    \n    while (Q--) {\n        int t;\n        cin >> t;\n        if (t == 1) {\n\
    \            int x;\n            cin >> x;\n            sg.push_back(S(x, 10));\n\
    \        } else if (t == 2) {\n            sg.pop_front();\n        } else {\n\
    \            print(sg.fold().first);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc298/tasks/abc298_d\"\n\n\
    #include \"../../cplib/template.hpp\"\n#include \"../../cplib/structure/swag.hpp\"\
    \n\nusing S = pair<modint998244353, modint998244353>;\nauto op = [](S a, S b)\
    \ { return S(a.first*b.second+b.first, a.second*b.second); };\nauto e = []() {\
    \ return S(0, 1); };\n\nint main() {\n    int Q;\n    cin >> Q;\n\n    swag<S,\
    \ op, e> sg;\n    sg.push_back(S(1, 1));\n\n    while (Q--) {\n        int t;\n\
    \        cin >> t;\n        if (t == 1) {\n            int x;\n            cin\
    \ >> x;\n            sg.push_back(S(x, 10));\n        } else if (t == 2) {\n \
    \           sg.pop_front();\n        } else {\n            print(sg.fold().first);\n\
    \        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/structure/swag.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/structure/swag.test.cpp
layout: document
redirect_from:
- /verify/verify/structure/swag.test.cpp
- /verify/verify/structure/swag.test.cpp.html
title: verify/structure/swag.test.cpp
---
