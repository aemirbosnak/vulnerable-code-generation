//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

// Data structure to represent a node in the network topology
typedef struct node {
    char *hostname;
    struct node *next;
} node_t;

// Data structure to represent the network topology
typedef struct topology {
    node_t *head;
    int num_nodes;
} topology_t;

// Function to create a new node in the network topology
node_t *create_node(char *hostname) {
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        perror("malloc");
        exit(1);
    }
    node->hostname = strdup(hostname);
    node->next = NULL;
    return node;
}

// Function to add a node to the network topology
void add_node(topology_t *topology, node_t *node) {
    if (topology->head == NULL) {
        topology->head = node;
    } else {
        node->next = topology->head;
        topology->head = node;
    }
    topology->num_nodes++;
}

// Function to print the network topology
void print_topology(topology_t *topology) {
    node_t *node = topology->head;
    while (node != NULL) {
        printf("%s\n", node->hostname);
        node = node->next;
    }
}

// Function to free the memory allocated for the network topology
void free_topology(topology_t *topology) {
    node_t *node = topology->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node->hostname);
        free(node);
        node = next;
    }
}

// Function to perform a port scan on a host
int port_scan(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return 0;
}

// Function to perform a network topology mapping
void *map_network(void *arg) {
    topology_t *topology = (topology_t *)arg;
    node_t *node = topology->head;
    int port;

    while (node != NULL) {
        for (port = 1; port <= 65535; port++) {
            if (port_scan(node->hostname, port) == 0) {
                printf("%s:%d is open\n", node->hostname, port);
            }
        }
        node = node->next;
    }

    return NULL;
}

int main(int argc, char **argv) {
    topology_t topology;
    pthread_t thread;
    int i;

    topology.head = NULL;
    topology.num_nodes = 0;

    for (i = 1; i < argc; i++) {
        node_t *node = create_node(argv[i]);
        add_node(&topology, node);
    }

    pthread_create(&thread, NULL, map_network, &topology);
    pthread_join(thread, NULL);

    free_topology(&topology);

    return 0;
}