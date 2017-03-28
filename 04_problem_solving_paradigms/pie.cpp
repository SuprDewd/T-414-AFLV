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

const double pi = acos(-1.0);

int n, f;
vector<double> pies;

bool p(double v) {

    int slices = 0;

    for (int i = 0; i < n; i++) {

        double r = pies[i];
        double volume = 1 * pi * r * r;

        slices += static_cast<int>(floor(volume / v) + 1e-9);
    }

    return !(slices >= f);
}

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++) {

        scanf("%d %d\n", &n, &f);
        f++;

        pies = vector<double>(n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &pies[i]);
        }

        double EPS = 1e-6,
            lo = 0,
            hi = 1e9;

        while (hi - lo > EPS) {
            double mid = (lo + hi) / 2.0;

            if (p(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        printf("%0.10lf\n", lo);
    }


    return 0;
}

