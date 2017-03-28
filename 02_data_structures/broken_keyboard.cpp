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
    string line;
    while (getline(cin, line)) {

        list<char> text;
        list<char>::iterator at = text.begin();

        for (int i = 0; i < line.size(); i++) {

            char c = line[i];

            if (c == '[') {

                at = text.begin();

            } else if (c == ']') {

                at = text.end();

            } else {

                text.insert(at, c);

            }

        }

        for (at = text.begin(); at != text.end(); ++at) {
            printf("%c", *at);
        }

        printf("\n");

    }

    return 0;
}

