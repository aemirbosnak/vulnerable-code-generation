//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_NODES 100

// A node in the network topology
typedef struct node {
    char *name;
    struct node *next;
} node_t;

// The network topology
typedef struct topology {
    node_t *head;
} topology_t;

// Create a new node
node_t *create_node(char *name) {
    node_t *node = malloc(sizeof(node_t));
    node->name = strdup(name);
    node->next = NULL;
    return node;
}

// Add a node to the topology
void add_node(topology_t *topology, node_t *node) {
    if (topology->head == NULL) {
        topology->head = node;
    } else {
        node->next = topology->head;
        topology->head = node;
    }
}

// Print the topology
void print_topology(topology_t *topology) {
    node_t *node = topology->head;
    while (node != NULL) {
        printf("%s\n", node->name);
        node = node->next;
    }
}

// Free the topology
void free_topology(topology_t *topology) {
    node_t *node = topology->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node->name);
        free(node);
        node = next;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided a hostname
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname from the command line
    char *hostname = argv[1];

    // Get the IP address of the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Create a new topology
    topology_t topology;
    topology.head = NULL;

    // Add the hostname to the topology
    node_t *node = create_node(hostname);
    add_node(&topology, node);

    // Get the list of IP addresses for the hostname
    char **addr_list = host->h_addr_list;
    while (*addr_list != NULL) {
        // Convert the IP address to a string
        char *ip_addr = inet_ntoa( *(struct in_addr *)*addr_list );

        // Add the IP address to the topology
        node = create_node(ip_addr);
        add_node(&topology, node);

        // Increment the pointer to the next IP address
        addr_list++;
    }

    // Print the topology
    print_topology(&topology);

    // Free the topology
    free_topology(&topology);

    return EXIT_SUCCESS;
}