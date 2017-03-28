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

int n;
vector<int> number;
void generate(int k) {

    if (k > 0) {
        stringstream ss;
        for (int i = 0; i < k; i++) {
            ss << number[i];
        }
        int x;
        ss >> x;
        if (x % k != 0) {
            return;
        }
    }

    if (k == n) {
        for (int i = 0; i < n; i++) {
            cout << number[i];
        }
        cout << endl;
    } else {
        for (int d = 0; d <= 9; d++) {
            if (k == 0 && d == 0) {
                continue;
            }
            number.push_back(d);
            generate(k+1);
            number.pop_back();
        }
    }
}


int main() {
    cin >> n;

    generate(0);

    return 0;
}

