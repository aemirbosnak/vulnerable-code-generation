//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    int value;
    struct Vertex *next;
} Vertex;

typedef struct Graph {
    int num_vertices;
    Vertex *vertices[MAX_VERTICES];
} Graph;

Graph *create_graph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i] = NULL;
    }
    return graph;
}

void add_vertex(Graph *graph, int value) {
    if (graph->num_vertices >= MAX_VERTICES) {
        printf("Error: Graph is full.\n");
        return;
    }
    Vertex *new_vertex = (Vertex *)malloc(sizeof(Vertex));
    new_vertex->value = value;
    new_vertex->next = NULL;
    graph->vertices[graph->num_vertices++] = new_vertex;
}

void add_edge(Graph *graph, int source, int destination) {
    if (source < 0 || source >= graph->num_vertices || destination < 0 || destination >= graph->num_vertices) {
        printf("Error: Invalid vertex.\n");
        return;
    }
    Vertex *new_edge = (Vertex *)malloc(sizeof(Vertex));
    new_edge->value = destination;
    new_edge->next = graph->vertices[source]->next;
    graph->vertices[source]->next = new_edge;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", graph->vertices[i]->value);
        Vertex *current = graph->vertices[i]->next;
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = create_graph();
    add_vertex(graph, 0);
    add_vertex(graph, 1);
    add_vertex(graph, 2);
    add_vertex(graph, 3);
    add_vertex(graph, 4);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    return 0;
}