#include <bits/stdc++.h>

using namespace std;


//This program:

//Represents an undirected graph using an adjacency list
//Prints the adjacency list
//Performs Breadth First Search (BFS)
//Uses a queue

int totalNodes = 100;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void performBFS(vector<vector<int>>& graph, int startNode) {
    vector<bool> visited(totalNodes, false); //Prevents revisiting nodes
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode); //Start node is marked visited and enqueued

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";

        for (int neighbor : graph[currentNode]) { //Unvisited neighbors are marked visited and added to queue
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void printGraph(vector<vector<int>>& graph) { //Prints only nodes that have neighbors; skips isolated nodes
    cout << "Adjacency List:\n";
    for (int i = 0; i < graph.size(); i++) {
        if (!graph[i].empty()) {
            cout << i << ": ";
            for (int neighbor : graph[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph(totalNodes);



    addEdge(graph, 10, 30);
    addEdge(graph, 10, 20);
    addEdge(graph, 20, 40);
    addEdge(graph, 20, 50);
    addEdge(graph, 30, 60);

    printGraph(graph);

    performBFS(graph, 10);

    return 0;
}
