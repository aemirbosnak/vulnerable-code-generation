//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200

typedef struct {
    int vertex;
    int weight;
    struct adj_list_node* next;
} AdjListNode;

typedef struct {
    int num_vertices;
    int num_edges;
    AdjListNode** adj_list;
} Graph;

void init_graph(Graph* graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_list = (AdjListNode**)malloc(num_vertices * sizeof(AdjListNode*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }
}

void add_edge(Graph* graph, int from, int to, int weight) {
    AdjListNode* new_node = (AdjListNode*)malloc(sizeof(AdjListNode));
    new_node->vertex = to;
    new_node->weight = weight;
    new_node->next = graph->adj_list[from];
    graph->adj_list[from] = new_node;
    graph->num_edges++;
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        AdjListNode* node = graph->adj_list[i];
        while (node!= NULL) {
            printf("(%d, %d) ", node->vertex, node->weight);
            node = node->next;
        }
        printf("\n");
    }
}

void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        AdjListNode* node = graph->adj_list[i];
        while (node!= NULL) {
            AdjListNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph->adj_list);
}

int main() {
    Graph graph;
    init_graph(&graph, 5);
    add_edge(&graph, 0, 1, 5);
    add_edge(&graph, 1, 2, 7);
    add_edge(&graph, 2, 3, 10);
    add_edge(&graph, 2, 4, 15);
    add_edge(&graph, 3, 4, 20);
    print_graph(&graph);
    free_graph(&graph);
    return 0;
}