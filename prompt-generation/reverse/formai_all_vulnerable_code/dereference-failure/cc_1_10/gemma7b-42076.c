//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_Clients 10

typedef struct Client {
    int sockfd;
    char name[20];
    struct Client* next;
} Client;

Client* head = NULL;

void handleClient(int sockfd) {
    char buf[1024];
    int len = read(sockfd, buf, 1024);
    if (len > 0) {
        printf("Client: %s said: %s\n", head->name, buf);
        write(sockfd, "Server: Received and echoed back!", len);
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
    int client_len = sizeof(client_addr);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

        // Create a new client structure
        Client* client = (Client*)malloc(sizeof(Client));
        client->sockfd = newsockfd;
        client->next = NULL;

        // Add the client to the head of the client list
        if (head == NULL) {
            head = client;
        } else {
            Client* tail = head;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = client;
        }

        // Handle the client
        handleClient(newsockfd);
    }

    return 0;
}