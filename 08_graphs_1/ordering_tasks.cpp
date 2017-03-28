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

vector<int> adj[1000];
vector<bool> visited(1000, false);
vector<int> order;
void topsort(int u) {
    if (visited[u]) {
        return;
    }

    visited[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topsort(v);
    }

    order.push_back(u);
}

int main()
{
    int n, m;
    while (scanf("%d %d\n", &n, &m) != EOF && !(n == 0 && m == 0)) {
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d\n", &a, &b);
            a--, b--;
            adj[b].push_back(a);
        }

        order.clear();
        visited.assign(n, false);

        for (int u = 0; u < n; u++) {
            topsort(u);
        }

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                printf(" ");
            }

            printf("%d", order[i] + 1);
        }

        printf("\n");

        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
    }

    return 0;
}

