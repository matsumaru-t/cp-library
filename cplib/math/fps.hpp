template<typename mint>
struct FormalPowerSeries: vector<mint> {
    using fps = FormalPowerSeries;
    using vector<mint>::vector;

    fps& operator+=(const fps& g) {
        if (this->size() < g.size()) this->resize(g.size());
        for (int i = 0; i < (int)g.size(); i++) (*this)[i] += g[i];
        return *this;
    }
    fps& operator+=(const mint& a) {
        if (this->empty()) this->resize(1);
        (*this)[0] += a;
        return *this;
    }
    fps& operator-=(const fps& g) {
        if (this->size() < g.size()) this->resize(g.size());
        for (int i = 0; i < (int)g.size(); i++) (*this)[i] -= g[i];
        return *this;
    }
    fps& operator-=(const mint& a) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= a;
        return *this;
    }
    fps& operator*=(const fps& g) {
        vector<mint> h = convolution(*this, g);
        return *this = fps(h.begin(), h.end());
    }
    fps& operator*=(const mint& a) {
        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= a;
        return *this;
    }

    fps operator+(const fps& g) const { return fps(*this) += g; }
    fps operator+(const mint& a) const { return fps(*this) += a; }
    fps operator-(const fps& g) const { return fps(*this) -= g; }
    fps operator-(const mint& a) const { return fps(*this) -= a; }
    fps operator-() const { return fps(*this) *= -1; }
    fps operator*(const fps& g) const { return fps(*this) *= g; }
    fps operator*(const mint& a) const { return fps(*this) *= a; }

    fps inv(int n) {
        assert((*this)[0] != 0);
        fps res = {(*this)[0].inv()};
        for (int d = 1; d < n; d <<= 1) {
            res = res * 2 - *this * res * res;
            res.resize(d << 1);
        }
        return res.resize(n), res;
    }
    fps& operator/=(const fps& g) {
        assert(!g.empty() && g[0] != 0);
        return *this *= g.inv(this->size());
    }
    fps& operator/=(const mint& a) {
        assert(a != 0);
        return *this *= a.inv();
    }
};