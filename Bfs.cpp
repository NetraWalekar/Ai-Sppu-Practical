#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& g, vector<bool>& v, queue<int>& q) {
    if (q.empty()) return;
    int c = q.front(); q.pop();
    cout << c << " ";
    for (int n : g[c]) if (!v[n]) v[n] = true, q.push(n);
    BFS(g, v, q);
}

int main() {
    vector<vector<int>> g = {{1, 2}, {0, 3, 4}, {0}, {1}, {1}};
    vector<bool> v(g.size(), false);
    queue<int> q;
    v[0] = true; q.push(0);
    BFS(g, v, q);
    return 0;
}