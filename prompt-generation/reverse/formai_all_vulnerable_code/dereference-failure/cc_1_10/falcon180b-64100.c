//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000

typedef struct {
    int id;
    char *name;
} Node;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

Node *nodes = NULL;
Edge *edges = NULL;
int num_nodes = 0;
int num_edges = 0;

void add_node(char *name) {
    Node *new_node = malloc(sizeof(Node));
    new_node->id = num_nodes++;
    new_node->name = strdup(name);
    nodes = realloc(nodes, sizeof(Node) * num_nodes);
    nodes[num_nodes - 1] = *new_node;
}

void add_edge(int source, int destination, int weight) {
    Edge *new_edge = malloc(sizeof(Edge));
    new_edge->source = source;
    new_edge->destination = destination;
    new_edge->weight = weight;
    edges = realloc(edges, sizeof(Edge) * num_edges + 1);
    edges[num_edges++] = *new_edge;
}

void generate_graph() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        char name[10];
        sprintf(name, "Node %d", i);
        add_node(name);
    }

    for (int i = 0; i < 20; i++) {
        int source = rand() % num_nodes;
        int destination = rand() % num_nodes;
        while (source == destination) {
            destination = rand() % num_nodes;
        }
        int weight = rand() % 100;
        add_edge(source, destination, weight);
    }
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s\n", nodes[i].name);
    }
}

void print_edges() {
    for (int i = 0; i < num_edges; i++) {
        printf("Edge %d: %d -> %d with weight %d\n", i, edges[i].source, edges[i].destination, edges[i].weight);
    }
}

int main() {
    generate_graph();
    print_nodes();
    print_edges();
    return 0;
}