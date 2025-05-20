//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

// Structure to store network topology information
typedef struct network_topology {
    char *hostname;
    int port;
    struct network_topology *next;
} network_topology;

// Function to add a new node to the network topology
network_topology *add_node(char *hostname, int port) {
    network_topology *new_node = malloc(sizeof(network_topology));
    new_node->hostname = strdup(hostname);
    new_node->port = port;
    new_node->next = NULL;
    return new_node;
}

// Function to free the memory allocated for the network topology
void free_topology(network_topology *topology) {
    network_topology *current_node = topology;
    while (current_node != NULL) {
        network_topology *next_node = current_node->next;
        free(current_node->hostname);
        free(current_node);
        current_node = next_node;
    }
}

// Function to print the network topology
void print_topology(network_topology *topology) {
    network_topology *current_node = topology;
    while (current_node != NULL) {
        printf("%s:%d\n", current_node->hostname, current_node->port);
        current_node = current_node->next;
    }
}

// Function to map the network topology
network_topology *map_topology(char *seed_hostname, int seed_port) {
    // Create a new network topology
    network_topology *topology = add_node(seed_hostname, seed_port);

    // Create a socket for communication
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the seed node
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(seed_port);
    struct hostent *host = gethostbyname(seed_hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a request for the network topology
    char request[] = "GET_TOPOLOGY";
    if (send(sockfd, request, strlen(request) + 1, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the network topology
    char buffer[1024];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Parse the network topology
    char *hostname, *port;
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        hostname = token;
        token = strtok(NULL, " ");
        port = token;
        token = strtok(NULL, " ");
        topology = add_node(hostname, atoi(port));
    }

    // Close the socket
    close(sockfd);

    // Return the network topology
    return topology;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <seed_hostname> <seed_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Map the network topology
    network_topology *topology = map_topology(argv[1], atoi(argv[2]));

    // Print the network topology
    print_topology(topology);

    // Free the memory allocated for the network topology
    free_topology(topology);

    return EXIT_SUCCESS;
}