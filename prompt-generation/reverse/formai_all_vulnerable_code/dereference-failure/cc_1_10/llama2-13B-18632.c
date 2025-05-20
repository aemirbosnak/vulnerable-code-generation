//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold client information
typedef struct {
    int sock;
    char ip[16];
    int port;
} client_t;

// Function to create a socket
client_t* create_socket(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return (client_t*) malloc(sizeof(client_t));
}

// Function to bind a socket to a specific IP and port
void bind_socket(client_t* client, char* ip, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);
    if (bind(client->sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
}

// Function to listen for incoming connections
void listen_socket(client_t* client) {
    if (listen(client->sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }
}

// Function to accept an incoming connection
client_t* accept_socket(client_t* client) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int new_sock = accept(client->sock, (struct sockaddr*) &client_addr, &client_len);
    if (new_sock < 0) {
        perror("Accepting failed");
        exit(EXIT_FAILURE);
    }
    return (client_t*) malloc(sizeof(client_t));
}

// Function to send and receive data through a socket
void send_receive_data(client_t* client, char* message) {
    send(client->sock, message, strlen(message), 0);
    char buffer[1024];
    recv(client->sock, buffer, 1024, 0);
    printf("%s\n", buffer);
}

int main(void) {
    // Create a socket
    client_t* client = create_socket();

    // Bind the socket to a specific IP and port
    bind_socket(client, "127.0.0.1", PORT);

    // Listen for incoming connections
    listen_socket(client);

    // Accept an incoming connection
    client_t* new_client = accept_socket(client);

    // Send and receive data through the socket
    char message[] = "Hello, client!";
    send_receive_data(new_client, message);

    // Close the socket
    close(new_client->sock);
    free(new_client);

    return 0;
}