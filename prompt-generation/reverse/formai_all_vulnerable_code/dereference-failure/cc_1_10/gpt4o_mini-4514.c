//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    char name[50];
    struct Edge *edges;
} Vertex;

typedef struct Edge {
    Vertex *destination;
    struct Edge *next;
} Edge;

typedef struct Graph {
    Vertex vertices[MAX_VERTICES];
    int vertex_count;
} Graph;

// Function prototypes
Graph* create_graph();
void add_vertex(Graph *graph, const char *name);
void add_edge(Graph *graph, const char *from, const char *to);
void display_graph(Graph *graph);
Vertex* find_vertex(Graph *graph, const char *name);
void free_graph(Graph *graph);

int main() {
    Graph *graph = create_graph();

    // Adding vertices
    add_vertex(graph, "A");
    add_vertex(graph, "B");
    add_vertex(graph, "C");
    add_vertex(graph, "D");
    add_vertex(graph, "E");

    // Adding edges (creating a decentralized connection)
    add_edge(graph, "A", "B");
    add_edge(graph, "A", "C");
    add_edge(graph, "B", "D");
    add_edge(graph, "C", "E");
    add_edge(graph, "D", "A");
    add_edge(graph, "E", "A");

    // Display the graph
    display_graph(graph);

    // Free the graph memory
    free_graph(graph);

    return 0;
}

Graph* create_graph() {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->vertex_count = 0;
    return graph;
}

void add_vertex(Graph *graph, const char *name) {
    if (graph->vertex_count < MAX_VERTICES) {
        strcpy(graph->vertices[graph->vertex_count].name, name);
        graph->vertices[graph->vertex_count].edges = NULL;
        graph->vertex_count++;
    } else {
        printf("Vertex limit reached!\n");
    }
}

void add_edge(Graph *graph, const char *from, const char *to) {
    Vertex *src = find_vertex(graph, from);
    Vertex *dest = find_vertex(graph, to);

    if (src && dest) {
        Edge *new_edge = (Edge*)malloc(sizeof(Edge));
        new_edge->destination = dest;
        new_edge->next = src->edges;
        src->edges = new_edge;
    } else {
        printf("One or both vertices not found.\n");
    }
}

Vertex* find_vertex(Graph *graph, const char *name) {
    for (int i = 0; i < graph->vertex_count; i++) {
        if (strcmp(graph->vertices[i].name, name) == 0) {
            return &graph->vertices[i];
        }
    }
    return NULL;
}

void display_graph(Graph *graph) {
    for (int i = 0; i < graph->vertex_count; i++) {
        Vertex *vertex = &graph->vertices[i];
        printf("Vertex %s is connected to: ", vertex->name);
        Edge *edge = vertex->edges;
        while (edge) {
            printf("%s ", edge->destination->name);
            edge = edge->next;
        }
        printf("\n");
    }
}

void free_graph(Graph *graph) {
    for (int i = 0; i < graph->vertex_count; i++) {
        Edge *edge = graph->vertices[i].edges;
        while (edge) {
            Edge *temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph);
}