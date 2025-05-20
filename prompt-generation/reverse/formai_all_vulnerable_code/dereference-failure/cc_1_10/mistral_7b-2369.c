//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct vertex {
    char name[20];
    int id;
    bool visited;
    struct vertex *next;
} Vertex;

typedef struct edge {
    Vertex *from;
    Vertex *to;
    struct edge *next;
} Edge;

typedef struct graph {
    int num_vertices;
    Vertex **vertices;
} Graph;

Graph *create_graph(int num_vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->vertices = malloc(num_vertices * sizeof(Vertex *));

    for (int i = 0; i < num_vertices; i++) {
        Vertex *vertex = malloc(sizeof(Vertex));
        vertex->id = i;
        vertex->visited = false;
        strcpy(vertex->name, "V0"); // Initialize vertex name as V0
        graph->vertices[i] = vertex;
    }

    return graph;
}

void add_edge(Graph *graph, int from_vertex_id, int to_vertex_id) {
    Vertex *from_vertex = graph->vertices[from_vertex_id];
    Vertex *to_vertex = graph->vertices[to_vertex_id];

    Edge *edge = malloc(sizeof(Edge));
    edge->from = from_vertex;
    edge->to = to_vertex;

    from_vertex->next = edge;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        Vertex *vertex = graph->vertices[i];
        printf("\nVertex %d (%s):", vertex->id, vertex->name);

        Edge *edge = vertex->next;
        while (edge != NULL) {
            printf(" -> %d (%s)", edge->to->id, edge->to->name);
            edge = edge->next;
        }
    }
}

int main() {
    int num_vertices = 5;
    Graph *graph = create_graph(num_vertices);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    printf("Graph representation:\n");
    print_graph(graph);

    return 0;
}