//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: modular
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
    char ip_addr[INET_ADDRSTRLEN];
    char username[50];
} client_t;

// Function to create a socket
int create_socket(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to bind a socket to a port
void bind_socket(int sock, char* ip_addr, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = htons(port);
    if (bind(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
}

// Function to listen for incoming connections
void listen_socket(int sock) {
    if (listen(sock, 3) < 0) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }
}

// Function to accept an incoming connection
client_t* accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr*) &client_addr, &client_len);
    if (client_sock < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    char* ip_addr = inet_ntoa(client_addr.sin_addr);
    printf("Connection accepted from IP address: %s\n", ip_addr);
    return (client_t*) malloc(sizeof(client_t));
}

// Function to handle incoming client data
void handle_client_data(client_t* client) {
    char buffer[1024];
    int bytes_received = recv(client->sock, buffer, 1024, 0);
    if (bytes_received < 0) {
        perror("Error receiving data from client");
        exit(EXIT_FAILURE);
    }
    printf("Received message from client: %s\n", buffer);
}

// Function to send data to a client
void send_data_to_client(int sock, char* message) {
    int bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("Error sending data to client");
        exit(EXIT_FAILURE);
    }
    printf("Sent message to client: %s\n", message);
}

int main(void) {
    // Create a socket
    int sock = create_socket();
    if (sock < 0) {
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    char* ip_addr = "127.0.0.1";
    int port = PORT;
    bind_socket(sock, ip_addr, port);

    // Listen for incoming connections
    listen_socket(sock);

    // Accept an incoming connection
    client_t* client = accept_connection(sock);

    // Handle incoming client data
    handle_client_data(client);

    // Send data to the client
    char* message = "Hello, client!";
    send_data_to_client(client->sock, message);

    // Close the socket
    close(sock);

    return 0;
}