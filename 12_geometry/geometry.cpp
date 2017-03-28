#include <complex>
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define C(p0, r) P(p0), double r
#define PP(pp) pair<point,point> &pp
typedef complex<double> point;
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
int intersect(C(A, rA), C(B, rB), point & res1, point & res2) { 
    double d = abs(B - A);
    if ( rA + rB <  d - EPS || d < abs(rA - rB) - EPS) {
        return 0;
    }
    double a = (rA*rA - rB*rB + d*d) / 2*d;
    double h = sqrt(rA*rA - a*a);
    point v = normalize(B - A, a)
    point u = normalize(rotate(B-A), h);
    res1 = A + v + u;
    res2 = A + v - u;
    if (abs(u) < EPS) {
        return 1; 
    }
    return 2;
}
