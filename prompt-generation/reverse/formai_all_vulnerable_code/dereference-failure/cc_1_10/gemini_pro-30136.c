//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

// Maximum length of the message
#define MAX_MSG_LEN 1024

// Port number
#define PORT 5000

// Sherlock Holmes's famous line
#define SHERLOCK_LINE "Elementary, my dear Watson."

// Function to handle client requests
void handle_client(int client_socket) {
    // Buffer to store the received message
    char msg[MAX_MSG_LEN];

    // Receive the message from the client
    int recv_len = recv(client_socket, msg, MAX_MSG_LEN, 0);
    if (recv_len <= 0) {
        perror("Error receiving message from client");
        close(client_socket);
        return;
    }

    // Print the received message
    printf("Client: %s\n", msg);

    // Send Sherlock Holmes's famous line to the client
    int send_len = send(client_socket, SHERLOCK_LINE, strlen(SHERLOCK_LINE), 0);
    if (send_len <= 0) {
        perror("Error sending message to client");
        close(client_socket);
        return;
    }

    // Close the client socket
    close(client_socket);
}

int main() {
    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        return 1;
    }

    // Set the server socket to be reusable
    int optval = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("Error setting server socket to be reusable");
        close(server_socket);
        return 1;
    }

    // Bind the server socket to the port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket to port");
        close(server_socket);
        return 1;
    }

    // Listen for client connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for client connections");
        close(server_socket);
        return 1;
    }

    printf("Sherlock Holmes server is listening on port %d\n", PORT);

    // Accept client connections and handle them
    while (1) {
        // Accept a client connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Handle the client request in a separate thread
        int *arg = malloc(sizeof(int));
        *arg = client_socket;
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *) handle_client, arg) != 0) {
            perror("Error creating thread to handle client request");
            close(client_socket);
            continue;
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}