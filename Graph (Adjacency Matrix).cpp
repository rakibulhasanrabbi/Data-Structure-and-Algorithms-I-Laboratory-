#include<bits/stdc++.h>

using namespace std;


//V represents the number of vertices in the graph. The adjacency matrix size will be 4 × 4.
#define V 4

void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}


void addEdge(int arr[][V], int i, int j) { //adds edge to an undirected graph
  arr[i][j] = 1;
  arr[j][i] = 1;
}


void printAdjMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}


int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
  addEdge(adjMatrix, 0, 1);
  addEdge(adjMatrix, 0, 2);
  addEdge(adjMatrix, 0, 3);
  addEdge(adjMatrix, 1, 2);


  printAdjMatrix(adjMatrix);

  return 0;
}
