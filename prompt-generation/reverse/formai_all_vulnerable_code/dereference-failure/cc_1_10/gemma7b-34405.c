//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_CLIENTS 10

typedef struct Client {
    char name[20];
    int sockfd;
    struct Client *next;
} Client;

Client *head = NULL;

void handleClient(int sockfd) {
    char buffer[1024];
    Client *client = malloc(sizeof(Client));

    sprintf(client->name, "Client %d", sockfd);
    client->sockfd = sockfd;
    client->next = head;
    head = client;

    printf("Client %s connected.\n", client->name);

    while (1) {
        int bytesRead = recv(sockfd, buffer, 1024, 0);

        if (bytesRead > 0) {
            printf("Client %s: %s\n", client->name, buffer);
        } else if (bytesRead == 0) {
            printf("Client %s disconnected.\n", client->name);
            break;
        } else {
            printf("Error receiving data.\n");
            break;
        }
    }

    free(client);
}

int main() {
    int listenfd, sockfd;
    struct sockaddr_in server_addr, client_addr;
    int client_len = sizeof(client_addr);

    listenfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Server listening on port 8080.\n");

    while (1) {
        sockfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_len);
        handleClient(sockfd);
    }

    return 0;
}