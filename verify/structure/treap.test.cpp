#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../cplib/template.hpp"
#include "../../cplib/structure/treap.hpp"

int op(int a, int b) { return min(a, b); }
int e() { return 1000000005; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    cin >> a;

    Treap<int, op, e> t(a);
    rep(i, Q) {
        int l, r;
        cin >> l >> r;
        cout << t.prod(l, r) << endl;
    }
}
