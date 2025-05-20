//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    int num_edges;
    struct edge *edges;
} Node;

typedef struct edge {
    int from;
    int to;
    int weight;
    struct edge *next;
} Edge;

Node *nodes;
Edge *edges;

int num_nodes;
int num_edges;

void init() {
    srand(time(NULL));
    num_nodes = rand() % MAX_NODES + 1;
    num_edges = rand() % MAX_EDGES + 1;
    nodes = (Node *)malloc(num_nodes * sizeof(Node));
    edges = (Edge *)malloc(num_edges * sizeof(Edge));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].num_edges = 0;
        nodes[i].edges = NULL;
    }
    for (int i = 0; i < num_edges; i++) {
        edges[i].from = rand() % num_nodes;
        edges[i].to = rand() % num_nodes;
        edges[i].weight = rand() % 100;
        edges[i].next = NULL;
    }
}

void add_edge(int from, int to, int weight) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->from = from;
    new_edge->to = to;
    new_edge->weight = weight;
    new_edge->next = NULL;
    if (nodes[from].num_edges == 0) {
        nodes[from].edges = new_edge;
    } else {
        Edge *cur_edge = nodes[from].edges;
        while (cur_edge->next!= NULL) {
            cur_edge = cur_edge->next;
        }
        cur_edge->next = new_edge;
    }
    nodes[to].num_edges++;
    nodes[from].num_edges++;
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: ", i);
        Edge *cur_edge = nodes[i].edges;
        while (cur_edge!= NULL) {
            printf("(%d, %d, %d) ", cur_edge->from, cur_edge->to, cur_edge->weight);
            cur_edge = cur_edge->next;
        }
        printf("\n");
    }
}

int main() {
    init();
    print_graph();
    return 0;
}