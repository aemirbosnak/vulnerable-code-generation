//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int node;
    struct edge *next;
} edge;

typedef struct {
    char name[20];
    int num_edges;
    edge *edges;
} node;

void add_edge(node *n1, node *n2) {
    edge *e = (edge *)malloc(sizeof(edge));
    e->node = n2->num_edges;
    e->next = n1->edges;
    n1->edges = e;
    n2->num_edges++;
}

void print_graph(node *graph, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s: ", graph[i].name);
        edge *e = graph[i].edges;
        while (e!= NULL) {
            printf("%d ", e->node);
            e = e->next;
        }
        printf("\n");
    }
}

int main() {
    node graph[MAX_NODES];
    int num_nodes = 0;

    node *n1 = &graph[num_nodes++];
    strcpy(n1->name, "Node 1");
    n1->num_edges = 0;

    node *n2 = &graph[num_nodes++];
    strcpy(n2->name, "Node 2");
    n2->num_edges = 0;

    node *n3 = &graph[num_nodes++];
    strcpy(n3->name, "Node 3");
    n3->num_edges = 0;

    add_edge(n1, n2);
    add_edge(n2, n3);
    add_edge(n3, n1);

    printf("Graph:\n");
    print_graph(graph, num_nodes);

    return 0;
}