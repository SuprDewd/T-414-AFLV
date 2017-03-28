#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)


struct segment_tree {
    segment_tree *left, *right;
    int from, to, value;
    segment_tree(int from, int to)
        : from(from), to(to), left(NULL), right(NULL), value(0) { }
};
segment_tree* build(const vector<int> &arr, int l, int r) {
    if (l > r) return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r) {
        res->value = arr[l];
    } else {
        int m = (l + r) / 2;
        res->left = build(arr, l, m);
        res->right = build(arr, m + 1, r);
        if (res->left != NULL) res->value += res->left->value;
        if (res->right != NULL) res->value += res->right->value;
    }
    return res;
}
int query(segment_tree *tree, int l, int r) {
    if (tree == NULL) return 0;
    if (l <= tree->from && tree->to <= r) return tree->value;
    if (tree->to < l) return 0;
    if (r < tree->from) return 0;
    return query(tree->left, l, r) + query(tree->right, l, r);
}
int update(segment_tree *tree, int i) {
    if (tree == NULL) return 0;
    if (tree->to < i) return tree->value;
    if (i < tree->from) return tree->value;
    if (tree->from == tree->to && tree->from == i) {
        // tree->value = val;
        tree->value = 1 - tree->value;
    } else {
        tree->value = update(tree->left, i) + update(tree->right, i);
    }
    return tree->value;
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);

    vector<int> mem(n,0);
    segment_tree *st = build(mem, 0, n-1);

    rep(i,0,m) {
        char op;
        scanf("%c ", &op);
        if (op == 'F') {
            int x;
            scanf("%d\n", &x);
            x--;

            update(st, x);

        } else {
            int l, r;
            scanf("%d %d\n", &l, &r);
            l--, r--;

            printf("%d\n", query(st, l, r));
        }
    }
    return 0;
}

