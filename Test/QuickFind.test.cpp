#define PROBLEM "https://yukicoder.me/problems/no/416"
#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll MOD = 998244353LL;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
#define call_from_test
#include "../DataStructure/QuickFind.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    set<P> st;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        st.insert(P(a, b));
    }
    V<int> c(q), d(q), res(n);
    for (int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
        --c[i];
        --d[i];
        st.erase(P(c[i], d[i]));
    }
    QuickFind uf(n);
    for (auto &e : st) {
        uf.unite(e.first, e.second);
    }
    for (auto &e : uf.elements(0)) {
        res[e] = -1;
    }
    for (int i = q - 1; i >= 0; i--) {
        if (uf.same(c[i], d[i])) continue;
        if (!uf.same(c[i], 0)) swap(c[i], d[i]);
        if (uf.same(c[i], 0)) {
            for (auto &e : uf.elements(d[i])) {
                res[e] = i + 1;
            }
        }
        uf.unite(c[i], d[i]);
    }
    for (int i = 1; i < n; i++) {
        cout << res[i] << '\n';
    }
}