#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source;
    int destination;
    int cost;
};

struct UnionFind {
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return find(parent[x]);
    }

    void unite(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        parent[parentX] = parentY;
    };
};

int findMinSpanningTreeCost(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
    });

    UnionFind uf(n);
    int totalCost = 0;
    int connectedEdges = 0;

    for (const auto& edge : edges) {
        if (uf.find(edge.source) != uf.find(edge.destination)) {
            totalCost += edge.cost;
            uf.unite(edge.source, edge.destination);
            connectedEdges++;
            if (connectedEdges == n - 1)
                break;
        }
    }

    return totalCost;
}

int main() {
    int choice;
    int numOffices, numConnections;
    vector<Edge> edges;

    while (true) {
        cout << "\n --\n";
        cout << "Menu:" << endl;
        cout << "1. Enter number of offices" << endl;
        cout << "2. Enter number of connections" << endl;
        cout << "3. Add connection details" << endl;
        cout << "4. Calculate minimum total cost" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << endl;
                cout << "Enter the number of offices: ";
                cin >> numOffices;
                break;
            case 2:
                cout << endl;
                cout << "Enter the number of connections: ";
                cin >> numConnections;
                edges.resize(numConnections);
                break;
            case 3:
                for (int i = 0; i < numConnections; i++) {
                    cout << "Enter details for connection " << i + 1 << "\n";
                    cout << "Source office: ";
                    cin >> edges[i].source;
                    cout << "Destination office: ";
                    cin >> edges[i].destination;
                    cout << "Cost: ";
                    cin >> edges[i].cost;
                }
                break;
            case 4:
                if (numOffices == 0 || numConnections == 0) {
                    cout << "Please enter the number of offices and connections first!" << endl;
                } else {
                    int totalCost = findMinSpanningTreeCost(edges, numOffices);
                    cout << "Minimum total cost to connect all offices: " << totalCost << endl;
                }
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}


