//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int node;
    int distance;
} Node;

typedef struct graph {
    int num_nodes;
    int num_edges;
    Node* nodes;
} Graph;

void initialize_graph(Graph* graph, int num_nodes, int num_edges) {
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->nodes = (Node*)malloc(num_nodes * sizeof(Node));
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].node = i;
        graph->nodes[i].distance = -1;
    }
}

void add_edge(Graph* graph, int from, int to, int weight) {
    graph->nodes[from].distance = weight;
    graph->nodes[to].distance = weight;
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->nodes[i].distance);
        }
        printf("\n");
    }
}

void print_shortest_paths(Graph* graph, int start, int end) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (i == start) {
            printf("%d: ", i);
        }
        else {
            printf("%d,", i);
        }
        if (i == end) {
            printf("0\n");
        }
        else {
            printf("%d\n", graph->nodes[i].distance);
        }
    }
}

int main() {
    int num_nodes = 5;
    int num_edges = 6;
    Graph graph;
    initialize_graph(&graph, num_nodes, num_edges);
    add_edge(&graph, 0, 1, 1);
    add_edge(&graph, 0, 2, 3);
    add_edge(&graph, 1, 2, 2);
    add_edge(&graph, 1, 3, 4);
    add_edge(&graph, 2, 3, 5);
    add_edge(&graph, 3, 4, 6);
    print_graph(&graph);
    print_shortest_paths(&graph, 0, 4);
    return 0;
}