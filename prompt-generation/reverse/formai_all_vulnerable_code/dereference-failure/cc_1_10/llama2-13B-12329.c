//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold client information
struct client {
    int sock;    // Socket descriptor
    char name[50]; // Name of the client
};

// Function to create a socket
int create_socket(int domain, int type, int protocol) {
    int sock;
    sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to listen for incoming connections
void listen_for_connections(int sock) {
    printf("Listening for incoming connections...\n");
    listen(sock, 3);
}

// Function to accept an incoming connection
struct client *accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int new_sock;

    // Accept the incoming connection
    new_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (new_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Create a new client structure
    struct client *new_client = (struct client *)malloc(sizeof(struct client));
    new_client->sock = new_sock;

    // Print the client's IP address and port
    printf("New client connected from IP address %s port %d\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    return new_client;
}

// Function to send and receive data between client and server
void send_receive(int sock) {
    char message[100];
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    send(sock, message, strlen(message), 0);

    char buffer[100];
    recv(sock, buffer, 100, 0);
    printf("Server said: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    // Create a socket
    int sock = create_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen_for_connections(sock);

    // Accept an incoming connection
    struct client *new_client = accept_connection(sock);

    // Send and receive data
    send_receive(new_client->sock);

    // Close the socket
    close(new_client->sock);
    free(new_client);

    return 0;
}