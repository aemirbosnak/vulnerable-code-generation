//FormAI DATASET v1.0 Category: Chat server ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5

int clients[MAX_CLIENTS];
int num_clients = 0;

char *get_client_name(struct sockaddr_in client_addr) {
    char *ip = inet_ntoa(client_addr.sin_addr);
    char *name = malloc(strlen(ip) + 6);
    sprintf(name, "%s:%d", ip, client_addr.sin_port);
    return name;
}

void broadcast(char *msg, int sender_fd) {
    for (int i = 0; i < num_clients; i++) {
        int client_fd = clients[i];
        if (client_fd != sender_fd) {
            send(client_fd, msg, strlen(msg), 0);
        }
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Add client to list
        clients[num_clients++] = new_socket;

        // Get the client's name
        char *name = get_client_name(address);

        // Send welcome message to client
        char msg[100];
        sprintf(msg, "Welcome to the chat, %s!\n", name);
        send(new_socket, msg, strlen(msg), 0);

        // Notify other clients of new client
        sprintf(msg, "%s has joined the chat.\n", name);
        broadcast(msg, new_socket);

        // Receive messages from the new client
        while (1) {
            char buffer[1024] = {0};
            int bytes_read = recv(new_socket, buffer, 1024, 0);
            if (bytes_read <= 0) {
                // Client has disconnected
                break;
            }
            sprintf(msg, "%s: %s", name, buffer);
            broadcast(msg, new_socket);
        }

        // Remove the client from the list
        for (int i = 0; i < num_clients; i++) {
            if (clients[i] == new_socket) {
                clients[i] = clients[num_clients-1];
                num_clients--;
            }
        }

        // Notify other clients of disconnect
        sprintf(msg, "%s has left the chat.\n", name);
        broadcast(msg, new_socket);

        // Free memory used for name
        free(name);

        // Close the socket
        close(new_socket);
    }

    return 0;
}