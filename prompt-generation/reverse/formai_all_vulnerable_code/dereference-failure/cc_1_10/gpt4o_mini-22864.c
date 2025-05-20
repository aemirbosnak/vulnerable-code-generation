//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NODES 15
#define MAX_CONNECTIONS 5

typedef struct Node {
    int id;
    char name[20];
    struct Node* connections[MAX_CONNECTIONS];
    int connection_count;
} Node;

Node* create_node(int id, const char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    node->id = id;
    strncpy(node->name, name, sizeof(node->name) - 1);
    node->name[sizeof(node->name) - 1] = '\0'; // Ensure null-termination
    node->connection_count = 0;
    return node;
}

void connect_nodes(Node* a, Node* b) {
    if (a->connection_count < MAX_CONNECTIONS &&
        b->connection_count < MAX_CONNECTIONS) {
        a->connections[a->connection_count++] = b;
        b->connections[b->connection_count++] = a; // Bidirectional connection
    }
}

void print_network(Node* nodes[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Node %d: %s\n", nodes[i]->id, nodes[i]->name);
        printf("Connections: ");
        for (int j = 0; j < nodes[i]->connection_count; j++) {
            printf("%s ", nodes[i]->connections[j]->name);
        }
        printf("\n\n");
    }
}

void free_network(Node* nodes[], int count) {
    for (int i = 0; i < count; i++) {
        free(nodes[i]);
    }
}

int main() {
    srand(time(NULL));

    Node* nodes[MAX_NODES];
    int node_count = MAX_NODES;

    for (int i = 0; i < node_count; i++) {
        char name[20];
        sprintf(name, "Node_%d", i + 1);
        nodes[i] = create_node(i + 1, name);
    }
    
    for (int i = 0; i < node_count; i++) {
        int connections_to_make = rand() % MAX_CONNECTIONS + 1; // Random connections
        for (int j = 0; j < connections_to_make; j++) {
            int target_index = rand() % node_count;
            if (target_index != i) {
                connect_nodes(nodes[i], nodes[target_index]);
            }
        }
    }

    print_network(nodes, node_count);
    
    free_network(nodes, node_count);
    return 0;
}