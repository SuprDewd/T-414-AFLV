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

string a = "bananinn";
string b = "kaninan";

int lcs(int i, int j) {
    if (i == -1 || j == -1) {
        return 0;
    }

    int res = 0;
    res = max(res, lcs(i - 1, j));
    res = max(res, lcs(i, j - 1));
    if (a[i] == b[j]) {
        res = max(res, 1 + lcs(i - 1, j - 1));
    }

    return res;
}

int main() {

    cout << lcs(a.size() - 1, b.size() - 1) << endl;

    return 0;
}

