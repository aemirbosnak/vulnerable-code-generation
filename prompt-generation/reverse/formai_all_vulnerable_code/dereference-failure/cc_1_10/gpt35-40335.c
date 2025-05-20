//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* name;
    int id;
    int num_edges;
    struct node** edges;
} Node;

typedef struct network {
    int num_nodes;
    Node** nodes;
} Network;

Node* create_node(char* name, int id) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->name = name;
    node->id = id;
    node->num_edges = 0;
    node->edges = NULL;
    return node;
}

void add_edge(Node* node1, Node* node2) {
    if(node1->edges == NULL) {
        node1->edges = (Node**) malloc(sizeof(Node*));
    } else {
        node1->edges = (Node**) realloc(node1->edges, (node1->num_edges + 1) * sizeof(Node*));
    }
    node1->edges[node1->num_edges] = node2;
    node1->num_edges++;
}

Network* create_network(int num_nodes) {
    Network* network = (Network*) malloc(sizeof(Network));
    network->num_nodes = num_nodes;
    network->nodes = (Node**) malloc(num_nodes * sizeof(Node*));
    for(int i = 0; i < num_nodes; i++) {
        char name[20];
        sprintf(name, "Node%d", i);
        network->nodes[i] = create_node(name, i);
    }
    return network;
}

void print_network(Network* network) {
    printf("Network:\n");
    for(int i = 0; i < network->num_nodes; i++) {
        printf("Node %d (%s) connects to: ", network->nodes[i]->id, network->nodes[i]->name);
        for(int j = 0; j < network->nodes[i]->num_edges; j++) {
            printf("%d ", network->nodes[i]->edges[j]->id);
        }
        printf("\n");
    }
}

int main() {
    Network* network = create_network(3);
    add_edge(network->nodes[0], network->nodes[1]);
    add_edge(network->nodes[0], network->nodes[2]);
    add_edge(network->nodes[1], network->nodes[2]);
    print_network(network);
    return 0;
}