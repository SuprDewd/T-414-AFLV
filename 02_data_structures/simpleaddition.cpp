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

struct big_integer {
    string s;
    big_integer(string _s) {
        s = _s;
    }

    big_integer operator + (const big_integer &other) const {
        string a = s,
               b = other.s;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        stringstream c;

        int carry = 0;
        for (int at = 0; at < size(a) || at < size(b) || carry > 0; at++) {
            int cur = carry;
            if (at < size(a)) cur += a[at] - '0';
            if (at < size(b)) cur += b[at] - '0';

            // if (cur < 10) {
            //     c << cur;
            //     carry = 0;
            // } else {
            //     c << (cur - 10);
            //     carry = 1;
            // }

            c << (cur % 10);
            carry = cur / 10;
        }

        string out = c.str();
        reverse(out.begin(), out.end());
        return big_integer(out);
    }
};

int main() {
    string a, b;
    cin >> a >> b;

    big_integer x = a,
                y = b;

    big_integer z = x + y;

    cout << z.s << endl;

    return 0;
}

