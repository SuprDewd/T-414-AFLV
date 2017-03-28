#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo


struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};


int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++) {

        int n, m;
        scanf("%d %d\n", &n, &m);

        union_find uf(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d\n", &a, &b);

            a--, b--;

            uf.unite(a, b);
        }


        vector<int> sz(n, 0);

        for (int i = 0; i < n; i++) {
            sz[uf.find(i)]++;
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (i == uf.find(i)) {
                mx = max(mx, sz[i]);
            }
        }

        printf("%d\n", mx);
    }


    return 0;
}

