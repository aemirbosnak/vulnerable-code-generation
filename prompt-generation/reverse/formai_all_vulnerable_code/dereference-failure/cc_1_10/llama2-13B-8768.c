//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int data;
    int neighbors[MAX_EDGES];
} Node;

typedef struct edge {
    int from;
    int to;
} Edge;

Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->neighbors[0] = 0;
    return node;
}

void add_edge(Node* from, Node* to) {
    from->neighbors[from->neighbors[0]++] = to;
}

void print_graph(Node* graph[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %d\n", i, graph[i]->data);
        for (int j = 0; j < graph[i]->neighbors[0]; j++) {
            printf("  Neighbor %d: %d\n", graph[i]->neighbors[j], graph[graph[i]->neighbors[j]]->data);
        }
    }
}

int main() {
    srand(time(NULL));

    Node* graph[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        graph[i] = create_node(rand() % 10);
    }

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            add_edge(graph[i], graph[j]);
        }
    }

    print_graph(graph, MAX_NODES);

    return 0;
}