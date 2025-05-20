//FormAI DATASET v1.0 Category: Graph representation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int vertex_count;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->vertex_count = 0;
    
    for(int i = 0; i < MAX_VERTICES; i++) {
        for(int j = 0; j < MAX_VERTICES; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

void add_vertex(Graph* graph) {
    if(graph->vertex_count < MAX_VERTICES) {
        graph->vertex_count++;
    } else {
        printf("Max number of vertices reached\n");
    }
}

void add_edge(Graph* graph, int src, int dest, int weight) {
    if(src >= 0 && dest >= 0 && src < graph->vertex_count && dest < graph->vertex_count) {
        graph->adj_matrix[src][dest] = weight;
    }
}

void print_graph(Graph* graph) {
    printf("Vertices  ");
    for(int i = 0; i < graph->vertex_count; i++) {
        printf("%d    ", i);
    }
    printf("\n");

    for(int i = 0; i < graph->vertex_count; i++) {
        printf("    %d      ", i);
        for(int j = 0; j < graph->vertex_count; j++) {
            printf("%d     ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = create_graph();

    add_vertex(graph);
    add_vertex(graph);
    add_vertex(graph);
    add_vertex(graph);
    add_vertex(graph);

    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 20);
    add_edge(graph, 1, 2, 30);
    add_edge(graph, 2, 3, 40);
    add_edge(graph, 3, 4, 50);

    print_graph(graph);

    return 0;
}