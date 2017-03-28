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

int main() {
    int n, m;
    int ts = 0;
    while (cin >> n) {
        printf("Case %d:\n", ++ts);
        vi arr(n);
        rep(i,0,n) {
            cin >> arr[i];
        }
        cin >> m;
        rep(i,0,m) {
            int x;
            cin >> x;
            int best = 1323;
            bool found = false;
            for (int j = 0; j < n; j++) {
                for (int k = j+1; k<n; k++) {
                    int here = arr[j] + arr[k];
                    if (!found || abs(x - here) < abs(x - best)) {
                        best = here;
                        found = true;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", x, best);
        }
    }
    return 0;
}

