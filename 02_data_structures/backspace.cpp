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

int main() {
    string s;
    cin >> s;
    deque<char> S;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '<') {
            S.pop_back();
        } else {
            S.push_back(c);
        }
    }

    while (!S.empty()) {
        cout << S.front();
        S.pop_front();
    }
    cout << endl;

    return 0;
}

