//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// A structure to represent a node in the network
typedef struct node {
    char *ip_address;  // The IP address of the node
    int port;          // The port number of the node
    struct node *next; // A pointer to the next node in the list
} node;

// A structure to represent the network topology
typedef struct network_topology {
    node *head;  // A pointer to the head of the list of nodes
    int num_nodes;  // The number of nodes in the list
} network_topology;

// A function to create a new node
node *create_node(char *ip_address, int port) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->ip_address = ip_address;
    new_node->port = port;
    new_node->next = NULL;
    return new_node;
}

// A function to add a node to the network topology
void add_node(network_topology *topology, node *new_node) {
    if (topology->head == NULL) {
        topology->head = new_node;
    } else {
        node *current_node = topology->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    topology->num_nodes++;
}

// A function to print the network topology
void print_topology(network_topology *topology) {
    node *current_node = topology->head;
    while (current_node != NULL) {
        printf("%s:%d\n", current_node->ip_address, current_node->port);
        current_node = current_node->next;
    }
}

// A function to map the network topology
void map_topology(network_topology *topology) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Could not create socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) == -1) {
        perror("Could not set socket options");
        exit(1);
    }

    // Bind the socket to the broadcast address
    struct sockaddr_in broadcast_addr;
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    broadcast_addr.sin_port = htons(54321);

    if (bind(sockfd, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr)) == -1) {
        perror("Could not bind socket");
        exit(1);
    }

    // Send a broadcast message
    char *message = "DISCOVER";
    if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr)) == -1) {
        perror("Could not send broadcast message");
        exit(1);
    }

    // Receive responses from nodes
    struct sockaddr_in sender_addr;
    socklen_t sender_addr_len = sizeof(sender_addr);
    char buffer[1024];
    while (1) {
        int recvlen = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sender_addr, &sender_addr_len);
        if (recvlen == -1) {
            perror("Could not receive response from node");
            continue;
        }

        // Parse the response message
        char *ip_address = strtok(buffer, ":");
        char *port = strtok(NULL, ":");

        // Add the node to the topology
        node *new_node = create_node(ip_address, atoi(port));
        add_node(topology, new_node);
    }

    // Close the socket
    close(sockfd);
}

int main() {
    // Create a new network topology
    network_topology *topology = (network_topology *)malloc(sizeof(network_topology));
    topology->head = NULL;
    topology->num_nodes = 0;

    // Map the network topology
    map_topology(topology);

    // Print the network topology
    print_topology(topology);

    return 0;
}