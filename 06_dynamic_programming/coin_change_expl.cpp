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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo


int INF = 100000; // INF táknar óendanlegt, nota það til að segja ef það er ekki til lausn
int d[10]; // d[i] er gildið á peningi i
int mem[10][10000]; // mem[i][x] er svarið við opt(i, x), eða -1 ef við vitum ekki hvað svarið er.
                    // mem fylkið er notað svo við séum ekki að endurreikna svarið við opt(i, x) oft.
                    // þetta er það sem gerir forritið hratt, og er kallað memoization (sem er ein leið til að leysa vandamál með dynamic programming)
bool taken[10][10000];  // taken[i][x] segir hvort við tókum i-ta peninginn eða ekki í optimal lausninni sem við finnum í opt(i, x), sjá betur að neðan

int opt(int i, int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (i == -1) return INF;

    if (mem[i][x] != -1) return mem[i][x];

    int res = INF;

    int a = 1 + opt(i, x - d[i]);
    int b = opt(i - 1, x);

    if (a < b) {
        taken[i][x] = true;
    } else {
        taken[i][x] = false;
    }

    res = min(a, b);

    mem[i][x] = res;
    return res;
}


void find_opt(int i, int x) {
    if (x == 0) {
        return;
    }

    if (taken[i][x]) {
        cout << d[i] << " ";

        find_opt(i, x - d[i]);

    } else {

        find_opt(i - 1, x);
    }
}


int main()
{
    memset(mem, -1, sizeof(mem));

    int dcnt = 3;

    d[0] = 7;
    d[1] = 8;
    d[2] = 9;

    for (int x = 0; x <= 100; x++) {
        cout << x << " " << opt(dcnt - 1, x) << ": ";

        if (opt(dcnt - 1, x) == INF) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            find_opt(dcnt - 1, x);
            cout << endl;
        }
    }

    return 0;
}

