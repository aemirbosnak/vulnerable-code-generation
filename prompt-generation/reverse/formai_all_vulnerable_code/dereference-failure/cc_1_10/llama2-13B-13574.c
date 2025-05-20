//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold client and server information
struct client_server {
    int sock;  // Socket for communication
    char name[50]; // Name of the client/server
    char message[100]; // Message to be sent/received
};

// Function to create a socket
int create_socket(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to listen for incoming connections
void listen_for_connections(int sock) {
    listen(sock, 3); // Listen for 3 incoming connections
    printf("Listening for incoming connections...\n");
}

// Function to accept an incoming connection
struct client_server *accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int new_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (new_sock < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    printf("Accepted connection from client...\n");
    struct client_server *new_client = (struct client_server *)malloc(sizeof(struct client_server));
    new_client->sock = new_sock;
    new_client->name[0] = '\0';
    return new_client;
}

// Function to send and receive messages
void send_receive_messages(int sock) {
    char message[100];
    printf("Enter a message to send: ");
    fgets(message, 100, stdin);
    send(sock, message, strlen(message), 0);
    char *message_received = malloc(100);
    recv(sock, message_received, 100, 0);
    printf("Received message: %s\n", message_received);
    free(message_received);
}

// Function to start the server
void start_server(int sock) {
    listen_for_connections(sock);
    struct client_server *client;
    while (1) {
        client = accept_connection(sock);
        send_receive_messages(client->sock);
        free(client);
    }
}

int main(void) {
    int sock = create_socket();
    start_server(sock);
    return 0;
}