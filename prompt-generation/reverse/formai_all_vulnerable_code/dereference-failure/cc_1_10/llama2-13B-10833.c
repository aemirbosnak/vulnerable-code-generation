//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to store client and server information
typedef struct {
    int sock;
    char client_name[50];
} client_server_info_t;

// Function to create a new client or server socket
int create_socket(int domain, int type, int protocol) {
    int sock;
    sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to bind a socket to a specific address and port
void bind_socket(int sock, struct sockaddr_in server_addr) {
    int error;
    socklen_t addrlen = sizeof(server_addr);
    getsockname(sock, (struct sockaddr *)&server_addr, &addrlen);
    error = bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (error < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
}

// Function to listen for incoming connections
void listen_socket(int sock) {
    listen(sock, 3); // Listen for 3 incoming connections
}

// Function to accept an incoming connection
client_server_info_t *accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    char client_name[50];
    gets(client_name, 50, stdin);
    client_server_info_t *new_client = (client_server_info_t *)malloc(sizeof(client_server_info_t));
    new_client->sock = client_sock;
    strcpy(new_client->client_name, client_name);
    return new_client;
}

// Function to send and receive data between client and server
void send_receive(int sock, char *message) {
    send(sock, message, strlen(message), 0);
    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("%s\n", buffer);
}

// Main function
int main(int argc, char *argv[]) {
    int server_sock = create_socket(AF_INET, SOCK_STREAM, 0);
    bind_socket(server_sock, (struct sockaddr_in) {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    });
    listen_socket(server_sock);

    // Create a new client socket
    int client_sock = accept_connection(server_sock);

    // Send and receive data between client and server
    char message[] = "Hello, client!";
    send_receive(client_sock, message);

    // Close the client socket
    close(client_sock);

    // Create a new client socket
    client_sock = accept_connection(server_sock);

    // Send and receive data between client and server
    message[0] = ' ';
    send_receive(client_sock, message);

    // Close the client socket
    close(client_sock);

    // Create a new client socket
    client_sock = accept_connection(server_sock);

    // Send and receive data between client and server
    message[0] = '!';
    send_receive(client_sock, message);

    // Close the client socket
    close(client_sock);

    return 0;
}