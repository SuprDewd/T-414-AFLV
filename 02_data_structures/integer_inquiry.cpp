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

struct big_integer {
    string data;

    big_integer(string num) {
        data = num;
    }

    big_integer operator +(const big_integer &other) {
        string a = data,
               b = other.data;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        stringstream ss;

        int carry = 0;
        for (int i = 0; i < max(a.size(), b.size()); i++) {

            int ad = i < a.size() ? a[i] - '0' : 0;
            int bd = i < b.size() ? b[i] - '0' : 0;

            int cur = ad + bd + carry;

            carry = 0;

            if (cur >= 10) {
                carry = 1;
                cur -= 10;
            }

            ss << cur;
        }

        if (carry > 0) {
            ss << carry;
            carry = 0;
        }

        string c = ss.str();
        reverse(c.begin(), c.end());

        return big_integer(c);
    }
};


int main() {

    big_integer sum("0");

    string line;
    while (getline(cin, line) && line != "0") {

        big_integer num(line);
        sum = sum + num;
    }

    cout << sum.data << endl;

    return 0;
}

