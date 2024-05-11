template<class T, auto op, auto e> class Treap {
public:
    static unsigned long xor128() {
        static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        unsigned long t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
    struct Node {
        T val, prod;
        unsigned priority, size;
        Node *left, *right;
        Node(): val(e()), prod(e()), priority(xor128()), size(1), left(nullptr), right(nullptr) {}
        Node(T val): val(val), prod(val), priority(xor128()), size(1), left(nullptr), right(nullptr) {}
    };

    Treap() : root(nullptr) {}
    Treap(Node *root) : root(root) {}
    Treap(vector<T> &v) { root = build(v); }
    Treap(int n) { vector<T> v(n, e()); root = build(v);}
    unsigned size() { return size(root); }
    void insert(int k, T val) { root = insert(root, k, val); }
    void erase(int k) { root = erase(root, k); }
    void merge(Treap &t) { root = merge(root, t.root); }
    pair<Treap, Treap> split(int k) { auto [l, r] = split(root, k); return {Treap(l), Treap(r)}; }
    T get(int k) { return get(root, k)->val; }
    void set(int k, T val) { erase(k); insert(k, val); }
    T prod(int l, int r) {
        auto [left, rest] = split(root, l);
        auto [mid, right] = split(rest, r - l);
        T res = prod(mid);
        root = merge(merge(left, mid), right);
        return res;
    }
private:
    Node *root;
    unsigned size(Node *node) { return node ? node->size : 0; }
    T prod(Node *node) { return node ? node->prod : e(); }
    Node *update(Node *node) {
        node->size = size(node->left) + size(node->right) + 1;
        node->prod = op(op(prod(node->left), node->val), prod(node->right));
        return node;
    }
    Node *build(vector<T> &v) {
        Node *node = nullptr;
        for (auto val: v) node = merge(node, new Node(val));
        return node;
    }
    Node *merge(Node *left, Node *right) {
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
    Node *insert(Node *node, int k, T val) {
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
};