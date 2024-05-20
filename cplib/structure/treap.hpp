template<
    class S,
    auto op,
    auto e,
    class F = S,
    auto mapping = [](F f, S x) { return x; },
    auto composition = [](F f, F g) { return f; },
    auto id = []() { return F(); }
>
class Treap {
public:
    static unsigned long xor128() {
        static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        unsigned long t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
    struct Node {
        S val, prod;
        F lazy;
        unsigned priority, size;
        bool rev;
        Node *left, *right;
        Node(): val(e()), prod(e()), lazy(id()), priority(xor128()), size(1), rev(false), left(nullptr), right(nullptr) {}
        Node(S val): val(val), prod(val), lazy(id()), priority(xor128()), size(1), rev(false), left(nullptr), right(nullptr) {}
    };
    Treap() : root(nullptr) {}
    Treap(Node *root) : root(root) {}
    Treap(vector<S> &v) { root = build(v); }
    Treap(int n) { vector<S> v(n, e()); root = build(v);}
    unsigned size() { return size(root); }
    void insert(int k, S val) { root = insert(root, k, val); }
    void erase(int k) { root = erase(root, k); }
    void merge(Treap &t) { root = merge(root, t.root); }
    pair<Treap, Treap> split(int k) { auto [l, r] = split(root, k); return {Treap(l), Treap(r)}; }
    S get(int k) { return get(root, k)->val; }
    void set(int k, S val) { erase(k); insert(k, val); }
    S prod(int l, int r) {
        if (l >= r) return e();
        auto [left, rest] = split(root, l);
        auto [mid, right] = split(rest, r - l);
        S res = prod(mid);
        root = merge(merge(left, mid), right);
        return res;
    }
    void apply(int l, int r, F f) {
        if (l >= r) return;
        auto [left, rest] = split(root, l);
        auto [mid, right] = split(rest, r - l);
        propagate(mid, f);
        root = merge(merge(left, mid), right);
    }
    void reverse(int l, int r) {
        if (l >= r) return;
        auto [left, rest] = split(root, l);
        auto [mid, right] = split(rest, r - l);
        mid->rev ^= 1;
        root = merge(merge(left, mid), right);
    }
private:
    Node *root;
    unsigned size(Node *node) { return node ? node->size : 0; }
    S prod(Node *node) { return node ? node->prod : e(); }
    Node *update(Node *node) {
        node->size = size(node->left) + size(node->right) + 1;
        node->prod = op(op(prod(node->left), node->val), prod(node->right));
        return node;
    }
    Node *build(vector<S> &v) {
        Node *node = nullptr;
        for (auto val: v) node = merge(node, new Node(val));
        return node;
    }
    Node *merge(Node *left, Node *right) {
        push(left); push(right);
        if (!left || !right) return left ? left : right;
        if (left->priority > right->priority) {
            left->right = merge(left->right, right);
            return update(left);
        } else {
            right->left = merge(left, right->left);
            return update(right);
        }
    }
    pair<Node*, Node*> split(Node *node, int k) {
        push(node);
        if (!node) return {nullptr, nullptr};
        if (k <= (int)size(node->left)) {
            auto [left, right] = split(node->left, k);
            node->left = right;
            return {left, update(node)};
        } else {
            auto [left, right] = split(node->right, k - size(node->left) - 1);
            node->right = left;
            return {update(node), right};
        }
    }
    Node *insert(Node *node, int k, S val) {
        auto [left, right] = split(node, k);
        return merge(merge(left, new Node(val)), right);
    }
    Node *erase(Node *node, int k) {
        auto [left, right] = split(node, k);
        auto [one, right_others] = split(right, 1);
        delete one;
        return merge(left, right_others);
    }
    Node *get(Node *node, int k) {
        if (k < size(node->left)) return get(node->left, k);
        if (k == size(node->left)) return node;
        return get(node->right, k - size(node->left) - 1);
    }
    void push(Node *node) {
        if (node && node->rev) {
            swap(node->left, node->right);
            if (node->left) node->left->rev ^= 1;
            if (node->right) node->right->rev ^= 1;
            node->rev = false;
        }
        if (node && node->lazy != id()) {
            propagate(node->left, node->lazy);
            propagate(node->right, node->lazy);
            node->lazy = id();
        }
    }
    void propagate(Node *node, F f) {
        if (!node) return;
        node->val = mapping(f, node->val);
        node->prod = mapping(f, node->prod);
        node->lazy = composition(node->lazy, f);
    }
};