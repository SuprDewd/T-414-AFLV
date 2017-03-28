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

struct flow_network {

    struct edge {
        int u, v, cap;
        edge *rev;
        bool forward;
        edge(int _u, int _v, int _cap, bool forw)
            : u(_u), v(_v), cap(_cap), forward(forw) { }
    };

    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }

    void add_edge(int u, int v, int cap) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->rev = rev;
        rev->rev = e;
        adj[u].push_back(e);
        adj[v].push_back(rev);
    }

    int augment(int s, int t) {
        vector<edge*> back(n, (edge*)0);
        queue<int> Q;
        Q.push(s);
        back[s] = (edge*)1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i]->v;
                if (back[v] == NULL && adj[u][i]->cap > 0) {
                    back[v] = adj[u][i];
                    Q.push(v);
                }
            }
        }

        if (back[t] == NULL)
            return 0;

        stack<edge*> S;
        S.push(back[t]);
        int bneck = back[t]->cap;
        while (S.top()->u != s) {
            S.push(back[S.top()->u]);
            bneck = min(bneck, S.top()->cap);
        }

        while (!S.empty()) {
            S.top()->cap -= bneck;
            S.top()->rev->cap += bneck;
            S.pop();
        }

        return bneck;
    }

    int max_flow(int source, int sink) {
        int flow = 0;
        while (true) {
            int f = augment(source, sink);
            if (f == 0) {
                break;
            }

            flow += f;
        }

        return flow;
    }
};

int main() {
    int n;
    int at = 1;
    while (cin >> n && n != 0) {
        flow_network G(n);

        int s, t, m;
        cin >> s >> t >> m;
        s--, t--;
        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;
            G.add_edge(u, v, c);
            G.add_edge(v, u, c);
        }

        cout << "Network " << (at++) << endl;
        cout << "The bandwidth is " << G.max_flow(s, t) << "." << endl;
        cout << endl;
    }

    return 0;
}

