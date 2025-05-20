//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10

typedef struct client_info {
    char name[255];
    int socketfd;
    struct client_info* next;
} client_info;

client_info* head = NULL;

void add_client(char* name, int socketfd) {
    client_info* new_client = malloc(sizeof(client_info));
    strcpy(new_client->name, name);
    new_client->socketfd = socketfd;
    new_client->next = NULL;

    if (head == NULL) {
        head = new_client;
    } else {
        client_info* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_client;
    }
}

int main() {
    int sockfd, newsockfd, clientfd;
    struct sockaddr_in server_addr, client_addr;
    int server_port = 8080;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, NULL);
        if (newsockfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Add the client to the list
        add_client("Client", newsockfd);

        // Send a welcome message to the client
        write(newsockfd, "Welcome to the server!", 20);

        // Receive a message from the client
        read(newsockfd, buffer, 1024);

        // Print the message to the console
        printf("Client: %s, Message: %s\n", head->name, buffer);

        // Close the client connection
        close(newsockfd);
    }

    return 0;
}