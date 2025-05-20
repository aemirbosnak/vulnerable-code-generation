//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 5
#define MAX_NAME 50

typedef struct Vertex {
    char name[MAX_NAME];
    struct Edge *edges[MAX_VERTICES];
    int edge_count;
} Vertex;

typedef struct Edge {
    Vertex *destination;
    int weight;
} Edge;

// Graph structure
typedef struct Graph {
    Vertex *vertices[MAX_VERTICES];
    int vertex_count;
} Graph;

// Function prototypes
Graph* create_graph();
Vertex* create_vertex(const char *name);
Edge* create_edge(Vertex *destination, int weight);
void add_vertex(Graph *graph, const char *name);
void add_edge(Graph *graph, const char *source_name, const char *destination_name, int weight);
void display_graph(Graph *graph);
void free_graph(Graph *graph);

int main() {
    Graph *graph = create_graph();
    if (!graph) {
        fprintf(stderr, "Failed to create graph.\n");
        return 1;
    }

    add_vertex(graph, "A");
    add_vertex(graph, "B");
    add_vertex(graph, "C");
    add_vertex(graph, "D");
    add_vertex(graph, "E");

    add_edge(graph, "A", "B", 4);
    add_edge(graph, "A", "C", 2);
    add_edge(graph, "B", "C", 5);
    add_edge(graph, "B", "D", 10);
    add_edge(graph, "C", "D", 3);
    add_edge(graph, "D", "E", 2);
    add_edge(graph, "C", "E", 8);

    display_graph(graph);

    free_graph(graph);
    return 0;
}

// Function definitions

Graph* create_graph() {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) return NULL;
    graph->vertex_count = 0;
    return graph;
}

Vertex* create_vertex(const char *name) {
    Vertex *vertex = (Vertex*)malloc(sizeof(Vertex));
    if (!vertex) return NULL;
    strcpy(vertex->name, name);
    vertex->edge_count = 0;
    return vertex;
}

Edge* create_edge(Vertex *destination, int weight) {
    Edge *edge = (Edge*)malloc(sizeof(Edge));
    if (!edge) return NULL;
    edge->destination = destination;
    edge->weight = weight;
    return edge;
}

void add_vertex(Graph *graph, const char *name) {
    if (graph->vertex_count < MAX_VERTICES) {
        Vertex *vertex = create_vertex(name);
        graph->vertices[graph->vertex_count++] = vertex;
    } else {
        fprintf(stderr, "Cannot add more vertices; maximum reached.\n");
    }
}

void add_edge(Graph *graph, const char *source_name, const char *destination_name, int weight) {
    Vertex *source = NULL;
    Vertex *destination = NULL;

    for (int i = 0; i < graph->vertex_count; i++) {
        if (strcmp(graph->vertices[i]->name, source_name) == 0)
            source = graph->vertices[i];

        if (strcmp(graph->vertices[i]->name, destination_name) == 0)
            destination = graph->vertices[i];

        if (source && destination) break;
    }

    if (source && destination) {
        if (source->edge_count < MAX_VERTICES) {
            Edge *edge = create_edge(destination, weight);
            source->edges[source->edge_count++] = edge;
        } else {
            fprintf(stderr, "Cannot add more edges to vertex %s; maximum reached.\n", source_name);
        }
    } else {
        fprintf(stderr, "One or both vertices not found: %s, %s\n", source_name, destination_name);
    }
}

void display_graph(Graph *graph) {
    printf("Graph Representation:\n");
    for (int i = 0; i < graph->vertex_count; i++) {
        Vertex *vertex = graph->vertices[i];
        printf("%s: ", vertex->name);
        for (int j = 0; j < vertex->edge_count; j++) {
            Edge *edge = vertex->edges[j];
            printf(" -> %s (%d)", edge->destination->name, edge->weight);
        }
        printf("\n");
    }
}

void free_graph(Graph *graph) {
    for (int i = 0; i < graph->vertex_count; i++) {
        Vertex *vertex = graph->vertices[i];
        for (int j = 0; j < vertex->edge_count; j++) {
            free(vertex->edges[j]);
        }
        free(vertex);
    }
    free(graph);
}