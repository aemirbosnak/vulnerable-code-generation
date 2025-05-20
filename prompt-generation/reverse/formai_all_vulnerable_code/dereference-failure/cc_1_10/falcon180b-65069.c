//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_NODES 10
#define NUM_EDGES 20

typedef struct node {
    int id;
    int degree;
    int *neighbors;
} Node;

Node *create_node(int id) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->id = id;
    node->degree = 0;
    node->neighbors = NULL;
    return node;
}

void add_edge(Node *node1, Node *node2) {
    node1->neighbors = realloc(node1->neighbors, sizeof(int) * ++node1->degree);
    node1->neighbors[node1->degree - 1] = node2->id;
    node2->neighbors = realloc(node2->neighbors, sizeof(int) * ++node2->degree);
    node2->neighbors[node2->degree - 1] = node1->id;
}

void generate_graph(Node **nodes) {
    for (int i = 0; i < NUM_NODES; i++) {
        nodes[i] = create_node(i);
    }

    for (int i = 0; i < NUM_EDGES; i++) {
        int node1_id = rand() % NUM_NODES;
        int node2_id = rand() % NUM_NODES;

        while (node1_id == node2_id) {
            node2_id = rand() % NUM_NODES;
        }

        Node *node1 = nodes[node1_id];
        Node *node2 = nodes[node2_id];

        add_edge(node1, node2);
    }
}

void print_graph(Node *node) {
    printf("Node %d:\n", node->id);
    printf("Degree: %d\n", node->degree);
    printf("Neighbors: ");
    for (int i = 0; i < node->degree; i++) {
        printf("%d ", node->neighbors[i]);
    }
    printf("\n");
}

void print_graphs(Node **nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        print_graph(nodes[i]);
    }
}

int main() {
    srand(time(NULL));

    Node **nodes = (Node **) malloc(sizeof(Node *) * NUM_NODES);
    generate_graph(nodes);
    print_graphs(nodes, NUM_NODES);

    free(nodes);
    return 0;
}