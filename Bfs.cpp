#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& graph, vector<bool>& visited, queue<int>& q) {
    if (q.empty()) return;
    int current = q.front(); q.pop();
    cout << current << " ";
    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
    BFS(graph, visited, q);
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0}, {1}, {1}};
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[0] = true; q.push(0);
    BFS(graph, visited, q);
    return 0;
}
