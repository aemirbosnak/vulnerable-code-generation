//FormAI DATASET v1.0 Category: Chat server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 2048

int server_socket, client_sockets[MAX_CLIENTS], num_clients = 0;

void handle_signal(int signal) {
    printf("\nShutting down server...\n");

    // Close all client sockets
    for (int i = 0; i < num_clients; i++) {
        close(client_sockets[i]);
    }

    // Close server socket
    close(server_socket);

    exit(0);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Receive data from client
    while ((bytes_read = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
        // Broadcast message to all clients
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] != client_socket) {
                write(client_sockets[i], buffer, bytes_read);
            }
        }
    }

    // Remove client from list of active clients
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[num_clients-1];
            num_clients--;
            break;
        }
    }

    // Close client socket
    close(client_socket);
}

int main(int argc, char *argv[]) {
    int port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Parse command-line arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    // Set up signal handler
    signal(SIGINT, handle_signal);

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server started on port %d...\n", port);

    // Accept new client connections
    while (1) {
        int client_socket;

        // Wait for incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr,
                                     &client_addr_len)) == -1) {
            perror("accept");
            exit(1);
        }

        // Add client to list of active clients
        client_sockets[num_clients++] = client_socket;

        // Fork a new process to handle the client's requests
        if (fork() == 0) {
            handle_client(client_socket);
            exit(0);
        }
    }

    return 0;
}