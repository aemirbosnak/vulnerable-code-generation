//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 100

struct connection {
    int sock;
    struct sockaddr_in addr;
    int status;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the socket address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    struct connection *connections = calloc(MAX_CONNECTIONS, sizeof(struct connection));
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        connections[i].sock = accept(sock, NULL, NULL);
        if (connections[i].sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Get the IP address and port number of the connecting client
        getsockname(connections[i].sock, (struct sockaddr *)&connections[i].addr, &connections[i].status);

        // Print the IP address and port number of the connecting client
        printf("Connection from %s on port %d\n", inet_ntoa(connections[i].addr.sin_addr), ntohs(connections[i].addr.sin_port));

        // Keep track of the connections
        connections[i].status = 1;
    }

    // Loop through the connections and print the statistics
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connections[i].status) {
            printf("Connection %d is active\n", i);
        } else {
            printf("Connection %d is inactive\n", i);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}