//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Donald Knuth
#include <stdio.h>       // Standard I/O
#include <stdlib.h>      // Standard Library
#include <string.h>      // String manipulation
#include <unistd.h>      // UNIX standard functions
#include <arpa/inet.h>   // For sockaddr_in and inet_ntoa
#include <pthread.h>     // POSIX threads

#define PORT 8080        // Server port
#define MAX_CLIENTS 10   // Maximum number of clients
#define BUFFER_SIZE 256   // Buffer size for messages

// Structure to hold client information
typedef struct {
    int sockfd;
    struct sockaddr_in address;
    int addr_len;
} client_info;

// Array to hold client sockets
int client_sockets[MAX_CLIENTS];

// Function to broadcast messages to all clients
void broadcast_message(const char *message, int sender_sock) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_sock) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

// Function to handle each client connection
void *client_handler(void *arg) {
    client_info *cli = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(cli->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate received string
        printf("Client %d: %s\n", cli->sockfd, buffer);
        broadcast_message(buffer, cli->sockfd);  // Broadcast to other clients
    }

    printf("Client %d disconnected.\n", cli->sockfd);
    close(cli->sockfd);
    free(cli);
    return NULL;
}

// Main function
int main() {
    int sockfd, new_sockfd, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    pthread_t tid;

    // Initialize client sockets array
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Set socket options failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;         // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept any incoming address
    server_addr.sin_port = htons(PORT);         // Port number

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Socket listen failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept incoming connection
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
        if (new_sockfd < 0) {
            perror("Socket accept failed");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Store client socket
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_sockfd;
                break;
            }
        }

        // Create a new thread for the client
        client_info *cli = malloc(sizeof(client_info));
        cli->sockfd = new_sockfd;
        cli->address = client_addr;
        cli->addr_len = addrlen;

        if (pthread_create(&tid, NULL, client_handler, (void *)cli) != 0) {
            perror("Thread creation failed");
            close(new_sockfd);
            free(cli);
        }
    }

    // Clean up (not reached in this example)
    close(sockfd);
    return 0;
}