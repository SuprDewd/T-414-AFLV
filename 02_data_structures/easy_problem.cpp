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

int main()
{
    int n, m;
    while (scanf("%d %d\n", &n, &m) != EOF) {

        vector<int> *loc = new vector<int>[1000100];

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);

            loc[x].push_back(i);
        }


        for (int i = 0; i < m; i++) {
            int k, v;
            scanf("%d %d\n", &k, &v);

            if (k - 1 < loc[v].size()) {
                printf("%d\n", loc[v][k-1] + 1);
            } else {
                printf("0\n");
            }
        }
    }

    return 0;
}

