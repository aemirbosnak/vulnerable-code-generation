//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold client and server information
struct client_info {
    int sock;    // Socket for communication
    char name[50]; // Client name
};

// Function to create a socket
int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to bind the socket to a specific address and port
void bind_socket(int sock) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
}

// Function to listen for incoming connections
void listen_socket(int sock) {
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }
}

// Function to accept an incoming connection
struct client_info *accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    return (struct client_info *)malloc(sizeof(struct client_info));
}

// Function to send and receive data between client and server
void send_receive(int sock, char *message) {
    send(sock, message, strlen(message), 0);
    recv(sock, message, strlen(message), 0);
}

// Main function
int main(int argc, char *argv[]) {
    int sock_server, sock_client;
    struct client_info *client_info;

    // Create the server socket
    sock_server = create_socket();
    bind_socket(sock_server);
    listen_socket(sock_server);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_info = accept_connection(sock_server);

        // Print the client name and connection status
        printf("Client connected: %s\n", client_info->name);

        // Send a message to the client
        send_receive(client_info->sock, "Hello, client!");

        // Close the connection
        close(client_info->sock);
        free(client_info);
    }

    return 0;
}