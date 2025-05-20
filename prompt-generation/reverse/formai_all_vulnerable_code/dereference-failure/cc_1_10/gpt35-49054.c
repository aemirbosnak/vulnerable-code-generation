//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>

typedef struct Graph{
   int V;
   int E;
   int **AdjacencyMatrix;
}Graph;

void* threadFunction(void* arg){
   printf("This is a thread function\n");

   Graph* graph = (Graph*)arg;

   printf("Total number of vertices in the graph: %d\n", graph->V);
   printf("Total number of edges in the graph: %d\n", graph->E);

   int i,j;
   printf("Adjacency Matrix:\n");
   for(i=0;i<graph->V;i++){
      for(j=0;j<graph->V;j++)
         printf("%d ", graph->AdjacencyMatrix[i][j]);
      printf("\n");
   }
   return NULL;
}

int main(){

   int i,j;
   Graph graph;
   graph.V = 4;
   graph.E = 5;
   
   graph.AdjacencyMatrix = (int**)malloc(graph.V*sizeof(int*));
   for(i=0;i<graph.V;i++)
      graph.AdjacencyMatrix[i] = (int*)calloc(graph.V,sizeof(int));

   graph.AdjacencyMatrix[0][1] = 1;
   graph.AdjacencyMatrix[0][2] = 1;
   graph.AdjacencyMatrix[1][2] = 1;
   graph.AdjacencyMatrix[2][0] = 1;
   graph.AdjacencyMatrix[2][3] = 1;

   pthread_t thread;
   pthread_create(&thread,NULL,&threadFunction,&graph);
   pthread_join(thread,NULL);

   return 0;
}