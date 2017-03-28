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

ll memory[1000];
ll fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    if (memory[n] != -1) {
        return memory[n];
    }
    ll res = fibonacci(n-2) + fibonacci(n-1);
    memory[n] = res;
    return res;
}

int main() {
    memset(memory, -1, sizeof(memory));
    cout << fibonacci(500) << endl;

    return 0;
}

