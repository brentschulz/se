#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Function to check whether the graph is connected using Breadth First Search (BFS)
bool isConnected(vector<vector<pair<int, int>>>& graph, int startNode) {
    vector<bool> visited(graph.size(), false);
    queue<int> queue;
    queue.push(startNode);
    visited[startNode] = true;

    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();

        for (auto neighbor : graph[currentNode]) {
            int neighborNode = neighbor.first;
            if (!visited[neighborNode]) {
                queue.push(neighborNode);
                visited[neighborNode] = true;
            }
        }
    }

    // Check if all nodes have been visited
    for (bool nodeVisited : visited) {
        if (!nodeVisited) {
            return false;
        }
    }

    return true;
}

int main() {
    // Map of airports or cities
    map<string, int> airports;
    airports["A"] = 0;
    airports["B"] = 1;
    airports["C"] = 2;
    airports["D"] = 3;
    airports["E"] = 4;

    // Creating an adjacency list
    vector<vector<pair<int, int>>> adjacencyList(5);

    // Adding flight paths between cities (edges in the graph)
    adjacencyList[airports["A"]].push_back({airports["B"], 1});
    adjacencyList[airports["B"]].push_back({airports["C"], 2});
    adjacencyList[airports["C"]].push_back({airports["D"], 4});
    adjacencyList[airports["D"]].push_back({airports["E"], 3});
    adjacencyList[airports["E"]].push_back({airports["A"], 5});

    // Checking whether the graph is connected or not
    bool connected = isConnected(adjacencyList, airports["A"]);

    if (connected) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}

