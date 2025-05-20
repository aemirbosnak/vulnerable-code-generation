//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int id;
    struct Node *next;
} Node;

typedef struct Topology {
    Node *head;
    int node_count;
} Topology;

// Function prototypes
void initialize_topology(Topology *topology);
void add_node(Topology *topology, const char *name);
void display_topology(const Topology *topology);
void free_topology(Topology *topology);
void remove_node(Topology *topology, int node_id);
Node *find_node(Topology *topology, int node_id);

int main() {
    Topology network;
    initialize_topology(&network);

    // Adding nodes to the network
    add_node(&network, "Router1");
    add_node(&network, "Switch1");
    add_node(&network, "Server1");
    add_node(&network, "PC1");
    add_node(&network, "PC2");
    
    // Display current topology
    printf("Current Network Topology:\n");
    display_topology(&network);
    
    // Remove a node
    printf("\nRemoving node with ID 2 (Switch1):\n");
    remove_node(&network, 2);
    
    // Display topology after removal
    printf("Updated Network Topology:\n");
    display_topology(&network);
    
    // Free allocated memory
    free_topology(&network);

    return 0;
}

void initialize_topology(Topology *topology) {
    topology->head = NULL;
    topology->node_count = 0;
}

void add_node(Topology *topology, const char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->name, name);
    new_node->id = topology->node_count++;
    new_node->next = topology->head; // Insert at the beginning
    topology->head = new_node;
    printf("Added node: %s with ID: %d\n", new_node->name, new_node->id);
}

void display_topology(const Topology *topology) {
    Node *current = topology->head;
    while (current != NULL) {
        printf("Node ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

void free_topology(Topology *topology) {
    Node *current = topology->head;
    Node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    topology->head = NULL; // Avoid dangling pointer
    topology->node_count = 0;
}

void remove_node(Topology *topology, int node_id) {
    Node *current = topology->head;
    Node *previous = NULL;

    while (current != NULL && current->id != node_id) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Node with ID %d not found!\n", node_id);
        return;
    }
    
    if (previous == NULL) {
        // Removing the first node
        topology->head = current->next;
    } else {
        // Bypass the current node
        previous->next = current->next;
    }
    
    printf("Removed node: %s with ID: %d\n", current->name, current->id);
    free(current);
}