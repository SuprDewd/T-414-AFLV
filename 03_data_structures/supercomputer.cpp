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
    scanf("%d %d\n", &n, &m);

    int k = (int)sqrt(n) + 2;

    vector<int> arr(n);
    vector<int> buck((n-1)/k + 1);

    rep(i,0,m) {
        char op;
        scanf("%c ", &op);
        if (op == 'F') {
            int x;
            scanf("%d\n", &x);
            x--;

            if (arr[x] == 0) {
                arr[x] = 1;
                buck[x/k]++;
            } else {
                arr[x] = 0;
                buck[x/k]--;
            }

        } else {
            int l, r;
            scanf("%d %d\n", &l, &r);
            l--, r--;

            int sum = 0;
            for (int i = 0; i < buck.size(); i++) {

                int a = k*i,
                    b = a + k-1;

                if (l <= a && b <= r) {
                    sum += buck[i];
                } else if (b < l || r < a) {
                } else {
                    for (int j = max(l,a); j <= min(b,r); j++) {
                        sum += arr[j];
                    }
                }
            }

            printf("%d\n", sum);
        }
    }
    return 0;
}

