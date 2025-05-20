//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Custom data structure to represent a node in the network topology
typedef struct node {
    char *name;
    char *ip_address;
    struct node *next;
} node_t;

// Global linked list to store the nodes in the network topology
node_t *head = NULL;

// Function to create a new node in the network topology
node_t *create_node(char *name, char *ip_address) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->ip_address = (char *)malloc(strlen(ip_address) + 1);
    strcpy(new_node->ip_address, ip_address);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the network topology
void add_node(char *name, char *ip_address) {
    node_t *new_node = create_node(name, ip_address);
    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to print the network topology
void print_topology() {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("Name: %s, IP Address: %s\n", current_node->name, current_node->ip_address);
        current_node = current_node->next;
    }
}

// Function to free the memory allocated for the network topology
void free_topology() {
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node->name);
        free(current_node->ip_address);
        free(current_node);
        current_node = next_node;
    }
}

int main() {
    // Add some nodes to the network topology
    add_node("Node 1", "192.168.1.1");
    add_node("Node 2", "192.168.1.2");
    add_node("Node 3", "192.168.1.3");

    // Print the network topology
    print_topology();

    // Free the memory allocated for the network topology
    free_topology();

    return 0;
}