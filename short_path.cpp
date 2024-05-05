#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Represents infinity

// Define a structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {}
};

// Function to find the shortest path from a source vertex to all other vertices using Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<Edge>>& graph, int source) {
    int V = graph.size(); // Number of vertices
    vector<int> dist(V, INF); // Tracks shortest distance from source
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<Edge>> graph(V); // Adjacency list representation of the graph

    // Add edges to the graph
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(2, 5);
    graph[1].emplace_back(2, 2);
    graph[1].emplace_back(3, 1);
    graph[2].emplace_back(1, 3);
    graph[2].emplace_back(3, 9);
    graph[2].emplace_back(4, 2);
    graph[3].emplace_back(4, 4);
    graph[4].emplace_back(0, 7);
    graph[4].emplace_back(3, 6);

    int source = 0; // Source vertex

    vector<int> shortest_distances = dijkstra(graph, source);

    // Print shortest distances from source
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}
