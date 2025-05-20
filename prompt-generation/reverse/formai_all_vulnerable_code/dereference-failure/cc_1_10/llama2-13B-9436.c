//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Structure to hold the client and server information
typedef struct {
    int sock;
    char address[INET_ADDRSTRLEN];
} client_server_info_t;

// Function to create a socket
client_server_info_t *create_socket(int domain, int type, int protocol) {
    int sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }
    return (client_server_info_t *) malloc(sizeof(client_server_info_t));
    ((client_server_info_t *) sock)->sock = sock;
    return sock;
}

// Function to bind the socket to a specific address and port
void bind_socket(client_server_info_t *sock, int port) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    if (bind(sock->sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("binding failed");
        exit(1);
    }
}

// Function to listen for incoming connections
void listen_socket(client_server_info_t *sock) {
    if (listen(sock->sock, 3) < 0) {
        perror("listening failed");
        exit(1);
    }
}

// Function to accept an incoming connection
client_server_info_t *accept_socket(client_server_info_t *sock) {
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_sock = accept(sock->sock, (struct sockaddr *) &client_address, &client_address_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(1);
    }
    return (client_server_info_t *) malloc(sizeof(client_server_info_t));
    ((client_server_info_t *) client_sock)->sock = client_sock;
    return client_sock;
}

// Function to send and receive data using the socket
void send_receive_data(client_server_info_t *sock) {
    char buffer[BUFFER_SIZE];
    int bytes_sent = send(sock->sock, "Hello, client!", 13, 0);
    if (bytes_sent < 0) {
        perror("sending failed");
        exit(1);
    }
    printf("Server: Sent %d bytes\n", bytes_sent);

    char client_message[BUFFER_SIZE];
    int bytes_received = recv(sock->sock, client_message, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("receiving failed");
        exit(1);
    }
    printf("Server: Received %d bytes: %s\n", bytes_received, client_message);
}

int main() {
    // Create a socket
    client_server_info_t *sock = create_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == NULL) {
        perror("socket creation failed");
        exit(1);
    }

    // Bind the socket to a specific address and port
    bind_socket(sock, PORT);

    // Listen for incoming connections
    listen_socket(sock);

    // Accept an incoming connection
    client_server_info_t *client_sock = accept_socket(sock);
    if (client_sock == NULL) {
        perror("accept failed");
        exit(1);
    }

    // Send and receive data using the socket
    send_receive_data(client_sock);

    // Close the socket
    close(client_sock->sock);
    free(client_sock);
    return 0;
}