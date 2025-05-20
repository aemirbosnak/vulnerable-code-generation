//Gemma-7B DATASET v1.0 Category: Chat server ; Style: modular
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10

// Define the server structure
typedef struct Client {
    int sockfd;
    char name[255];
    struct Client* next;
} Client;

Client* head = NULL;

void handle_client(int sockfd) {
    // Allocate memory for the client structure
    Client* client = malloc(sizeof(Client));
    client->sockfd = sockfd;
    client->next = NULL;

    // Add the client to the head of the list
    if (head == NULL) {
        head = client;
    } else {
        Client* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = client;
    }

    // Send a welcome message to the client
    char message[] = "Welcome to the C Chat server!";
    send(sockfd, message, sizeof(message), 0);

    // Listen for messages from the client
    char buffer[255];
    while (1) {
        // Receive a message from the client
        int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);

        // Check if the client has disconnected
        if (bytes_received == 0) {
            // Remove the client from the list
            Client* client_to_remove = head;
            while (client_to_remove) {
                if (client_to_remove->sockfd == sockfd) {
                    head = client_to_remove->next;
                    free(client_to_remove);
                    break;
                }
                client_to_remove = client_to_remove->next;
            }
            break;
        }

        // Broadcast the message to the other clients
        for (Client* client = head; client; client->next) {
            if (client->sockfd != sockfd) {
                send(client->sockfd, buffer, bytes_received, 0);
            }
        }
    }

    // Free the client structure
    free(client);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    // Bind the socket to a port
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

    // Listen for clients
    int client_sockfd;
    while (1) {
        // Accept a client connection
        client_sockfd = accept(sockfd, NULL, NULL);

        // Handle the client
        handle_client(client_sockfd);
    }

    return 0;
}