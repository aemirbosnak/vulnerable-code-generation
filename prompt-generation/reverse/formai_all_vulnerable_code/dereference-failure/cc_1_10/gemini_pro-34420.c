//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_COLORS 4

typedef struct {
  int num_nodes;
  int num_edges;
  int **adj_matrix;
  int *colors;
} Graph;

typedef struct {
  Graph *graph;
  int start_node;
  int num_nodes_to_color;
} ColoringTask;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* color_nodes(void *arg) {
  ColoringTask *task = (ColoringTask *)arg;
  int start_node = task->start_node;
  int num_nodes_to_color = task->num_nodes_to_color;

  for (int i = start_node; i < start_node + num_nodes_to_color; i++) {
    int node = i;
    bool available_colors[NUM_COLORS] = {true};

    for (int j = 0; j < task->graph->num_nodes; j++) {
      if (task->graph->adj_matrix[node][j] == 1 && task->graph->colors[j] != -1) {
        available_colors[task->graph->colors[j]] = false;
      }
    }

    int color = -1;
    for (int c = 0; c < NUM_COLORS; c++) {
      if (available_colors[c]) {
        color = c;
        break;
      }
    }

    pthread_mutex_lock(&mutex);
    task->graph->colors[node] = color;
    pthread_mutex_unlock(&mutex);
  }

  free(task);
  pthread_exit(NULL);
}

Graph* create_graph(int num_nodes, int num_edges, int **adj_matrix) {
  Graph *graph = malloc(sizeof(Graph));
  graph->num_nodes = num_nodes;
  graph->num_edges = num_edges;
  graph->adj_matrix = adj_matrix;
  graph->colors = malloc(sizeof(int) * num_nodes);

  for (int i = 0; i < num_nodes; i++) {
    graph->colors[i] = -1;
  }

  return graph;
}

void print_graph(Graph *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    for (int j = 0; j < graph->num_nodes; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

void print_colors(Graph *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("%d ", graph->colors[i]);
  }
  printf("\n");
}

int main() {
  // Create a graph
  int num_nodes = 5;
  int num_edges = 7;
  int adj_matrix[5][5] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0}
  };

  Graph *graph = create_graph(num_nodes, num_edges, adj_matrix);

  // Create coloring tasks
  int num_tasks = 2;
  ColoringTask tasks[num_tasks];
  int nodes_per_task = num_nodes / num_tasks;

  for (int i = 0; i < num_tasks; i++) {
    tasks[i].graph = graph;
    tasks[i].start_node = i * nodes_per_task;
    tasks[i].num_nodes_to_color = nodes_per_task;
  }

  // Create threads
  pthread_t threads[num_tasks];

  for (int i = 0; i < num_tasks; i++) {
    pthread_create(&threads[i], NULL, color_nodes, (void *)&tasks[i]);
  }

  // Join threads
  for (int i = 0; i < num_tasks; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the colored graph
  print_colors(graph);

  return 0;
}