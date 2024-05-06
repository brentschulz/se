#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
struct Edge {
    string src;
    string dest;
    int cost;
    Edge(string s, string d, int c) : src(s), dest(d), cost(c) {}
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};
class MST {
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
public:
    void makeSet(string v) {
        parent[v] = v;
        rank[v] = 0;
    }
    string findSet(string v) {
        if (v != parent[v]) {
            parent[v] = findSet(parent[v]);
        }
        return parent[v];
    }
    void unionSets(string a, string b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
    vector<Edge> kruskal(vector<Edge>& edges) {
        vector<Edge> result;
        for (const Edge& edge : edges) {
            string rootA = findSet(edge.src);
            string rootB = findSet(edge.dest);
            if (rootA != rootB) {
                result.push_back(edge);
                unionSets(rootA, rootB);
            }
        }
        return result;
    }
};
int main() {
    MST mst;
    vector<Edge> edges;
    int numOffices, numConnections;
    cout << "1. Enter the number of offices: ";
    cin >> numOffices;
    cin.ignore();
    for (int i = 0; i < numOffices; ++i) {
        string office;
        cout << "Enter the name of office " << i + 1 << ": ";
        getline(cin, office);
        mst.makeSet(office);
    }
    cout << "2. Enter the number of connections: ";
    cin >> numConnections;
    cin.ignore(); 
    cout << "3. Enter connection details (source destination cost):" << endl;
    for (int i = 0; i < numConnections; ++i) {
        string src, dest;
        int cost;
        cout << "Connection " << i + 1 << ": ";
        cin >> src >> dest >> cost;
        edges.emplace_back(src, dest, cost);
    }
    sort(edges.begin(), edges.end());
    vector<Edge> mstEdges = mst.kruskal(edges);
    int totalCost = 0;
    cout << "Minimum spanning tree edges:" << endl;
    for (const Edge& edge : mstEdges) {
        cout << edge.src << " - " << edge.dest << " : " << edge.cost << endl;
        totalCost += edge.cost;
    }
    cout << "Minimum total cost for phone lines: " << totalCost << endl;
    return 0;
}
