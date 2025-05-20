//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Structure to represent a node in the network
typedef struct node {
    char *name;
    char *ip_address;
    struct node *next;
} node;

// Structure to represent the network topology
typedef struct network {
    node *head;
    node *tail;
} network;

// Function to create a new node
node *create_node(char *name, char *ip_address) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->name = (char *) malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->ip_address = (char *) malloc(strlen(ip_address) + 1);
    strcpy(new_node->ip_address, ip_address);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the network
void add_node(network *net, node *new_node) {
    if (net->head == NULL) {
        net->head = new_node;
        net->tail = new_node;
    } else {
        net->tail->next = new_node;
        net->tail = new_node;
    }
}

// Function to print the network topology
void print_network(network *net) {
    node *current_node = net->head;
    while (current_node != NULL) {
        printf("Node: %s (%s)\n", current_node->name, current_node->ip_address);
        current_node = current_node->next;
    }
}

// Function to map the network topology
void map_network(network *net) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int broadcast_enable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast_enable, sizeof(broadcast_enable)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the broadcast address
    struct sockaddr_in broadcast_addr;
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    broadcast_addr.sin_port = htons(54321);
    if (bind(sockfd, (struct sockaddr *) &broadcast_addr, sizeof(broadcast_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Send a broadcast message
    char *broadcast_message = "Hello, I am a network mapper!";
    if (sendto(sockfd, broadcast_message, strlen(broadcast_message), 0, (struct sockaddr *) &broadcast_addr, sizeof(broadcast_addr)) == -1) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    // Receive responses from other nodes
    char buffer[1024];
    struct sockaddr_in sender_addr;
    socklen_t sender_addr_len = sizeof(sender_addr);
    while (1) {
        int num_bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &sender_addr, &sender_addr_len);
        if (num_bytes_received == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Parse the response message
        char *response_message = buffer;
        char *name = strtok(response_message, " ");
        char *ip_address = strtok(NULL, " ");

        // Create a new node and add it to the network
        node *new_node = create_node(name, ip_address);
        add_node(net, new_node);
    }

    // Close the socket
    close(sockfd);
}

int main() {
    // Create a new network
    network *net = (network *) malloc(sizeof(network));
    net->head = NULL;
    net->tail = NULL;

    // Map the network topology
    map_network(net);

    // Print the network topology
    print_network(net);

    return 0;
}