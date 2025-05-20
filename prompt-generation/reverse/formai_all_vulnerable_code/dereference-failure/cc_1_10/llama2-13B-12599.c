//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Structure to hold client information
struct client_info {
    int sock;
    char ip_address[INET_ADDRSTRLEN];
};

// Function to create a socket
int create_socket(int domain, int type, int protocol) {
    int sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to listen for incoming connections
void listen_for_connections(int sock) {
    listen(sock, 3); // Listen for 3 incoming connections
}

// Function to accept an incoming connection
struct client_info *accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    char ip_address[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, ip_address, sizeof(ip_address));
    struct client_info *client = malloc(sizeof(struct client_info));
    client->sock = client_sock;
    strcpy(client->ip_address, ip_address);
    return client;
}

// Function to send and receive data
void send_receive_data(int sock, char *message) {
    send(sock, message, strlen(message), 0);
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Received message: %s\n", buffer);
}

int main() {
    int server_sock = create_socket(AF_INET, SOCK_STREAM, 0);
    listen_for_connections(server_sock);

    while (1) {
        struct client_info *client = accept_connection(server_sock);
        send_receive_data(client->sock, "Hello, client!");
        free(client);
    }

    return 0;
}