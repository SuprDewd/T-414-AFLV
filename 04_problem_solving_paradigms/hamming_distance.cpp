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

int n, k;
bool bit_set[100];
int bits_set = 0;

void generate(int at) {

    if (bits_set > k) {
        return;
    }

    if (at == n) {

        if (bits_set == k) {
            for (int i = 0; i < n; i++) {
                if (bit_set[i]) {
                    printf("1");
                } else {
                    printf("0");
                }
            }

            printf("\n");
        }

    } else {

        bit_set[at] = false;
        generate(at + 1);

        bit_set[at] = true;
        bits_set++;
        generate(at + 1);
        bits_set--;
    }

}

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++) {

        if (t != 0) {
            printf("\n");
        }

        scanf("%d %d\n", &n, &k);

        bits_set = 0;
        memset(bit_set, 0, sizeof(bit_set));

        generate(0);

    }

    return 0;
}

