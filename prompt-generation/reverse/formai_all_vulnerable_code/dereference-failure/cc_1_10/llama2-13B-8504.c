//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

// Structure to hold client and server information
typedef struct {
    int sock;
    char address[INET_ADDRSTRLEN];
} client_server_info;

// Function to create a socket
int create_socket(int domain, int type, int protocol) {
    int sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to bind a socket to a port
void bind_socket(int sock, int port) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("binding failed");
        exit(EXIT_FAILURE);
    }
}

// Function to listen for incoming connections
void listen_socket(int sock) {
    if (listen(sock, 3) < 0) {
        perror("listening failed");
        exit(EXIT_FAILURE);
    }
}

// Function to accept an incoming connection
client_server_info *accept_connection(int sock) {
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_sock = accept(sock, (struct sockaddr *)&client_address, &client_address_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    char address_string[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_address.sin_addr, address_string, sizeof(address_string));
    client_server_info *client = (client_server_info *)malloc(sizeof(client_server_info));
    client->sock = client_sock;
    strcpy(client->address, address_string);
    return client;
}

// Function to send and receive data between client and server
void send_receive(int sock, char *message) {
    send(sock, message, strlen(message), 0);
    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("Received message: %s\n", buffer);
}

int main() {
    // Create a socket
    int sock = create_socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    bind_socket(sock, PORT);

    // Listen for incoming connections
    listen_socket(sock);

    // Accept an incoming connection
    client_server_info *client = accept_connection(sock);

    // Send and receive data between client and server
    char message[] = "Hello, client!";
    send_receive(client->sock, message);

    // Close the socket
    close(client->sock);

    // Free memory
    free(client);

    return 0;
}