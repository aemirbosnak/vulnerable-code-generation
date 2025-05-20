//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold the client and server information
typedef struct {
    char *name;
    int sock;
} client_info_t;

// Function to create a socket
int create_socket(int domain, int type, int protocol) {
    int sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }
    return sock;
}

// Function to listen for incoming connections
void listen_for_connections(int sock) {
    listen(sock, 3);
}

// Function to accept an incoming connection
client_info_t *accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(1);
    }
    char *client_name = inet_ntoa(client_addr.sin_addr);
    client_info_t *new_client = malloc(sizeof(client_info_t));
    new_client->name = client_name;
    new_client->sock = client_sock;
    return new_client;
}

// Function to send and receive data between the client and server
void send_receive(int sock) {
    char buffer[256];
    int bytes_sent, bytes_received;
    printf("Client: ");
    fgets(buffer, 256, stdin);
    bytes_sent = send(sock, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("send failed");
        exit(1);
    }
    bytes_received = recv(sock, buffer, 256, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        exit(1);
    }
    printf("Server: %s\n", buffer);
}

int main() {
    int server_sock = create_socket(AF_INET, SOCK_STREAM, 0);
    listen_for_connections(server_sock);
    while (1) {
        client_info_t *new_client = accept_connection(server_sock);
        send_receive(new_client->sock);
        free(new_client);
    }
    return 0;
}