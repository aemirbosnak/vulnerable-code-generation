//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NODES 100 // maximum number of nodes in the graph

// edge structure
typedef struct {
   int source;
   int destination;
} edge_t;

// adjacency list structure
typedef struct {
   int node_count;
   edge_t edges[MAX_NODES * (MAX_NODES - 1) / 2];
} adjacency_list_t;

// graph structure
typedef struct {
   adjacency_list_t* adjacency_list;
   int node_count;
} graph_t;

typedef struct {
   graph_t* graph;
   int node;
   int visited[MAX_NODES];
   pthread_mutex_t* mutex;
} thread_args_t;

// function to add edge to the graph
void add_edge(graph_t* graph, int source, int destination) {
   adjacency_list_t* adjacency_list = graph->adjacency_list;
   int node_count = adjacency_list->node_count;
   adjacency_list->edges[node_count].source = source;
   adjacency_list->edges[node_count].destination = destination;
   adjacency_list->node_count++;
}

// function to check if a node is visited
int is_visited(int node, int* visited, int visited_count) {
   int i;
   for (i = 0; i < visited_count; i++) {
      if (visited[i] == node) {
         return 1;
      }
   }
   return 0;
}

// function to traverse the graph
void traverse(graph_t* graph, int node, int* visited, int visited_count, pthread_mutex_t* mutex) {
   visited[visited_count] = node;
   visited_count++;
   
   printf("Node %d visited.\n", node);
   
   int i;
   for (i = 0; i < graph->adjacency_list->node_count; i++) {
      if (graph->adjacency_list->edges[i].source == node) {
         int destination = graph->adjacency_list->edges[i].destination;
         if (!is_visited(destination, visited, visited_count)) {
            pthread_mutex_lock(mutex);
            traverse(graph, destination, visited, visited_count, mutex);
            pthread_mutex_unlock(mutex);
         }
      }
   }
}

// function to traverse the graph in a separate thread
void* traverse_thread(void* args) {
   thread_args_t* thread_args = (thread_args_t*)args;
   graph_t* graph = thread_args->graph;
   int node = thread_args->node;
   int* visited = thread_args->visited;
   int visited_count = 0;
   pthread_mutex_t* mutex = thread_args->mutex;
   
   traverse(graph, node, visited, visited_count, mutex);
   
   pthread_exit(NULL);
}

// main function
int main() {
   graph_t graph;
   graph.adjacency_list = (adjacency_list_t*)malloc(sizeof(adjacency_list_t));
   graph.adjacency_list->node_count = 0;
   graph.node_count = 0;
   
   add_edge(&graph, 0, 1);
   add_edge(&graph, 0, 2);
   add_edge(&graph, 1, 2);
   add_edge(&graph, 2, 0);
   add_edge(&graph, 2, 3);
   add_edge(&graph, 3, 3);
   
   pthread_mutex_t mutex;
   pthread_mutex_init(&mutex, NULL);
   
   int i;
   pthread_t threads[MAX_NODES];
   thread_args_t thread_args[MAX_NODES];
   for (i = 0; i < graph.adjacency_list->node_count; i++) {
      int node = graph.adjacency_list->edges[i].source;
      thread_args[i].graph = &graph;
      thread_args[i].node = node;
      thread_args[i].mutex = &mutex;
      pthread_create(&threads[i], NULL, traverse_thread, (void*)&thread_args[i]);
   }
   
   for (i = 0; i < graph.adjacency_list->node_count; i++) {
      pthread_join(threads[i], NULL);
   }
   
   pthread_mutex_destroy(&mutex);
   
   return 0;
}