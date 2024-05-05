#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Define a structure for each node in the search space
struct Node {
    int x, y, f;
    Node(int x, int y, int f) : x(x), y(y), f(f) {}
};

// Define comparison function for nodes based on f value
struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        return a.f > b.f;
    }
};

// Function to calculate Manhattan distance heuristic
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// A* search function
void aStarSearch(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    priority_queue<Node, vector<Node>, CompareNodes> open;

    open.push(Node(start.first, start.second, manhattanDistance(start.first, start.second, goal.first, goal.second)));

    while (!open.empty()) {
        Node current = open.top();
        open.pop();

        if (current.x == goal.first && current.y == goal.second) {
            cout << "Goal found!" << endl;
            return;
        }

        visited[current.x][current.y] = true;

        // Possible movements: Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] != 1 && !visited[newX][newY]) {
                open.push(Node(newX, newY, manhattanDistance(newX, newY, goal.first, goal.second)));
            }
        }
    }

    cout << "Goal not reachable!" << endl;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    aStarSearch(grid, start, goal);

    return 0;
}