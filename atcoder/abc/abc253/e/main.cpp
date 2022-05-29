// URL : https://atcoder.jp/contests/abc253/tasks/abc253_e
#pragma region optimize
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma endregion
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
#pragma region boost multiprecision
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// using Bint       = boost::multiprecision::cpp_int;
// using Bfloat32   = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<32>>;
// using Bfloat1024 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;
#pragma endregion
// #define int long long
// #define endl '\n'

#pragma region TEMPLATE
// clang-format off
/* TYPE */
typedef long long ll;       typedef long double ld;
typedef pair<int, int> pii; typedef pair<ll, ll> pll;
typedef vector<pii> vpii;   typedef vector<pll> vpll;
typedef vector<int> vi;     typedef vector<ll> vl;
typedef vector<string> vst; typedef vector<bool> vb;
typedef vector<ld> vld;     typedef vector<vector<int>> vvi;
template<typename T, typename Cmp = less<>> using prique = priority_queue<T, vector<T>, Cmp>;
template<typename T> using prique_r = prique<T, greater<>>;
/* CONSTANT */
#define ln '\n'
const int INF = 1 << 30;    const ll INFF = 1LL << 60;  const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int MOD = 1e9 + 7;    const int MODD = 998244353; const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const double EPS = 1e-9;    const ld PI = 3.14159265358979323846264338327950288;
const int dx[] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };
const int dy[] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };
/* CONTAINER */
#define PB              emplace_back
#define ALL(v)          (v).begin(), (v).end()
#define RALL(v)         (v).rbegin(), (v).rend()
#define SORT(v)         sort(ALL(v))
#define RSORT(v)        sort(RALL(v))
#define LESS(x, val)    (lower_bound(x.begin(), x.end(), val) - x.begin())
#define LEQ(x, val)     (upper_bound(x.begin(), x.end(), val) - x.begin())
#define GREATER(x, val) (int)(x).size() - LEQ((x), (val))
#define GEQ(x, val)     (int)(x).size() - LESS((x), (val))
#define UNIQUE(v)       sort(ALL(v)); (v).erase(unique(ALL(v)), (v).end())
template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }
template<typename T, typename U, typename... V> enable_if_t<is_same<T, U>::value != 0> fill_v(U &u, const V... v) { u = U(v...); }
template<typename T, typename U, typename... V> enable_if_t<is_same<T, U>::value == 0> fill_v(U &u, const V... v) { for (auto &e : u) fill_v<T>(e, v...); }
/* LOOP */
#define _overload3(_1, _2, _3, name, ...) name
#define _REP(i, n)      REPI(i, 0, n)
#define REPI(i, a, b)   for (ll i = (ll)a; i < (ll)b; ++i)
#define REP(...)        _overload3(__VA_ARGS__, REPI, _REP,)(__VA_ARGS__)
#define _RREP(i, n)     RREPI(i, n, 0)
#define RREPI(i, a, b)  for (ll i = (ll)a; i >= (ll)b; --i)
#define RREP(...)       _overload3(__VA_ARGS__, RREPI, _RREP,)(__VA_ARGS__)
#define EACH(e, v)      for (auto& e : v)
#define PERM(v)         sort(ALL(v)); for (bool c##p = true; c##p; c##p = next_permutation(ALL(v)))
/* INPUT */
template<typename T> void SSS(T& t) { cin >> t; }
template<typename Head, typename... Tail> void SSS(Head&& head, Tail&&... tail) { cin >> head; SSS(tail...); }
#define SS(T, ...)      T __VA_ARGS__; SSS(__VA_ARGS__);
#define SV(T, v, n)     vector<T> v(n); for (auto& i : v) cin >> i;
#define SVV(T, v, n, m) vector<vector<T>> v(n, vector<T>(m)); for (auto& r : v) for (auto& i : r) cin >> i;
/* OUTPUT */
// Yes / No
inline int YES(bool x) { cout << (x ? "YES"  : "NO") << endl; return 0; }
inline int Yes(bool x) { cout << (x ? "Yes"  : "No") << endl; return 0; }
inline int yes(bool x) { cout << (x ? "yes"  : "no") << endl; return 0; }
inline int yES(bool x) { cout << (x ? "yES"  : "nO") << endl; return 0; }
inline int Yay(bool x) { cout << (x ? "Yay!" : ":(") << endl; return 0; }
// PROTOTYPE DECLARATION
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &j);
template<typename... T> ostream &operator<<(ostream &os, const tuple<T...> &t);
template<class C, enable_if_t<!is_same<C, string>::value, decltype(declval<const C &>().begin(), nullptr)> = nullptr> ostream& operator<<(ostream &os, const C &c);
template<typename T> ostream &operator<<(ostream &os, const stack<T> &j);
template<typename T> ostream &operator<<(ostream &os, const queue<T> &j);
template<typename T, typename C, typename Cmp> ostream &operator<<(ostream &os, const priority_queue<T, C, Cmp> &j);
// IMPLEMENTATION
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &j) { return os << '{' << j.first << ", " << j.second << '}'; }
template<size_t num = 0, typename... T> enable_if_t<num == sizeof...(T)> PRINT_TUPLE(ostream &os, const tuple<T...> &t) {}
template<size_t num = 0, typename... T> enable_if_t<num <  sizeof...(T)> PRINT_TUPLE(ostream &os, const tuple<T...> &t) { os << get<num>(t); if (num + 1 < sizeof...(T)) os << ", "; PRINT_TUPLE<num + 1>(os, t); }
template<typename... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { PRINT_TUPLE(os << '{', t); return os << '}'; }
template<class C, enable_if_t<!is_same<C, string>::value, decltype(declval<const C &>().begin(), nullptr)>> ostream& operator<<(ostream &os, const C &c) { os << '{'; for (auto it = begin(c); it != end(c); it++) { if (begin(c) != it) os << ", "; os << *it; } return os << '}'; }
template<typename T> ostream &operator<<(ostream &os, const stack<T> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_front(c.top());  return os << d; }
template<typename T> ostream &operator<<(ostream &os, const queue<T> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_back(c.front()); return os << d; }
template<typename T, typename C, typename Cmp> ostream &operator<<(ostream &os, const priority_queue<T, C, Cmp> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_front(c.top());  return os << d; }
// OUTPUT FUNCTION
template<typename T> int PV(T &v) { int sz = v.size(); for (int i = 0; i < sz; ++i) cout << v[i] << " \n"[i == sz - 1]; return 0; }
inline int print() { cout << endl; return 0; }
template<typename Head> int print(Head&& head){ cout << head; return print(); }
template<typename Head, typename... Tail> int print(Head&& head, Tail&&... tail) { cout << head << " "; return print(forward<Tail>(tail)...); }
#ifdef LOCAL
inline void dump() { cerr << endl; }
template<typename Head> void dump(Head&& head) { cerr << head; dump(); }
template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }
#define debug(...) do {cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)
#else
#define dump(...)
#define debug(...)
#endif
/* OTHER */
#define fi              first
#define se              second
#define MP              make_pair
#define MT              make_tuple
template<typename T, typename A, typename B> inline bool between(T x, A a, B b) { return ((a <= x) && (x < b)); }
template<typename A, typename B> inline bool chmax(A &a, const B &b) { if (a < b) { a = b; return true; } return false; }
template<typename A, typename B> inline bool chmin(A &a, const B &b) { if (a > b) { a = b; return true; } return false; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll POW(ll a, ll b) { ll r = 1; do { if (b & 1)  r *= a; a *= a; } while (b >>= 1); return r; }
struct abracadabra {
    abracadabra() {
        cin.tie(nullptr); ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
        cerr << fixed << setprecision(5);
    };
} ABRACADABRA;
// clang-format on
#pragma endregion
#pragma region datastructure / segmenttree / segmenttree.hpp
/**
 * @brief セグメント木
 * @docs docs/datastructure/segmenttree/segmenttree.md
 */

template <typename T, typename F>
struct SegmentTree {
    int N;
    const int sz;
    const T ID;
    const F f;
    vector<T> cbt;
    SegmentTree(int n, T ID, F func)
        : sz(n), ID(ID), f(func) { init(sz); }
    SegmentTree(vector<T> V, T ID, F func)
        : sz(V.size()), ID(ID), f(func) {
        init(sz);
        for (int i = 0; i < sz; ++i)
            cbt[i + N] = V[i];
        for (int i = N - 1; i >= 1; --i)
            cbt[i] = f(cbt[i << 1 | 0], cbt[i << 1 | 1]);
    }
    void init(int n) {
        N = 1;
        while (N < n) N <<= 1;
        cbt.assign(N << 1, ID);
    }
    void update(int idx, T val) {
        assert(0 <= idx and idx < sz);
        idx += N;
        cbt[idx] = val;
        while (idx >>= 1) cbt[idx] = f(cbt[idx << 1 | 0], cbt[idx << 1 | 1]);
    }
    T query(int l, int r) {
        assert(0 <= l and l <= r and r <= sz);
        T ret_l = ID, ret_r = ID;
        l += N, r += N;
        while (l < r) {
            if (l & 1) ret_l = f(ret_l, cbt[l++]);
            if (r & 1) ret_r = f(cbt[--r], ret_r);
            l >>= 1, r >>= 1;
        }
        return f(ret_l, ret_r);
    }
    T query_all() { return cbt[1]; }
    template <typename CF>
    int rightmost(CF check, int l = 0) {
        assert(0 <= l and l <= sz);
        assert(check(ID));
        if (l == sz) return sz;
        l += N;
        T acc = ID;
        do {
            while (l % 2 == 0) l >>= 1;
            if (not check(f(acc, cbt[l]))) {
                while (l < N) {
                    l = 2 * l;
                    if (check(f(acc, cbt[l]))) acc = f(acc, cbt[l++]);
                }
                return l - N;
            }
            acc = f(acc, cbt[l++]);
        } while ((l & -l) != l);
        return sz;
    }
    template <typename CF>
    int leftmost(CF check, int r = INT_MIN) {
        if (r == INT_MIN) r = sz;
        assert(0 <= r and r <= sz);
        assert(check(ID));
        if (r == 0) return 0;
        r += N;
        T acc = ID;
        do {
            --r;
            while (r > 1 and (r % 2)) r >>= 1;
            if (not check(f(cbt[r], acc))) {
                while (r < N) {
                    r = 2 * r + 1;
                    if (check(f(cbt[r], acc))) acc = f(cbt[r--], acc);
                }
                return r + 1 - N;
            }
            acc = f(cbt[r], acc);
        } while ((r & -r) != r);
        return 0;
    }
    T const &operator[](int idx) const { return cbt[idx + N]; }
    void print() {
        for (int i = 1; i < 2 * N; ++i) {
            cerr << cbt[i] << ' ';
            if (!(i & (i + 1))) cerr << endl;
        }
    }
};

template <typename T, typename F>
auto make_segment_tree(int N, T ID, F func) {
    return SegmentTree<T, F>(N, ID, func);
}
template <typename T, typename F>
auto make_segment_tree(vector<T> V, T ID, F func) {
    return SegmentTree<T, F>(V, ID, func);
}
#pragma endregion
#pragma region math / modint.hpp
/**
 * @brief ModInt
 * @docs docs/math/modint.md
 */

template <int MODULO>
struct ModInt {
    using i32 = int;
    using i64 = long long;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    u64 x;
    ModInt()
        : x(0) {}
    ModInt(i64 y)
        : x(set(y % MODULO + MODULO)) {}
    static u64 set(const i64 &y) { return (y < MODULO) ? y : y - MODULO; }
    ModInt operator+(const ModInt &m) const { return ModInt(set(x + m.x)); }
    ModInt operator-(const ModInt &m) const { return ModInt(set(x + MODULO - m.x)); }
    ModInt operator*(const ModInt &m) const { return ModInt(x * m.x % MODULO); }
    ModInt operator/(const ModInt &m) const { return ModInt(x) * ~ModInt(m.x); }
    ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
    ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
    ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
    ModInt &operator^=(const u64 &y) { return *this = *this ^ y; }
    ModInt operator~() const { return *this ^ (MODULO - 2); }
    ModInt operator-() const { return ModInt(set(MODULO - x)); }
    ModInt operator++() { return *this = ModInt(set(x + 1)); }
    ModInt operator--() { return *this = ModInt(set(x + MODULO - 1)); }
    bool operator<(const ModInt &m) const { return x < m.x; }
    bool operator>(const ModInt &m) const { return x > m.x; }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator u64() const { return x; }
    ModInt operator^(i64 y) const { return pow(x, y); }
    static ModInt pow(i64 x, i64 y) {
        bool neg = false;
        if (y < 0) y = -y, neg = true;
        ModInt u(1), t(x);
        while (y) {
            if (y & 1) u *= t;
            t *= t;
            y >>= 1;
        }
        return neg ? ModInt(1) / u : u;
    }
    friend ostream &operator<<(ostream &os, const ModInt<MODULO> &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt<MODULO> &m) {
        u64 y;
        is >> y;
        m = ModInt(y);
        return is;
    }
};
constexpr int MODULO = (int)1e9 + 7;
using modint = ModInt<MODULO>;
#pragma endregion

using mint = ModInt<MODD>;

int solve();

signed main() {
    // int _T; cin >> _T; for (int t = 1; t <= _T; ++t)
    solve();
}

int solve() {

    SS(int, N, M, K);

    auto seg = make_segment_tree(
        vector<mint>(M + 1, 1), mint(0), [](mint a, mint b) { return a + b; });
    seg.update(0, 0);

    REP (i, N - 1) {
        vector<mint> seg_nxt(M + 1, 0);

        REP (j, 1, M + 1) {
            // dp[i + 1][j] を更新
            if (K == 0) {
                seg_nxt[j] = seg.query_all();
            } else {
                if (j - K + 1 > 0) seg_nxt[j] = seg.query(0, j - K + 1);
                if (M + 1 > j + K) seg_nxt[j] += seg.query(j + K, M + 1);
            }
        }

        REP (j, M + 1) {
            seg.update(j, seg_nxt[j]);
        }
    }

    print(seg.query_all());

    return 0;
}
