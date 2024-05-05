#include <iostream>
#include <vector>
using namespace std;

void DFS(const vector<vector<int>>& graph, vector<bool>& visited, int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS(graph, visited, neighbor);
        }
    }
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0}, {1}, {1}};
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            DFS(graph, visited, i);
        }
    }
    return 0;
}