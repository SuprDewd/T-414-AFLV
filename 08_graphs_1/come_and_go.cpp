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


vector<int> adj[2100];
vector<int> low(2100), num(2100, -1);
vector<bool> incomp(2100, false);

int curnum = 0;
int components = 0;

stack<int> comp;

void scc(int u) {
    comp.push(u);
    incomp[u] = true;

    low[u] = num[u] = curnum++;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            scc(v);
            low[u] = min(low[u], low[v]);
        } else if (incomp[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (num[u] == low[u]) {
        // printf("comp: ");
        while (true) {
            int cur = comp.top();
            comp.pop();
            incomp[cur] = false;
            // printf("%d, ", cur);
            if (cur == u) {
                break;
            }
        }

        components++;

        // printf("\n");
    }
}


int main()
{
    int n, m;
    while (scanf("%d %d\n", &n, &m) != EOF && !(n == 0 && m == 0)) {

        curnum = 0;
        components = 0;
        num.assign(2100, -1);

        for (int i = 0; i < m; i++) {
            int a, b, p;
            scanf("%d %d %d\n", &a, &b, &p);

            a--;
            b--;

            if (p == 1) {
                adj[a].push_back(b);
            } else {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }

        for (int i = 0; i < n; i++) {
            if (num[i] == -1) {
                scc(i);
            }
        }

        // printf("\n");

        if (components == 1) {
            printf("%d\n", 1);
        } else {
            printf("%d\n", 0);
        }

        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
    }

    return 0;
}

