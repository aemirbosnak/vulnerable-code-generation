//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold client and server information
typedef struct {
    int sock;
    char name[50];
} client_t;

// Function to create a socket
int create_socket(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to bind a socket to a port
void bind_socket(int sock, char *host, int port) {
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &serv_addr.sin_addr);
    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
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
client_t *accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    char *name = inet_ntoa(client_addr.sin_addr);
    client_t *client = malloc(sizeof(client_t));
    client->sock = client_sock;
    strcpy(client->name, name);
    return client;
}

// Function to send and receive messages between client and server
void send_message(int sock, char *message) {
    send(sock, message, strlen(message), 0);
}

char *receive_message(int sock) {
    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    return buffer;
}

int main(int argc, char *argv[]) {
    int sock_server = create_socket();
    bind_socket(sock_server, "localhost", PORT);
    listen_socket(sock_server);

    while (1) {
        client_t *client = accept_connection(sock_server);
        char *message = "Hello, client!";
        send_message(client->sock, message);
        char *response = receive_message(client->sock);
        printf("Server: %s\n", response);
        free(client);
    }
    close(sock_server);
    return 0;
}