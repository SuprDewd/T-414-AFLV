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

double f(double x) {
    return 2.0 * x + 4;
}

bool p(double j) {
    return f(j) >= 0.0;
}

int main()
{

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

