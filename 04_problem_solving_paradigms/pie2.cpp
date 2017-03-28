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

const double pi = acos(-1.0);
int n, f;
vector<double> rad;

double F(double x) {
    double cnt = 0;
    for (int i = 0; i < size(rad); i++) {
        double v = rad[i] * rad[i] * pi;
        cnt += floor(v/x);
    }
    return cnt;
}

int main() {
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        cin >> n >> f;
        rad.clear();
        rep(i,0,n) {
            double r;
            cin >> r;
            rad.push_back(r);
        }

        double EPS = 1e-10,
            lo = 0,
            hi = 1e9;
        while (hi - lo > EPS) {
            double mid = (lo + hi) / 2.0;
            if (F(mid) < f + 1) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        cout << setprecision(10) << fixed << lo << endl;
    }

    return 0;
}

