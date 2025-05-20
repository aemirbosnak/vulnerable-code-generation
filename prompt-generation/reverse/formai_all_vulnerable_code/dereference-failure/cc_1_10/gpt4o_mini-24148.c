//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Edge {
    int destination;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int num_vertices;
    Edge* adj_list[MAX_VERTICES];
    char* names[MAX_VERTICES];
} Graph;

Graph* create_graph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adj_list[i] = NULL;
        graph->names[i] = NULL;
    }
    return graph;
}

void add_vertex(Graph* graph, int index, const char* name) {
    graph->names[index] = strdup(name);
}

void add_edge(Graph* graph, int src, int dest) {
    Edge* new_edge = malloc(sizeof(Edge));
    new_edge->destination = dest;
    new_edge->next = graph->adj_list[src];
    graph->adj_list[src] = new_edge;
}

void print_graph(Graph* graph) {
    printf("Sherlock Holmes' London: A Graph Representation of Connections:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%s connects to: ", graph->names[i]);
        Edge* edge = graph->adj_list[i];
        while (edge) {
            printf("%s ", graph->names[edge->destination]);
            edge = edge->next;
        }
        printf("\n");
    }
}

void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        Edge* edge = graph->adj_list[i];
        while (edge) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
        free(graph->names[i]);
    }
    free(graph);
}

int main() {
    printf("It was a curious case of missing jewels, and as I sat in 221B Baker Street, I decided to map the events leading to their disappearance.\n");

    Graph* london_map = create_graph(6);
    
    add_vertex(london_map, 0, "221B Baker Street");
    add_vertex(london_map, 1, "The British Museum");
    add_vertex(london_map, 2, "The Red-Headed League");
    add_vertex(london_map, 3, "St. Paul's Cathedral");
    add_vertex(london_map, 4, "Baker Street Underground Station");
    add_vertex(london_map, 5, "The Gables");

    add_edge(london_map, 0, 1); // Baker Street to British Museum
    add_edge(london_map, 0, 2); // Baker Street to Red-Headed League
    add_edge(london_map, 1, 3); // British Museum to St. Paul's Cathedral
    add_edge(london_map, 1, 4); // British Museum to Baker Street Underground Station
    add_edge(london_map, 2, 5); // Red-Headed League to The Gables
    add_edge(london_map, 3, 0); // St. Paul's Cathedral to Baker Street
    add_edge(london_map, 4, 2); // Baker Street Underground to Red-Headed League
    add_edge(london_map, 5, 1); // The Gables to British Museum

    print_graph(london_map);

    free_graph(london_map);
    printf("And thus, the intricate web of London's streets lay bare before me, each path seen through the eyes of deduction.\n");
    
    return 0;
}