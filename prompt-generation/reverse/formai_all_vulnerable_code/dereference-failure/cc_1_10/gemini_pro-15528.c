//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
  int num_vertices;
  int num_edges;
  int vertices[MAX_VERTICES];
  int edges[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
  int num_colors;
  int colors[MAX_COLORS];
} ColorSet;

int graph_read(Graph *graph) {
  int i, j;
  
  if (scanf("%d %d", &graph->num_vertices, &graph->num_edges) != 2) {
    return 0;
  }
  
  for (i = 0; i < graph->num_vertices; i++) {
    graph->vertices[i] = i;
  }
  
  for (i = 0; i < graph->num_edges; i++) {
    int v1, v2;
    if (scanf("%d %d", &v1, &v2) != 2) {
      return 0;
    }
    graph->edges[v1][v2] = 1;
    graph->edges[v2][v1] = 1;
  }
  
  return 1;
}

int colorset_read(ColorSet *colorset) {
  int i;
  
  if (scanf("%d", &colorset->num_colors) != 1) {
    return 0;
  }
  
  for (i = 0; i < colorset->num_colors; i++) {
    colorset->colors[i] = i;
  }
  
  return 1;
}

int graph_color(Graph *graph, ColorSet *colorset) {
  int i, j, k;
  int colorings[MAX_VERTICES];
  
  for (i = 0; i < graph->num_vertices; i++) {
    colorings[i] = -1;
  }
  
  for (i = 0; i < graph->num_vertices; i++) {
    if (colorings[i] != -1) continue;
    
    for (j = 0; j < colorset->num_colors; j++) {
      int color = colorset->colors[j];
      int valid = 1;
      
      for (k = 0; k < graph->num_vertices; k++) {
        if (graph->edges[i][k] && colorings[k] == color) {
          valid = 0;
          break;
        }
      }
      
      if (valid) {
        colorings[i] = color;
        break;
      }
    }
    
    if (colorings[i] == -1) {
      return 0;
    }
  }
  
  return 1;
}

int main() {
  Graph graph;
  ColorSet colorset;
  
  if (!graph_read(&graph)) {
    fprintf(stderr, "Error reading graph\n");
    return 1;
  }
  
  if (!colorset_read(&colorset)) {
    fprintf(stderr, "Error reading colorset\n");
    return 1;
  }
  
  if (!graph_color(&graph, &colorset)) {
    fprintf(stderr, "Error coloring graph\n");
    return 1;
  }
  
  printf("Graph colored successfully\n");
  
  return 0;
}