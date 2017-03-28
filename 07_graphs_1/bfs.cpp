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

vector<int> adj[1000];
vector<int> dist(1000, -1);
int back[1000];

int main() {

    int A = 0,
        B = 1;

    adj[0].push_back(1);
    adj[1].push_back(0);

    queue<int> Q;
    Q.push(A);
    dist[A] = 0;
    back[A] = -1;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {
                Q.push(v);
                dist[v] = 1 + dist[u];
                back[v] = u;
            }
        }
    }

    printf("dist: %d\n", dist[B]);
    printf("path (reversed):\n");

    int cur = B;
    while (true) {
        printf("%d\n", cur);
        if (back[cur] == -1) {
            break;
        }
        cur = back[cur];
    }

    return 0;
}

