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
  bundledCode: '#line 1 "cplib/template.hpp"

    #include <bits/stdc++.h>

    #include <atcoder/all>


    using namespace std;

    using namespace atcoder;


    typedef long long ll;

    typedef long double ld;

    typedef vector<int> vi;

    typedef vector<ll> vll;

    typedef vector<ld> vld;

    typedef vector<vi> vvi;

    typedef vector<vll> vvll;


    template <class T> using Vec = vector<T>;

    template <class T> using Graph = Vec<Vec<T>>;


    #define _overload3(_1,_2,_3,name,...) name

    #define _rep(i,n) repi(i,0,n)

    #define repi(i,a,b) for(int i=int(a);i<int(b);++i)

    #define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

    #define _rrep(i,n) rrepi(i,n-1,-1)

    #define rrepi(i,a,b) for(int i=int(a);i>int(b);--i)

    #define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep)(__VA_ARGS__)


    #define all(x) (x).begin(),(x).end()

    #define SORT(x) sort(all(x))

    #define REVERSE(x) reverse(all(x))


    template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return
    0; }

    template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return
    0; }


    ostream& operator<<(ostream& os, const modint998244353& a) { return os << a.val();
    }

    ostream& operator<<(ostream& os, const modint1000000007& a) { return os << a.val();
    }

    '
  code: '#include <bits/stdc++.h>

    #include <atcoder/all>


    using namespace std;

    using namespace atcoder;


    typedef long long ll;

    typedef long double ld;

    typedef vector<int> vi;

    typedef vector<ll> vll;

    typedef vector<ld> vld;

    typedef vector<vi> vvi;

    typedef vector<vll> vvll;


    template <class T> using Vec = vector<T>;

    template <class T> using Graph = Vec<Vec<T>>;


    #define _overload3(_1,_2,_3,name,...) name

    #define _rep(i,n) repi(i,0,n)

    #define repi(i,a,b) for(int i=int(a);i<int(b);++i)

    #define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

    #define _rrep(i,n) rrepi(i,n-1,-1)

    #define rrepi(i,a,b) for(int i=int(a);i>int(b);--i)

    #define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep)(__VA_ARGS__)


    #define all(x) (x).begin(),(x).end()

    #define SORT(x) sort(all(x))

    #define REVERSE(x) reverse(all(x))


    template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return
    0; }

    template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return
    0; }


    ostream& operator<<(ostream& os, const modint998244353& a) { return os << a.val();
    }

    ostream& operator<<(ostream& os, const modint1000000007& a) { return os << a.val();
    }'
  dependsOn: []
  isVerificationFile: false
  path: cplib/template.hpp
  requiredBy: []
  timestamp: '2024-05-05 15:00:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/fps.test.cpp
documentation_of: cplib/template.hpp
layout: document
redirect_from:
- /library/cplib/template.hpp
- /library/cplib/template.hpp.html
title: cplib/template.hpp
---
