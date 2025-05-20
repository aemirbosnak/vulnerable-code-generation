//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT_RANGE 1024
#define MAX_HOST_LEN 100
#define BUFFER_SIZE 1024

void init_ports(int *ports, int range) {
    int i;
    for (i = 0; i < range; i++) {
        ports[i] = i + 1;
    }
}

int main() {
    int sock, port, len, client_len, i;
    struct sockaddr_in server, client;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1234);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the port range and client address buffer
    int *ports = malloc(PORT_RANGE * sizeof(int));
    char client_ip[MAX_HOST_LEN];

    init_ports(ports, PORT_RANGE);

    // Loop forever to listen for incoming connections
    while (1) {
        // Accept an incoming connection
        if ((client_len = accept(sock, (struct sockaddr *)&client, (socklen_t*)&client_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Get the client IP address and port
        getpeername(client_len, (struct sockaddr *)&client, (socklen_t*)&client_len);
        printf("Client connected from IP address %s and port %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Iterate over the port range and perform the scan
        for (i = 0; i < PORT_RANGE; i++) {
            port = ports[i];

            // Send a SYN packet to the client
            send(client_len, buffer, 1, 0);

            // Wait for the client to respond
            recv(client_len, buffer, 1, 0);

            // Check if the port is open
            if (ntohs(client.sin_port) == port) {
                printf("Port %d is open\n", port);
            } else {
                printf("Port %d is closed\n", port);
            }
        }

        // Close the connection
        close(client_len);
    }

    return 0;
}