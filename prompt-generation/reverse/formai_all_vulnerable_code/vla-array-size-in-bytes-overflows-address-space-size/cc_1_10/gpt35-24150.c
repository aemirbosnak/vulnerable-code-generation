//FormAI DATASET v1.0 Category: Graph representation ; Style: random
#include<stdio.h>
#include<stdlib.h>

// struct to represent a node in the graph
struct node {
   int vertex;
   struct node* next;
};

// function to create a new node
struct node* createNode(int v) {
   struct node* newNode = malloc(sizeof(struct node));
   newNode->vertex = v;
   newNode->next = NULL;
   return newNode;
}

int main() {
   int n, i, j;
   printf("Enter number of vertices: ");
   scanf("%d", &n);
   struct node* adjacencyList[n];
   for (i = 0; i < n; i++) {
      adjacencyList[i] = NULL;
   }
   
   // add edges to the graph
   for(i = 0; i < n; i++) {
      for(j = 0; j < n; j++) {
         int x;
         printf("Enter 1 if %d has a node with %d , else 0: ", i, j);
         scanf("%d", &x);
         if(x == 1) {
            struct node* newNode = createNode(j);     
            newNode->next = adjacencyList[i]; // add the new node to the front of the adjacency list of vertex i
            adjacencyList[i] = newNode;
         }
      }
   }

   // print the adjacency list of the graph
   printf("\nAdjacency list representation of the graph:\n");
   for(i = 0; i < n; i++) {
      struct node* temp = adjacencyList[i];
      printf("Adjacency list of vertex %d: ", i);
      while(temp) {
         printf("%d -> ", temp->vertex);
         temp = temp->next;
      }
      printf("NULL\n");
   }
   return 0;
}