#define PROBLEM "https://atcoder.jp/contests/abc298/tasks/abc298_d"

#include "../../cplib/template.hpp"
#include "../../cplib/structure/swag.hpp"

using S = pair<modint998244353, modint998244353>;
auto op = [](S a, S b) { return S(a.first*b.second+b.first, a.second*b.second); };
auto e = []() { return S(0, 1); };

int main() {
    int Q;
    cin >> Q;

    swag<S, op, e> sg;
    sg.push_back(S(1, 1));

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            sg.push_back(S(x, 10));
        } else if (t == 2) {
            sg.pop_front();
        } else {
            print(sg.fold().first);
        }
    }
}