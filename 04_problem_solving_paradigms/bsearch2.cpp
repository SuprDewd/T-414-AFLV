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

double f(double x) {
    return 3*x - 10;
}

bool p(double i) {
    return f(i) >= 0;
}

int main() {

    double EPS = 1e-10,
           lo = -1000.0,
           hi = 1000.0;
    while (hi - lo > EPS) {
        double mid = (lo + hi) / 2.0;
        if (p(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%0.10lf\n", lo);

    return 0;
}

