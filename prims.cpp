#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> g;
int prim(int s, int n) {
    int t = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<bool> v(n);
    q.push({0, s});
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (v[u]) continue;
        v[u] = true; t += w;
        for (auto& [v, w] : g[u]) {
            if (!v[u]) q.push({w, v});
        }
    }
    return t;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int u, v, w; m--; g[u].push_back({v, w}), g[v].push_back({u, w}))
        cin >> u >> v >> w;
    cout << prim(0, n) << endl;
    return 0;
}