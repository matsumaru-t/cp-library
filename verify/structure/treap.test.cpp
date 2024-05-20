#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../cplib/template.hpp"
#include "../../cplib/structure/treap.hpp"

using S = int;
S op(S a, S b) { return min(a, b); }
S e() { return 1001001001; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    cin >> a;

    Treap<S, op, e> t(a);
    rep(i, Q) {
        int l, r;
        cin >> l >> r;
        cout << t.prod(l, r) << endl;
    }
}
