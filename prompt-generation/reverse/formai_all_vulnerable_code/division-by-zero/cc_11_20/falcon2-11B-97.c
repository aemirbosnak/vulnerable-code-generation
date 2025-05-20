//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int numNodes, numEdges;
   printf("Enter number of nodes: ");
   scanf("%d", &numNodes);
   printf("Enter number of edges: ");
   scanf("%d", &numEdges);

   // Generate random graph
   int* graph = malloc(numNodes * sizeof(int));
   for (int i = 0; i < numNodes; i++) {
      graph[i] = 0;
   }

   for (int i = 0; i < numEdges; i++) {
      int from, to;
      srand(time(NULL));
      from = rand() % numNodes;
      to = rand() % numNodes;
      graph[from]++;
      graph[to]++;
   }

   printf("Network topology:\n");
   for (int i = 0; i < numNodes; i++) {
      printf("%d: ", i);
      for (int j = 0; j < numNodes; j++) {
         if (graph[i] > 0 && graph[j] > 0) {
            printf("%d ", j);
         }
      }
      printf("\n");
   }

   // Remove random edge and re-print graph
   srand(time(NULL));
   int edgeToRemove = rand() % numEdges;
   int from, to;
   for (int i = 0; i < numEdges; i++) {
      from = rand() % numNodes;
      to = rand() % numNodes;
      if (from!= edgeToRemove && to!= edgeToRemove) {
         graph[from]--;
         graph[to]--;
         break;
      }
   }

   printf("\n");
   printf("Removed edge: %d -> %d\n", edgeToRemove, edgeToRemove);
   printf("Network topology:\n");
   for (int i = 0; i < numNodes; i++) {
      printf("%d: ", i);
      for (int j = 0; j < numNodes; j++) {
         if (graph[i] > 0 && graph[j] > 0) {
            printf("%d ", j);
         }
      }
      printf("\n");
   }

   free(graph);
   return 0;
}