#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform DFS recursively
void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " "; // Print the node

    // Recur for all the adjacent nodes
    for (int adjNode : adjList[node]) {
        if (!visited[adjNode]) {
            dfs(adjNode, adjList, visited);
        }
    }
}

// Function to initialize the DFS traversal
void dfsTraversal(int n, vector<vector<int>>& adjList) {
    // Create a visited array to mark all nodes as unvisited initially
    vector<bool> visited(n, false);

    // Perform DFS traversal for all unvisited nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited);
        }
    }
}

int main() {
    int n = 5; // Number of vertices
    // Create an adjacency list for the graph
    vector<vector<int>> adjList(n);

    // Add edges to the adjacency list
    adjList[0].push_back(1);
    adjList[0].push_back(4);
    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(1);
    adjList[3].push_back(1);
    adjList[3].push_back(4);
    adjList[4].push_back(0);
    adjList[4].push_back(3);

    cout << "DFS Traversal: ";
    dfsTraversal(n, adjList);  // Start DFS traversal from all unvisited nodes

    return 0;
}
