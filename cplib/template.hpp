#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;

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

#define dump(x) cerr << #x << " = " << (x) << endl
#define print(x) cout << (x) << endl
#define yes(f) cout << ((f) ? "Yes" : "No") << endl

#define ge(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define gt(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define le(v, x) (int)(upper_bound(all(v), x) - v.begin())-1
#define lt(v, x) (int)(lower_bound(all(v), x) - v.begin())-1

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ostream& operator<<(ostream& os, const modint998244353& a) { return os << a.val(); }
ostream& operator<<(ostream& os, const modint1000000007& a) { return os << a.val(); }

template<class T> istream& operator>>(istream& is, vector<T>& vec) { for (T& x : vec) is >> x; return is; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (const T& x : vec) os << x << ' '; return os; }