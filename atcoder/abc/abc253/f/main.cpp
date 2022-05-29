// URL : https://atcoder.jp/contests/abc253/tasks/abc253_f
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
#pragma region datastructure / segmenttree / lazysegmenttree.hpp
/**
 * @brief 遅延セグメント木
 * @docs docs/datastructure/segmenttree/lazysegmenttree.md
 */

template <typename M, typename OM, typename F, typename G, typename H, typename P>
struct LazySegmentTree {
    int sz;
    const M ID_M;
    const OM ID_OM;
    F f;
    G g;
    H h;
    P p;
    vector<M> dat;
    vector<OM> laz;
    LazySegmentTree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p)
        : ID_M(ID_M), ID_OM(ID_OM), f(f), g(g), h(h), p(p) { build(n); }
    LazySegmentTree(const vector<M> &v, M ID_M, OM ID_OM, F f, G g, H h, P p)
        : ID_M(ID_M), ID_OM(ID_OM), f(f), g(g), h(h), p(p) {
        int n = v.size();
        build(n);
        for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);
    }
    void build(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(2 * sz - 1, ID_M);
        laz.assign(2 * sz - 1, ID_OM);
    }
    void eval(int len, int k) {
        if (laz[k] == ID_OM) return;
        if (2 * k + 1 < 2 * sz - 1) {
            laz[2 * k + 1] = h(laz[2 * k + 1], laz[k]);
            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = ID_OM;
    }
    M update(int a, int b, OM x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return dat[k];
        if (a <= l and r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, 2 * k + 1, l, (l + r) / 2),
                          update(a, b, x, 2 * k + 2, (l + r) / 2, r));
    }
    M update(int a, int b, OM x) {
        return update(a, b, x, 0, 0, sz);
    }
    M query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return ID_M;
        if (a <= l and r <= b) return dat[k];
        M vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        M vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    M query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }
    M operator[](const int &k) {
        return query(k, k + 1);
    }
    void print() {
        for (int i = 0; i < sz; ++i) cerr << query(i, i + 1) << ' ';
        cerr << endl;
    }
};

template <typename M, typename OM, typename F, typename G, typename H, typename P>
auto make_segtree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p) {
    return LazySegmentTree<M, OM, F, G, H, P>(n, ID_M, ID_OM, f, g, h, p);
}
template <typename M, typename OM, typename F, typename G, typename H, typename P>
auto make_segtree(vector<M> v, M ID_M, OM ID_OM, F f, G g, H h, P p) {
    return LazySegmentTree<M, OM, F, G, H, P>(v, ID_M, ID_OM, f, g, h, p);
}
#pragma endregion

int solve();

signed main() {
    // int _T; cin >> _T; for (int t = 1; t <= _T; ++t)
    solve();
}

/*
    各列について、「クエリiを処理した時点でのその列の値」みたいなのを遅延セグ木で管理する
    クエリ2は独立で処理
*/

int solve() {

    SS(int, N, M, Q);

    // 順にクエリ1を処理するので、足すタイミングと引くタイミングを管理
    vector<vector<pair<int, int>>> query_1_add(M);
    vector<vector<pair<int, int>>> query_1_sub(M);

    // i行目に対するクエリ2 (index, value)
    vector<vector<pair<int, int>>> query_2(N);

    // j列目に対するクエリ3 (index, i)
    vector<vector<pair<int, int>>> query_3(M);

    vector<ll> v_ans(Q, -1);

    REP (i, Q) {
        SS(int, T);
        if (T == 1) {
            SS(int, L, R, X);
            --L, --R;
            query_1_add[L].emplace_back(i, X);
            query_1_sub[R].emplace_back(i, X);
        } else if (T == 2) {
            SS(int, I, X);
            --I;
            query_2[I].emplace_back(i, X);
        } else {
            SS(int, I, J);
            --I, --J;
            query_3[J].emplace_back(i, I);
        }
    }

    // 各列について、「クエリiを処理した時点でのその列の値」みたいなやつ
    auto f = [](ll a, ll b) -> ll {
        return a + b;
    };
    auto p = [](ll a, int b) -> ll {
        return a * b;
    };
    auto seg = make_segtree(Q, ll(0), ll(0), f, f, f, p);

    REP (j, M) {
        // query_1_add を処理
        for (auto &[i, x] : query_1_add[j]) {
            seg.update(i, Q, x);
        }

        for (auto &[i, h] : query_3[j]) {
            // query_2[h] の中で、indexがiよりも若いもののなかで一番大きいものを探す
            if (query_2[h].empty() || query_2[h][0].first > i) {
                // クエリ2がない or その時点では飛んできてない
                v_ans[i] = seg[i];
            } else {
                // そのようなものを二分探索する
                auto itr = lower_bound(query_2[h].begin(), query_2[h].end(), make_pair(i, 0));
                --itr;
                int I = itr->first;
                int X = itr->second;

                ll res = X;
                res += seg[i];
                res -= seg[I];
                v_ans[i] = res;
            }
        }

        // query_1_sub を処理
        for (auto &[i, x] : query_1_sub[j]) {
            seg.update(i, Q, -x);
        }
    }

    REP (i, Q) {
        if (v_ans[i] == -1) continue;
        print(v_ans[i]);
    }

    return 0;
}
