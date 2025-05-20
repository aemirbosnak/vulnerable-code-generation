//Gemma-7B DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_CLIENTS 50

typedef struct Client {
    char name[50];
    int sockfd;
    struct Client *next;
} Client;

Client *head = NULL;

void handleClient(int sockfd) {
    char msg[1024];
    Client *client = malloc(sizeof(Client));
    client->sockfd = sockfd;

    // Get client name
    recv(sockfd, client->name, 50, 0);

    // Print client name
    printf("Client: %s has joined the game.\n", client->name);

    // Send welcome message
    sprintf(msg, "Welcome, %s! You have been invited to the Round Table.", client->name);
    send(sockfd, msg, strlen(msg), 0);

    // Listen for messages from client
    while (1) {
        // Receive message
        recv(sockfd, msg, 1024, 0);

        // Print message
        printf("%s: %s\n", client->name, msg);

        // Check if client has left
        if (strcmp(msg, "Goodbye") == 0) {
            break;
        }
    }

    // Remove client from list
    Client *prev = NULL;
    Client *curr = head;
    while (curr) {
        if (curr->sockfd == sockfd) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // Close socket
    close(sockfd);
}

int main() {
    int sockfd, clientfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    int sin_size = sizeof(client_addr);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));

    // Bind the socket to a port
    server_addr.sin_port = htons(PORT);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for clients
    while (1) {
        // Accept a client connection
        clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);

        // Handle client
        handleClient(clientfd);
    }

    return 0;
}