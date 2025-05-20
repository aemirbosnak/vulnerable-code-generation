//Gemma-7B DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 5000
#define MAX_BUFFER_SIZE 1024

typedef struct ClientInfo {
    char name[256];
    char email[256];
    int socket_fd;
    struct ClientInfo* next;
} ClientInfo;

ClientInfo* client_list = NULL;

void add_client(char* name, char* email) {
    ClientInfo* new_client = malloc(sizeof(ClientInfo));
    strcpy(new_client->name, name);
    strcpy(new_client->email, email);
    new_client->socket_fd = -1;
    new_client->next = client_list;
    client_list = new_client;
}

void send_message(ClientInfo* client, char* message) {
    if (client->socket_fd != -1) {
        write(client->socket_fd, message, strlen(message));
    }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];
    int port = SERVER_PORT;

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (server_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, NULL);
        if (client_fd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Get the client's name and email
        char* name = malloc(256);
        char* email = malloc(256);
        recv(client_fd, name, 256, 0);
        recv(client_fd, email, 256, 0);

        // Add the client to the list
        add_client(name, email);

        // Send a welcome message to the client
        send_message(client_list, "Welcome to the email client!");

        // Receive and send messages
        while (1) {
            char* message = malloc(MAX_BUFFER_SIZE);
            recv(client_fd, message, MAX_BUFFER_SIZE, 0);

            // Check if the message is empty
            if (strcmp(message, "") == 0) {
                break;
            }

            // Send the message to all clients
            for (ClientInfo* client = client_list; client; client = client->next) {
                if (client != client_list) {
                    send_message(client, message);
                }
            }

            free(message);
        }

        // Close the client connection
        close(client_fd);
    }

    return 0;
}