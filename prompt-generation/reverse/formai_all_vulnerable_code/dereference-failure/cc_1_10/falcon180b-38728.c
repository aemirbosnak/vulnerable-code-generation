//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct graph {
    Node* nodes[MAX_NODES];
    int num_nodes;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_nodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->nodes[i] = NULL;
    }
    return graph;
}

void add_node(Graph* graph, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    graph->nodes[graph->num_nodes++] = new_node;
}

void add_edge(Graph* graph, int node1, int node2) {
    Node* curr_node = graph->nodes[node1];
    while (curr_node->next!= NULL) {
        curr_node = curr_node->next;
    }
    curr_node->next = graph->nodes[node2];
}

void print_graph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        Node* curr_node = graph->nodes[i];
        printf("Node %d: ", i);
        while (curr_node!= NULL) {
            printf("%d ", curr_node->data);
            curr_node = curr_node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = create_graph();
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    print_graph(graph);
    return 0;
}