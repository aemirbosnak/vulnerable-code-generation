//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

struct Client {
    char name[256];
    int sockfd;
    struct Client *next;
};

struct Client *head = NULL;

void addClient(char *name, int sockfd) {
    struct Client *newClient = malloc(sizeof(struct Client));
    strcpy(newClient->name, name);
    newClient->sockfd = sockfd;
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        head->next = newClient;
    }
}

int main() {
    int sockfd, clientSockfd;
    struct sockaddr_in serverSockaddr, clientSockaddr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    // Bind the socket to a port
    serverSockaddr.sin_family = AF_INET;
    serverSockaddr.sin_port = htons(8888);
    bind(sockfd, (struct sockaddr *)&serverSockaddr, sizeof(serverSockaddr));

    // Listen for clients
    while (1) {
        // Accept a client connection
        clientSockfd = accept(sockfd, (struct sockaddr *)&clientSockaddr, NULL);

        // Add the client to the list
        addClient("Client", clientSockfd);

        // Send a welcome message to the client
        write(clientSockfd, "Welcome to the C Network Topology Mapper!", 50);

        // Listen for messages from the client
        while (1) {
            // Receive a message from the client
            read(clientSockfd, buffer, 1024);

            // Print the message to the console
            printf("Client: %s: %s\n", head->name, buffer);

            // Send a message back to the client
            write(clientSockfd, buffer, strlen(buffer));

            // Check if the client has disconnected
            if (strcmp(buffer, "disconnect") == 0) {
                break;
            }
        }

        // Close the client connection
        close(clientSockfd);

        // Remove the client from the list
        struct Client *client = head;
        while (client) {
            if (client->sockfd == clientSockfd) {
                head = client->next;
                free(client);
                break;
            }
            client = client->next;
        }
    }

    return 0;
}