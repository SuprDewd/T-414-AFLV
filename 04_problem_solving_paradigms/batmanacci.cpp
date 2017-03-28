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


long long len[100100];

char get(long long n, long long k) {
    if (n == 1) {
        // N
        return 'N';
    } else if (n == 2) {
        return 'A';
    } else {
        long long L = len[n-2];
        if (k <= L) {
            return get(n-2, k);
        } else {
            return get(n-1, k-L);
        }
    }
}

int main() {
    len[1] = 1;
    len[2] = 1;
    for (int i = 3; i < 100100; i++) {
        len[i] = len[i-2] + len[i-1];
        if (len[i] > 1000000000000000000)
            len[i] = 1000000000000000001;
    }

    long long n, k;
    cin >> n >> k;

    cout << get(n, k) << endl;

    return 0;
}

