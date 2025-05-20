//GEMINI-pro DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the server's IP address and port
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

// Define the maximum number of clients that can connect
#define MAX_CLIENTS 10

// Define the maximum size of a message
#define MAX_MSG_SIZE 1024

// Function to handle client connections
void handle_client(int client_sock) {
    // Receive the message from the client
    char msg[MAX_MSG_SIZE];
    int recv_size = recv(client_sock, msg, MAX_MSG_SIZE, 0);

    // Check if the client has disconnected
    if (recv_size == 0) {
        printf("Client disconnected.\n");
        close(client_sock);
        return;
    }

    // Process the message
    printf("Received message from client: %s\n", msg);

    // Send a response to the client
    char response[] = "Hello from the server!";
    int sent_size = send(client_sock, response, strlen(response), 0);

    if (sent_size < 0) {
        perror("send");
        close(client_sock);
        return;
    }

    // Close the client socket
    close(client_sock);
}

int main() {
    // Create a server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server socket to be reusable
    int optval = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the server socket to the specified IP address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on %s:%d\n", SERVER_IP, SERVER_PORT);

    // Accept incoming connections
    while (1) {
        // Accept a new connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle the client connection in a separate thread
        int *client_sock_ptr = malloc(sizeof(int));
        *client_sock_ptr = client_sock;
        pthread_t client_thread;
        pthread_create(&client_thread, NULL, (void *)handle_client, client_sock_ptr);
    }

    // Close the server socket
    close(server_sock);

    return 0;
}