//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CLIENTS 50

int main(int argc, char *argv[]) {
    int sock, port, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[256];

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);

    if (port < 0 || port > PORT_RANGE) {
        printf("Invalid port number: %d\n", port);
        return 2;
    }

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 3;
    }

    // Set address and port number for the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        return 4;
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        return 5;
    }

    printf("Server listening on port %d...\n", port);

    while (1) {
        // Accept an incoming connection
        client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Connection accepted from client %s\n", inet_ntoa(client_addr.sin_addr));

        // Read data from the client
        read(client_sock, buffer, 255);

        // Print the received data
        printf("Received message from client: %s\n", buffer);

        // Send a response back to the client
        char *message = "Hello, client!";
        send(client_sock, message, strlen(message), 0);

        // Close the client socket
        close(client_sock);
    }

    return 0;
}