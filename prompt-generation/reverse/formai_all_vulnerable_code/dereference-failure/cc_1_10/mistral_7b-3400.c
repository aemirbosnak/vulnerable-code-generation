//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct Node {
    char name[32];
    int id;
    bool sentient;
    struct Node *next;
    struct Edge *edges;
    int degree;
} Node;

typedef struct Edge {
    Node *dest;
    int weight;
} Edge;

Node graph[MAX_NODES];
int num_nodes = 0;
int num_edges = 0;

void add_node(char *name) {
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->id = num_nodes;
    new_node->sentient = true;
    new_node->next = NULL;
    new_node->edges = NULL;
    new_node->degree = 0;

    graph[num_nodes++] = *new_node;
}

void add_edge(int source, int dest, int weight) {
    Node *source_node = &graph[source];
    Node *dest_node = &graph[dest];

    Edge *new_edge = malloc(sizeof(Edge));
    new_edge->dest = dest_node;
    new_edge->weight = weight;

    source_node->edges = realloc(source_node->edges, sizeof(Edge) * (source_node->degree + 1));
    source_node->edges[source_node->degree++] = *new_edge;

    dest_node->degree++;
    dest_node->edges = realloc(dest_node->edges, sizeof(Edge) * (dest_node->degree + 1));
    dest_node->edges[dest_node->degree - 1].dest = &graph[source];
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s: ", graph[i].name);
        for (int j = 0; j < graph[i].degree; j++) {
            printf("(%s, %d) ", graph[i].edges[j].dest->name, graph[i].edges[j].weight);
        }
        printf("\n");
    }
}

int main() {
    add_node("Node1");
    add_node("Node2");
    add_node("Node3");
    add_node("Node4");

    add_edge(0, 1, 1);
    add_edge(0, 2, 2);
    add_edge(0, 3, 3);
    add_edge(1, 2, 4);
    add_edge(1, 3, 5);

    print_graph();

    return 0;
}