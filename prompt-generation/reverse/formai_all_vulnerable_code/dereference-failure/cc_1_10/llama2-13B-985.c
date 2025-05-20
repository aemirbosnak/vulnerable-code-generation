//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BRAVE_PORT_RANGE 1024

struct brave_port {
    int port;
    char *host;
};

void brave_port_scan(struct brave_port *ports, int count) {
    int sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[256];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(BRAVE_PORT_RANGE);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    while (count > 0) {
        // Accept a client connection
        if ((client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            exit(1);
        }

        // Get the client IP address and port
        inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer));
        int client_port = ntohs(client_addr.sin_port);

        // Print the client information
        printf("Client connected from %s port %d\n", buffer, client_port);

        // Add the client to the list of connected ports
        ports = realloc(ports, (count + 1) * sizeof(struct brave_port));
        ports[count].port = client_port;
        ports[count].host = strdup(buffer);
        count++;

        // Close the client socket
        close(client_sock);
    }

    // Close the server socket
    close(sock);
}

int main(int argc, char *argv[]) {
    struct brave_port *ports;
    int count = 0;

    // Initialize the list of ports
    ports = malloc(BRAVE_PORT_RANGE * sizeof(struct brave_port));

    // Scan the ports
    brave_port_scan(ports, BRAVE_PORT_RANGE);

    // Print the list of connected ports
    printf("Connected ports:\n");
    for (int i = 0; i < count; i++) {
        printf("  %d: %s\n", ports[i].port, ports[i].host);
    }

    // Free the memory
    free(ports);

    return 0;
}