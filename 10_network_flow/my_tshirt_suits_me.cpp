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

int main()
{
    map<string, int> id;
    id["XS"] = 0;
    id["S"] = 1;
    id["M"] = 2;
    id["L"] = 3;
    id["XL"] = 4;
    id["XXL"] = 5;

    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++) {
        int shirts, ppl;
        scanf("%d %d\n", &shirts, &ppl);

        int SOURCE = 0,
            SINK = SOURCE + 1,
            PERSON = SINK + 1,
            SHIRT = PERSON + ppl,
            CNT = SHIRT + shirts;

        flow_network g(CNT);

        for (int i = 0; i < ppl; i++) {

            string a, b;
            cin >> a >> b;

            g.add_edge(PERSON + i, SHIRT + id[a], 1);
            g.add_edge(PERSON + i, SHIRT + id[b], 1);
        }

        for (int i = 0; i < ppl; i++) {
            g.add_edge(SOURCE, PERSON + i, 1);
        }

        for (int i = 0; i < shirts; i++) {
            g.add_edge(SHIRT + i, SINK, shirts / 6);
        }

        printf("%s\n", g.max_flow(SOURCE, SINK) == ppl ? "YES" : "NO");
    }

    return 0;
}

