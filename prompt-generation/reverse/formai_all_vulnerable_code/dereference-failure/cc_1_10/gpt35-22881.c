//FormAI DATASET v1.0 Category: Graph representation ; Style: Alan Touring
#include <stdio.h>

int main() {
  int numVertices = 5, numEdges = 6, i, j;

  // Adjacency matrix representation
  int adjMatrix[numVertices][numVertices];

  // Initialize the matrix
  for(i = 0; i < numVertices; i++) {
    for(j = 0; j < numVertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }

  // Add the edges to the matrix
  adjMatrix[0][1] = 1;
  adjMatrix[0][3] = 1;
  adjMatrix[1][2] = 1;
  adjMatrix[2][3] = 1;
  adjMatrix[3][4] = 1;
  adjMatrix[4][1] = 1;

  // Print the matrix
  printf("Adjacency Matrix Representation:\n");
  for(i = 0; i < numVertices; i++) {
    for(j = 0; j < numVertices; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }

  // Adjacency list representation
  struct node {
    int vertex;
    struct node* next;
  };

  struct node* adjList[numVertices];

  // Initialize the list
  for(i = 0; i < numVertices; i++) {
    adjList[i] = NULL;
  }

  // Add the edges to the list
  for(i = 0; i < numEdges; i++) {
    int v1, v2;
    scanf("%d %d", &v1, &v2);

    // Create the new nodes
    struct node* newNode1 = (struct node*) malloc(sizeof(struct node));
    newNode1->vertex = v2;
    newNode1->next = adjList[v1];
    adjList[v1] = newNode1;

    struct node* newNode2 = (struct node*) malloc(sizeof(struct node));
    newNode2->vertex = v1;
    newNode2->next = adjList[v2];
    adjList[v2] = newNode2;
  }

  // Print the list
  printf("Adjacency List Representation:\n");
  for(i = 0; i < numVertices; i++) {
    struct node* currentNode = adjList[i];
    printf("Vertex %d:", i);

    while(currentNode != NULL) {
      printf(" %d", currentNode->vertex);
      currentNode = currentNode->next;
    }

    printf("\n");
  }

  return 0;
}