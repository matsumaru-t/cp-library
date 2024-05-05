#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../cplib/template.hpp"
#include "../../cplib/math/fps.hpp"

int main() {
    using mint = modint998244353;
    using fps = FormalPowerSeries<mint>;

    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];

    fps f(A.begin(), A.end());
    f = f.inv(N);

    for (auto &x: f) cout << x << " ";
    cout << endl;
}