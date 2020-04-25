---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Test/SparseTable.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/SparseTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 20:12:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SparseTable.cpp.html">DataStructure/SparseTable.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
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
constexpr ll INF = (1LL << 60) - 1LL;
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
#include "../DataStructure/SparseTable.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SparseTable<ll> st(n, INF);
    st.build(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.get(l, r) << '\n';
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/SparseTable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
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
constexpr ll INF = (1LL << 60) - 1LL;
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
#line 1 "DataStructure/SparseTable.cpp"
const int LOG = 30;
template <class T>
struct SparseTable {
    int n;
    vector<vector<T>> dat;
    vector<int> lg, p;
    SparseTable(const int &n, const T &e) : n(n), lg(n + 1), p(LOG) {
        dat.resize(LOG, vector<T>(n, e));
        for (int i = 1; i <= n; i++) {
            lg[i] = 31 - __builtin_clz(i);
        }
        p[0] = 1;
        for (int i = 1; i < LOG; i++) {
            p[i] = p[i - 1] * 2;
        }
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            dat[0][i] = a[i];
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 0; j < n; j++) {
                if (j + p[i - 1] >= n) continue;
                dat[i][j] = min(dat[i - 1][j], dat[i - 1][j + p[i - 1]]);
            }
        }
    }
    T get(const int &l, const int &r) { //0-indexed [l,r)
        return min(dat[lg[r - l]][l], dat[lg[r - l]][r - p[lg[r - l]]]);
    }
};
#line 28 "Test/SparseTable.test.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SparseTable<ll> st(n, INF);
    st.build(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.get(l, r) << '\n';
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
