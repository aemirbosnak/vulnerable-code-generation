//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold client and server information
typedef struct {
    int sock;    // Socket for communication
    char *name;  // Name of the client/server
    int port;    // Port number
} client_server_t;

// Function to create a new socket
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
    listen(sock, 3);
    printf("Listening for incoming connections...\n");
}

// Function to accept an incoming connection
client_server_t *accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    char *name = inet_ntoa(client_addr.sin_addr);
    int port = ntohs(client_addr.sin_port);
    client_server_t *client = (client_server_t *)malloc(sizeof(client_server_t));
    client->sock = client_sock;
    client->name = name;
    client->port = port;
    return client;
}

// Function to send and receive data between client and server
void send_receive(int sock, char *message) {
    send(sock, message, strlen(message), 0);
    char buffer[256];
    recv(sock, buffer, 256, 0);
    printf("Received message: %s\n", buffer);
}

// Function to start the server
void start_server(int port) {
    int sock = create_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    listen_for_connections(sock);
    while (1) {
        client_server_t *client = accept_connection(sock);
        send_receive(client->sock, "Hello, client!");
        free(client);
    }
}

// Function to start the client
void start_client(int port) {
    int sock = create_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    send_receive(sock, "Hello, server!");
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int port = atoi(argv[1]);
    start_server(port);
    start_client(port);
    return 0;
}