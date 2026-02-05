#include<bits/stdc++.h>

using namespace std;

int totalNodes = 100;

void addEdge(vector<vector<int>>& graph, int u, int v) { //adds undirected edge between nodes u and v
    graph[u].push_back(v);
    graph[v].push_back(u);
}


//graph[i] → list of all neighbors of node i

//vector<int> → stores connected nodes

//vector<vector<int>> → list of adjacency lists

//Example: If graph[0] = {1, 2}, then node 0 is connected to nodes 1 and 2.



void printGraph(vector<vector<int>>& graph) {
    cout << "Adjacency List:\n";
    for (int i = 0; i < graph.size(); i++) {
        if (!graph[i].empty()) { //Prints only nodes that have at least one edge.
            cout << i << ": ";
            for (int neighbor : graph[i]) { //Prints all neighbors of node i.
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph(totalNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}


