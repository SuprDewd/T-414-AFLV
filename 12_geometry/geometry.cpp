#include <complex>
using namespace std;
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define C(p0, r) P(p0), double r
#define PP(pp) pair<point,point> &pp
typedef complex<double> point;
const double pi = acos(-1.0);
const double EPS = 1e-9;
double dot(P(a), P(b)) { 
    return real(conj(a) * b); 
}
double cross(P(a), P(b)) { 
    return imag(conj(a) * b); 
}
point rotate(P(p), double radians = pi / 2, P(about) = point(0,0)) { 
    return (p - about) * exp(point(0, radians)) + about; 
}
point proj(P(u), P(v)) { 
    return dot(u, v) / dot(u, u) * u; 
}
point normalize(P(p), double k = 1.0) { 
    return abs(p) == 0 ? point(0,0) : p / abs(p) * k; 
}
bool parallel(L(a, b), L(p, q)) { 
    return abs(cross(b - a, q - p)) < EPS; 
}
double ccw(P(a), P(b), P(c)) { 
    return cross(b - a, c - b); 
}
bool collinear(P(a), P(b), P(c)) { return abs(ccw(a, b, c)) < EPS; }
double angle(P(a), P(b), P(c)) {
    return acos(dot(b - a, c - b) / abs(b - a) / abs(c - b)); 
}
bool intersect(L(a, b), L(p, q), point &res, bool segment = false) {
    // NOTE: check for parallel/collinear lines before calling this function
    point r = b - a, s = q - p;
    double c = cross(r, s), t = cross(p - a, s) / c, u = cross(p - a, r) / c;
    if (segment && (t < 0-EPS || t > 1+EPS || u < 0-EPS || u > 1+EPS))
        return false;
    res = a + t * r;
    return true;
}
point closest_point(L(a, b), P(c), bool segment = false) {
    if (segment) {
        if (dot(b - a, c - b) > 0) return b;
        if (dot(a - b, c - a) > 0) return a;
    }
    double t = dot(c - a, b - a) / norm(b - a);
    return a + t * (b - a);
}

typedef vector<point> polygon;
#define MAXN 1000
point hull[MAXN];
bool cmp(const point &a, const point &b) {
    return abs(real(a) - real(b)) > EPS ?
        real(a) < real(b) : imag(a) < imag(b); }
int convex_hull(vector<point> p) {
    int n = p.size(), l = 0;
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && p[i] == p[i - 1])
            continue;
        while (l >= 2 && ccw(hull[l - 2], hull[l - 1], p[i]) >= 0)
            l--;
        hull[l++] = p[i];
    }
    int r = l;
    for (int i = n - 2; i >= 0; i--) {
        if (p[i] == p[i + 1])
            continue;
        while (r - l >= 1 && ccw(hull[r - 2], hull[r - 1], p[i]) >= 0)
            r--;
        hull[r++] = p[i];
    }
    return l == 1 ? 1 : r - 1;
}
