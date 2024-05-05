#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

vector<Edge> kruskalMST(vector<Edge> edges, int V) {
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });
    vector<Edge> result;
    vector<int> parent(V);
    iota(parent.begin(), parent.end(), 0);
    for (const Edge &edge : edges) {
        int src = edge.src, dest = edge.dest;
        while (parent[src] != src) src = parent[src];
        while (parent[dest] != dest) dest = parent[dest];
        if (src != dest) {
            result.push_back(edge);
            parent[src] = dest;
        }
    }
    return result;
}

int main() {
    vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    vector<Edge> mst = kruskalMST(edges, 4);
    for (const Edge &edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    return 0;
}