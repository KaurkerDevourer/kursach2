#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<typename T>
vector<T> &operator--(vector<T> &v) {
    for (auto &i: v) --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i: v) ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v) os << i << ' ';
    return os;
}

template<typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p) {
    --p.first;
    --p.second;
    return p;
}

template<typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p) {
    ++p.first;
    ++p.second;
    return p;
}

template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}

template<typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) { return mp(a.first - b.first, a.second - b.second); }

template<typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) { return mp(a.first + b.first, a.second + b.second); }

const ll INFLL = 1e18;
const int MAXN = 1e6 + 100;
const int INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

pair<vpii, bool> get_solution(pii a, pii b) {
    if (a.fi == b.fi && a.se == b.se) {
        return {{}, true};
    }

    bool type_a = ((a.fi + a.se) & 1);
    bool type_b = ((b.fi + b.se) & 1);

    if (!type_b) {
        return {{}, false};
    }

    if (!type_a) {
        vector<int> xx = {2, 2, -2, -2, 1, -1, 1, -1};
        vector<int> yy = {1, -1, 1, -1, 2, -2, 2, -2};
        pair<vpii, bool> ans;
        for (int i = 0; i < xx.size(); i++) {
            pii new_a = {a.fi + xx[i], a.se + yy[i]};
            auto what = get_solution(new_a, b);
            reverse(all(what.fi));
            what.fi.pb(new_a);
            reverse(all(what.fi));
            if (!ans.se) {
                swap(ans, what);
            } else if (!what.se);
            else {
                if (ans.fi.size() > what.fi.size())
                    swap(ans, what);
            }
        }
        return ans;
    } else {
        int dx = b.fi - a.fi, dy = b.se - a.se;
        if (abs(dx) == abs(dy)) {
            return {{b}, true};
        } else {
            assert(!((dy - dx) & 1));
            int A = (dy - dx) / 2;
            return {{{a.fi - A, a.se + A}, b}, true};
        }
    }
}

void solve() {
    pii a, b;
    cin >> a.fi >> a.se >> b.fi >> b.se;
    auto ans = get_solution(a, b);
    if (!ans.se)
        cout << -1 << '\n';
    else {
        cout << ans.fi.size() << '\n';
        for (auto to: ans.fi)
            cout << to.fi << " " << to.se << '\n';
    }
}

signed main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
//    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}
