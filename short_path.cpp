#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

typedef pair<int, int> pii;

void greedy_shortest_path(vector<vector<pii>>& graph, int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distances(graph.size(), INF);

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();

        if (d > distances[u]) continue;

        for (auto& [v, w] : graph[u])
            if (distances[u] + w < distances[v])
                pq.push({distances[v] = distances[u] + w, v});
    }

    for (int i = 0; i < graph.size(); ++i)
        cout << "Shortest distance from node " << start << " to node " << i << ": " << (distances[i] == INF ? "INF" : to_string(distances[i])) << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n);

    for (int i = 0, u, v, w; i < m && cin >> u >> v >> w; ++i) {
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // For undirected graph
    }

    int start;
    cin >> start;
    greedy_shortest_path(graph, start);
    return 0;
}