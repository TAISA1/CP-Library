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
struct UnionFind {
    int n;
    vector<int> par, sz, tim; //tim:親が変わった時刻
    UnionFind(int n) : n(n), par(n), sz(n, 1), tim(n, -1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x, int t) {
        if (par[x] == x || tim[x] > t) return x;
        return find(par[x], t);
    }
    bool unite(int u, int v, int t) { //与えられるtは単調増加
        u = find(u, t);
        v = find(v, t);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        u = par[v];
        tim[v] = t;
        return true;
    }
    //時刻tの後に同連結成分か？
    bool same(int u, int v, int t) {
        return find(u, v) == find(v, t);
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        uf.unite(a, b, 0);
    }
    V<int> c(n), d(n);
    for (int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
        --c[i];
        --d[i];
    }
    for (int i = q - 1; i >= 0; i--) {
        uf.unite(c[i], d[i], q - i);
    }
    for (int i = 1; i < n; i++) {
        if (uf.same(0, i, 0)) {
            cout << -1 << '\n';
            continue;
        }
        //到達できるtのMAX
        int ok = 0, ng = q;
        while (ng - ok > 0) {
            int mid = (ok + ng) / 2;
            if (uf.same(0, i, mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok << '\n';
    }
}