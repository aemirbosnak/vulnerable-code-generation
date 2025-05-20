//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

// Define a structure to hold the port scan results
typedef struct {
    int port;
    char host[100];
} scan_result;

// Function to perform the port scan
void scan_ports(int start, int end) {
    int sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    scan_result *results = (scan_result*) malloc(sizeof(scan_result) * (end - start) + 1);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(start);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    // Loop through the port range
    for (int i = start; i <= end; i++) {
        // Create a new client socket
        client_sock = accept(sock, (struct sockaddr*) &client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        // Get the client address and port
        inet_ntop(AF_INET, &client_addr.sin_addr, results->host, sizeof(results->host));
        results->port = ntohs(client_addr.sin_port);

        // Print the port scan results
        printf("Port %d open on %s\n", results->port, results->host);

        // Free the results structure
        free(results);
    }

    // Close the socket
    close(sock);
}

int main() {
    int port_range = PORT_RANGE;
    int start = 1024;
    int end = 65535;

    // Perform the port scan
    scan_ports(start, end);

    return 0;
}