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
    int n;
    cin >> n;
    map<string, vector<int> > trips;
    for (int i = 0; i < n; i++) {
        string name;
        int year;
        cin >> name >> year;
        trips[name].push_back(year);
    }
    for (map<string,vector<int> >::iterator it = trips.begin(); it != trips.end(); ++it) {
        sort(it->second.begin(), it->second.end());
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string name;
        int k;
        cin >> name >> k;
        cout << trips[name][k-1] << endl;
    }
    return 0;
}

