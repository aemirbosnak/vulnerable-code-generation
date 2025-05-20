//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct vertex {
   char label;
   int visited;
};

int main() {
   // create graph
   int n = 6;
   struct vertex* vertices = (struct vertex*)malloc(n * sizeof(struct vertex));
   for(int i = 0; i < n; i++) {
      vertices[i].label = 'A' + i;
      vertices[i].visited = 0;
   }

   int** adjMatrix = (int**)malloc(n * sizeof(int*));
   for(int i = 0; i < n; i++) {
      adjMatrix[i] = (int*)malloc(n * sizeof(int));
      for(int j = 0; j < n; j++) {
         adjMatrix[i][j] = 0;
      }
   }

   // add edges
   adjMatrix[0][1] = 1;
   adjMatrix[0][2] = 1;
   adjMatrix[1][3] = 1;
   adjMatrix[1][4] = 1;
   adjMatrix[2][4] = 1;
   adjMatrix[3][5] = 1;
   adjMatrix[4][5] = 1;

   // print graph
   printf("Vertices: ");
   for(int i = 0; i < n; i++) {
      printf("%c ", vertices[i].label);
   }
   printf("\n");

   printf("Adjacency Matrix:\n");
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         printf("%d ", adjMatrix[i][j]);
      }
      printf("\n");
   }

   return 0;
}