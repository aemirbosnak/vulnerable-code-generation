//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex_id;
    struct Node* next;
} Node;

typedef struct Graph {
    int num_vertices;
    Node** adjacency_list;
} Graph;

Graph* create_graph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = 0;
    graph->adjacency_list = NULL;
    return graph;
}

void add_vertex(Graph* graph) {
    graph->num_vertices++;
    graph->adjacency_list = realloc(graph->adjacency_list, graph->num_vertices * sizeof(Node*));
    graph->adjacency_list[graph->num_vertices - 1] = NULL;
}

void add_edge(Graph* graph, int src, int dest) {
    Node* node = malloc(sizeof(Node));
    node->vertex_id = dest;
    node->next = NULL;

    Node* prev = graph->adjacency_list[src];
    if (prev == NULL) {
        graph->adjacency_list[src] = node;
    } else {
        while (prev->next) {
            prev = prev->next;
        }
        prev->next = node;
    }
}

void traverse_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        Node* current = graph->adjacency_list[i];
        while (current) {
            printf("Vertex: %d, Edge: %d\n", i, current->vertex_id);
            current = current->next;
        }
    }
}

int main() {
    Graph* graph = create_graph();
    add_vertex(graph);
    add_vertex(graph);
    add_vertex(graph);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    traverse_graph(graph);

    return 0;
}