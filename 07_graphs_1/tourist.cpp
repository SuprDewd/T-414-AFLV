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


vector<int> adj[100];
vector<int> low(100), num(100, -1);
vector<bool> incomp(100, false);

int curnum = 0;
stack<int> comp;

int num_comps = 0;
int num_comp[1000];
vector<int> C[1000];
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
        while (true) {
            int cur = comp.top();
            comp.pop();

            num_comp[cur] = num_comps;
            C[num_comps].push_back(cur);

            incomp[cur] = false;
            if (cur == u) {
                break;
            }
        }

        num_comps++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (num[i] == -1) {
            scc(i);
        }
    }

    for (int i = 0; i < num_comps; i++) {
        bool ok = true;
        for (int j = 0; j < C[i].size(); j++) {
            int u = C[i][j];
            for (int k = 0; k < adj[u].size(); k++) {
                int v = adj[u][k];
                if (num_comp[u] != num_comp[v]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            for (int j = 0; j < C[i].size(); j++) {
                int u = C[i][j];
                printf("%d\n", u);
            }
        }
    }

    return 0;
}

