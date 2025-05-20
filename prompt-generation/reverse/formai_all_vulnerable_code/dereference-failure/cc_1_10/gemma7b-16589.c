//Gemma-7B DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Client {
    char name[256];
    int socketfd;
    struct Client* next;
} Client;

Client* client_list = NULL;

void add_client(char* name, int socketfd) {
    Client* new_client = malloc(sizeof(Client));
    strcpy(new_client->name, name);
    new_client->socketfd = socketfd;
    new_client->next = client_list;
    client_list = new_client;
}

void send_message(char* message, Client* recipient) {
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "From: %s\nTo: %s\nMessage: %s\n", client_list->name, recipient->name, message);
    write(recipient->socketfd, buffer, strlen(buffer));
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    server_addr.sin_port = htons(65535);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        add_client(inet_ntoa(client_addr.sin_addr), newsockfd);

        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        while (1) {
            memset(buffer, 0, MAX_BUFFER_SIZE);
            read(newsockfd, buffer, MAX_BUFFER_SIZE);

            if (strcmp(buffer, "quit") == 0) {
                break;
            }

            send_message(buffer, client_list);
        }

        close(newsockfd);
        printf("Client disconnected: %s\n", inet_ntoa(client_addr.sin_addr));
    }

    return 0;
}