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
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++) {
        int r;
        scanf("%d", &r);

        vector<int> arr(r);
        for (int i = 0; i < r; i++) {
            scanf("%d", &arr[i]);
        }

        int mn = -1;

        for (int i = 0; i < r; i++) {

            int dst = 0;
            for (int j = 0; j < r; j++) {
                dst += abs(arr[i] - arr[j]);
            }

            if (mn == -1 || dst < mn) {
                mn = dst;
            }
        }

        printf("%d\n", mn);
    }

    return 0;
}

