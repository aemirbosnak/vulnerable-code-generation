//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
// Romeo and Juliet: A Port Scanner Tragedy

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define NUM_PORTS 65535

// Romeo's declaration
int socket_connect(char *hostname, int port);

// Juliet's declaration
void print_port_status(int port, bool is_open);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Romeo and Juliet meet in the network
    char *hostname = argv[1];

    // Loop through each port, hoping to find an open one
    for (int port = 1; port <= NUM_PORTS; ++port) {
        bool is_open = socket_connect(hostname, port);

        // Inform the world of the port's status
        print_port_status(port, is_open);
    }

    return EXIT_SUCCESS;
}

// Romeo tries to connect to Juliet on the given port
int socket_connect(char *hostname, int port) {
    struct sockaddr_in server_addr;

    // Create a socket for Romeo's love messages
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Find Juliet's IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Set up Romeo's destination address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    // Try to connect to Juliet
    int status = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // Close Romeo's socket
    close(sockfd);

    // Return true if Romeo could connect to Juliet, false otherwise
    return status == 0;
}

// Juliet reveals the status of the port to the world
void print_port_status(int port, bool is_open) {
    if (is_open) {
        printf("Port %d: Open\n", port);
    } else {
        printf("Port %d: Closed\n", port);
    }
}