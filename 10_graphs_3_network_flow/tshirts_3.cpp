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
    map<string, int> num;
    num["XS"] = 0;
    num["S"] = 1;
    num["M"] = 2;
    num["L"] = 3;
    num["XL"] = 4;
    num["XXL"] = 5;

    int ts;
    cin >> ts;
    for (int t = 0; t < ts; t++) {

        int n, m;
        cin >> n >> m;

        int SOURCE = 0,
            SINK = 1,
            LEFT = 2,
            RIGHT = LEFT + size(num),
            CNT = RIGHT + m;

        flow_network G(CNT);

        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            G.add_edge(LEFT + num[a], RIGHT + i, 1);
            G.add_edge(LEFT + num[b], RIGHT + i, 1);
        }

        for (int i = 0; i < size(num); i++) {
            G.add_edge(SOURCE, LEFT + i, n/6);
        }
        for (int i = 0; i < m; i++) {
            G.add_edge(RIGHT + i, SINK, 1);
        }

        cout << G.max_flow(SOURCE, SINK) << endl;
        for (int i = 0; i < size(num); i++) {
            for (int j = 0; j < size(G.adj[LEFT + i]); j++) {
                if (G.adj[LEFT+i][j]->forward && G.adj[LEFT+i][j]->cap == 0) {
                    cout << "tshirts " << i << ", volunteer " << (G.adj[LEFT+i][j]->v - RIGHT) << endl;
                }
            }
        }
    }
    return 0;
}

