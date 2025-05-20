//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    int num_connections;
    struct Node** connections;
} Node;

// Function to add a connection between two nodes
void add_connection(Node* n1, Node* n2) {
    if (n1 == NULL || n2 == NULL) {
        printf("Error: Invalid node connection.\n");
        return;
    }

    n1->connections[n1->num_connections] = n2;
    n2->connections[n2->num_connections] = n1;

    n1->num_connections++;
    n2->num_connections++;
}

// Function to create a new node
Node* create_node(char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);

    new_node->num_connections = 0;
    new_node->connections = (Node**)malloc(sizeof(Node*) * 10);

    return new_node;
}

int main() {
    Node* router_a = create_node("Router A");
    Node* switch_1 = create_node("Switch 1");
    Node* server_1 = create_node("Server 1");
    Node* switch_2 = create_node("Switch 2");
    Node* server_2 = create_node("Server 2");
    Node* router_b = create_node("Router B");

    add_connection(router_a, switch_1);
    add_connection(switch_1, server_1);
    add_connection(switch_1, switch_2);
    add_connection(switch_2, server_2);
    add_connection(switch_2, router_b);

    printf("%s connected to:\n", router_a->name);
    for (int i = 0; i < router_a->num_connections; i++) {
        printf("- %s\n", router_a->connections[i]->name);
    }

    printf("%s connected to:\n", switch_1->name);
    for (int i = 0; i < switch_1->num_connections; i++) {
        printf("- %s\n", switch_1->connections[i]->name);
    }

    printf("%s connected to:\n", server_2->name);
    for (int i = 0; i < server_2->num_connections; i++) {
        printf("- %s\n", server_2->connections[i]->name);
    }

    // Free memory
    free(router_a->connections);
    free(switch_1->connections);
    free(server_1->connections);
    free(switch_2->connections);
    free(server_2->connections);
    free(router_b->connections);

    free(router_a);
    free(switch_1);
    free(server_1);
    free(switch_2);
    free(server_2);
    free(router_b);

    return 0;
}