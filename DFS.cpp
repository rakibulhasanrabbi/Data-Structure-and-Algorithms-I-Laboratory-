#include <bits/stdc++.h>

using namespace std;

//The program:
//Creates an undirected graph using an adjacency list
//Performs Depth First Search (DFS) starting from node 10
//Uses an explicit stack (iterative DFS)


void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void performDFS(vector<vector<int>>& graph, int startNode) {
    vector<bool> visited(graph.size(), false); //Tracks which nodes have already been visited. Prevents infinite loops in cyclic graphs
    stack<int> s; // Stack controls traversal order
    s.push(startNode);

    cout << "DFS Traversal: ";
    while (!s.empty()) { //Continues until all reachable nodes are visited
        int currentNode = s.top();
        s.pop();

        if (!visited[currentNode]) { //Marks node as visited and prints it
            visited[currentNode] = true;
            cout << currentNode << " ";

            for (int neighbor : graph[currentNode]) { //Pushes unvisited neighbors onto stack. DFS goes deep first
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> graph(100);

    addEdge(graph, 10, 30);
    addEdge(graph, 10, 20);
    addEdge(graph, 20, 40);
    addEdge(graph, 20, 50);
    addEdge(graph, 30, 60);

    performDFS(graph, 10);

    return 0;
}

