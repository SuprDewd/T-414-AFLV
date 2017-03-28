#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
// const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)


int INF = 100000;
// int d[10]={1, 10, 21, 34, 70, 100, 350, 1225, 1500};
int d[10]={7,8,9};
int mem[10][10000];
bool take[10][10000];
int opt(int i, int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (i == -1) return INF;
    if (mem[i][x] != -1) return mem[i][x];

    int res = INF,
        a = 1 + opt(i, x - d[i]),
        b = opt(i - 1, x);

    take[i][x] = true;
    res = a;

    if (b < a) {
        take[i][x] = false;
        res = b;
    }

    mem[i][x] = res;
    return res;
}

void reconstruct(int i, int x) {
    if (x < 0) {
        assert(false);
        return;
    }
    if (x == 0) {
        cout << endl;
        return;
    }
    if (i == -1) {
        assert(false);
        return;
    }

    if (take[i][x]) {
        cout << d[i] << " ";
        reconstruct(i, x - d[i]);
    } else {
        reconstruct(i - 1, x);
    }
}

int main() {
    memset(mem, -1, sizeof(mem));

    int x = 5;
    cout << opt(2, x) << endl;
    if (opt(2, x) == INF) {
        cout << "impossible" << endl;
    } else {
        reconstruct(2, x);
    }

    return 0;
}

