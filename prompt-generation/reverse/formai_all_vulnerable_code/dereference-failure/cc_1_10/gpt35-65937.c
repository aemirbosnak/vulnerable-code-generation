//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Node data structure to store network device information
 */
typedef struct node {
    char name[20];
    int num_connections;
    struct node *connections[10];
} node;

/*
 * Function to create a new node
 */
node *create_node(char *name) {
    node *new_node = (node *) malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->num_connections = 0;
    return new_node;
}

/*
 * Function to create a connection between two nodes
 */
void create_connection(node *node1, node *node2) {
    if (node1->num_connections < 10 && node2->num_connections < 10) {
        node1->connections[node1->num_connections++] = node2;
        node2->connections[node2->num_connections++] = node1;
    }
}

/*
 * Function to print the network topology
 */
void print_topology(int num_nodes, node **nodes) {
    printf("=============================\n");
    printf("Network Topology\n");
    printf("=============================\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s (%d connections): ", nodes[i]->name, nodes[i]->num_connections);
        for (int j = 0; j < nodes[i]->num_connections; j++) {
            printf("%s ", nodes[i]->connections[j]->name);
        }
        printf("\n");
    }
    printf("=============================\n");
}

int main() {
    node *A = create_node("A");
    node *B = create_node("B");
    node *C = create_node("C");
    node *D = create_node("D");
    node *E = create_node("E");
    node *F = create_node("F");
    node *G = create_node("G");

    create_connection(A, B);
    create_connection(B, C);
    create_connection(C, D);
    create_connection(C, E);
    create_connection(E, F);
    create_connection(F, G);
    create_connection(G, A);

    node *nodes[7] = {A, B, C, D, E, F, G};
    int num_nodes = 7;

    print_topology(num_nodes, nodes);

    return 0;
}