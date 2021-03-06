//@docs : Docs/LowestCommonAncester.md
const int LOG = 30;
struct LCA {
    vector<vector<int>> G, par;
    vector<int> dep;
    int n, cnt;
    LCA(const int &n) : n(n), G(n), par(LOG, vector<int>(n, -1)), dep(n), cnt(0) {}
    void addedge(const int &u, const int &v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        cnt++;
        if (cnt == n - 1) {
            build();
        }
    }
    void dfs(int i, int p) {
        par[0][i] = p;
        for (auto &e : G[i]) {
            if (e == p) continue;
            dep[e] = dep[i] + 1;
            dfs(e, i);
        }
    }
    //辺追加後に自動でbuild
    void build() {
        dfs(0, -1);
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j < n; j++) {
                if (par[i - 1][j] != -1) {
                    par[i][j] = par[i - 1][par[i - 1][j]];
                }
            }
        }
    }
    int lca(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = 19; i >= 0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1) v = par[i][v];
        }
        if (u == v) return u;
        for (int i = 19; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
};