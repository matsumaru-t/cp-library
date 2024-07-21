template<class S, auto op, auto e>
class swag {
    public:
        swag() { topfold.push(e()); bottomfold.push(e()); }
        void push_back(S x) { _pushbottom(x); }
        void push_front(S x) { _pushtop(x); }
        S fold() { return op(topfold.top(), bottomfold.top()); }
        S pop_front() {
            if (top.empty()) {
                vector<S> st;
                while (!bottom.empty()) st.push_back(_popbottom());
                int n = st.size();
                for (int i = n/2; i < n; i++) _pushtop(st[i]);
                for (int i = n/2-1; i >= 0; i--) _pushbottom(st[i]);
            }
            if (top.empty()) return e();
            else return _poptop();
        }
        S pop_back() {
            if (bottom.empty()) {
                vector<S> st;
                while (!top.empty()) st.push_back(_poptop());
                int n = st.size();
                for (int i = n/2-1; i >= 0; i--) _pushtop(st[i]);
                for (int i = n/2; i < n; i++) _pushbottom(st[i]);
            }
            if (bottom.empty()) return e();
            else return _popbottom();
        }

    private:
        stack<S> top, bottom, topfold, bottomfold;
        void _pushbottom(S x) {
            bottom.push(x);
            bottomfold.push(op(bottomfold.top(), x));
        }
        S _popbottom() {
            bottomfold.pop();
            S x = bottom.top();
            bottom.pop();
            return x;
        }
        void _pushtop(S x) {
            top.push(x);
            topfold.push(op(x, topfold.top()));
        }
        S _poptop() {
            topfold.pop();
            S x = top.top();
            top.pop();
            return x;
        }
};