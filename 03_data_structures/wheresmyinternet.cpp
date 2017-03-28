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


#define MAXN 200100
int p[MAXN];
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]); }
void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
    for (int i = 0; i < MAXN; i++) p[i] = i;

    int n, m;
    cin >> n >> m;
    rep(i,0,m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        unite(a,b);
    }

    bool any = false;
    rep(i,0,n) {
        if (find(i) != find(0)) {
            cout << i+1 << endl;
            any = true;
        }
    }

    if (!any) {
        cout << "Connected" << endl;
    }

    return 0;
}

