//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 5
#define MAX_MESSAGE_LENGTH 1024

// Structure to hold client connection information
struct client_info {
    int sock;
    char name[50];
};

// Function to create a new client connection
void create_client_connection(int sock) {
    struct client_info *new_client;

    new_client = (struct client_info *)malloc(sizeof(struct client_info));
    new_client->sock = sock;
    printf("New client connection from %s! \n", new_client->name);
}

// Function to send a message to all connected clients
void send_message_to_all(int sock, char *message) {
    struct client_info *client_list;
    int i;

    client_list = (struct client_info *)malloc(sizeof(struct client_info) * MAX_CLIENT_CONNECTIONS);
    for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
        client_list[i].sock = sock;
    }
    sendto(sock, message, strlen(message), 0, (struct sockaddr *)&client_list, sizeof(struct client_info));
}

// Function to handle incoming messages from clients
void handle_client_message(int sock, char *message) {
    struct client_info *client_info;

    client_info = (struct client_info *)malloc(sizeof(struct client_info));
    client_info->sock = sock;
    strcpy(client_info->name, message);
    printf("Received message from %s: %s \n", client_info->name, message);
}

int main() {
    int sock, new_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(struct sockaddr_in);
    char message[MAX_MESSAGE_LENGTH];

    // Create a listening socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1234);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept an incoming connection
    new_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (new_sock < 0) {
        perror("Error accepting connection");
        exit(1);
    }

    // Create a new client connection structure
    create_client_connection(new_sock);

    // Loop to handle incoming messages from clients
    while (1) {
        // Receive a message from a client
        recvfrom(new_sock, message, MAX_MESSAGE_LENGTH, 0, (struct sockaddr *)&client, &client_len);

        // Handle the message
        handle_client_message(new_sock, message);

        // Send a message to all connected clients
        send_message_to_all(new_sock, "Hello, all!");
    }

    // Close the listening socket
    close(sock);

    return 0;
}