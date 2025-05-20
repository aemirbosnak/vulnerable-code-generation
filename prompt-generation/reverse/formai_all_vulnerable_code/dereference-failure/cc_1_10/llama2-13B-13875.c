//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct edge {
    int data;
    struct edge *next;
} Edge;

Node *create_graph(void) {
    Node *nodes = calloc(MAX_NODES, sizeof(Node));
    Edge *edges = calloc(MAX_EDGES, sizeof(Edge));

    srand(time(NULL));

    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i].data = i % 2 ? 10 : 20;
        nodes[i].next = NULL;
    }

    for (int i = 0; i < MAX_EDGES; i++) {
        edges[i].data = rand() % 100;
        edges[i].next = NULL;

        int node1 = rand() % MAX_NODES;
        int node2 = rand() % MAX_NODES;

        if (node1 == node2) {
            continue;
        }

        nodes[node1].next = &nodes[node2];
        edges[i].next = &edges[i];
    }

    return nodes;
}

void traverse_graph(Node *nodes) {
    for (Node *current = nodes; current != NULL; current = current->next) {
        printf("%d ", current->data);

        if (current->next != NULL) {
            traverse_graph(current->next);
        }
    }
}

int main(void) {
    Node *graph = create_graph();

    traverse_graph(graph);

    free(graph);

    return 0;
}