//Gemma-7B DATASET v1.0 Category: Chat server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

typedef struct Client {
    char name[256];
    int sockfd;
    struct Client* next;
} Client;

Client* head = NULL;

void handle_client(int sockfd) {
    char buf[1024];
    int len = recv(sockfd, buf, sizeof(buf), 0);
    if (len > 0) {
        printf("Client: %s said: %s\n", head->name, buf);
    } else {
        printf("Client: %s disconnected.\n", head->name);
        close(sockfd);
        Client* client = head;
        head = client->next;
        free(client);
    }
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    int port = 8080;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, NULL);
        if (newsockfd < 0) {
            perror("Error accepting client");
            continue;
        }

        // Create a new client structure
        Client* client = (Client*)malloc(sizeof(Client));
        client->sockfd = newsockfd;
        client->next = head;
        head = client;

        // Handle the client
        handle_client(newsockfd);
    }

    return 0;
}