//Falcon-180B DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char name[20];
};

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    char *message;
    struct client clients[MAX_CLIENTS];
    int num_clients = 0;

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for connections
    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port 8080\n");

    while (1) {
        // Accept new connection
        addrlen = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addrlen);
        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        // Get client name
        message = "Enter your name: ";
        send(client_sock, message, strlen(message), 0);
        recv(client_sock, clients[num_clients].name, 20, 0);

        // Add client to list
        clients[num_clients].sock = client_sock;
        num_clients++;

        // Broadcast message to all clients
        message = "New client connected: ";
        strcat(message, clients[num_clients-1].name);
        send(server_sock, message, strlen(message), 0);
    }

    return 0;
}