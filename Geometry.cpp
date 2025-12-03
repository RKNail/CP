#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define vt vector
#define ft first
#define sd second
#define mp make_pair
#define i128 __int128

pll p_minus(pll p1, pll p2) {
    return mp(p2.ft - p1.ft, p2.sd - p1.sd);
}

i128 cross(pll v1, pll v2) {
    return (i128)v1.ft * v2.sd - (i128)v2.ft * v1.sd;
}

i128 cross(pll p1, pll p2, pll p3) {
    pll v1 = p_minus(p2, p1), v2 = p_minus(p3, p1);
    return cross(v1, v2);
}

bool intersept(ll a, ll b, ll c, ll d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool segment_intersept(pll p1, pll p2, pll p3, pll p4) {
    pll v1 = p_minus(p1, p2);
    pll v2 = p_minus(p1, p3);
    pll v3 = p_minus(p1, p4);
    pll v4 = p_minus(p3, p4);
    pll v5 = p_minus(p3, p2);
    pll v6 = p_minus(p3, p1);
    return
        intersept(p1.ft, p2.ft, p3.ft, p4.ft) &&
        intersept(p1.sd, p2.sd, p3.sd, p4.sd) &&
        cross(v1, v2) * cross(v1, v3) <= 0 &&
        cross(v4, v5) * cross(v4, v6) <= 0;

}
vector <pll> convex_hull(vector <pll> p) {
    if (p.size() == 1) {
        return p;
    }
    vector <pll> top, bottom;
    sort(p.begin(), p.end());
    for (int i =0; i < p.size(); i++) {
        while (bottom.size()>=2 && cross(bottom[bottom.size()-2], bottom[bottom.size()-1], p[i]) < 0) {
            bottom.pop_back();
        }
        bottom.push_back(p[i]);
    }
    for (int i = p.size()-1; i >= 0; --i) {
        while (top.size() >= 2 && cross(top[top.size()-2], top[top.size()-1], p[i]) < 0) {
            top.pop_back();
        }
        top.push_back(p[i]);
    }
    top.pop_back();
    bottom.pop_back();
    vector <pll> hull = bottom;
    hull.insert(hull.end(), top.begin(), top.end());
    return hull;
}
