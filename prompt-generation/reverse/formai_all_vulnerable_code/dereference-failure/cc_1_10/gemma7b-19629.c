//Gemma-7B DATASET v1.0 Category: Chat server ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10

struct client_info {
    char name[256];
    int sockfd;
    struct client_info *next;
};

typedef struct client_info ClientInfo;

ClientInfo *head = NULL;

void handle_client(int sockfd) {
    char buffer[1024];
    ClientInfo *client = malloc(sizeof(ClientInfo));

    sprintf(client->name, "Client %d", sockfd);
    client->sockfd = sockfd;

    if (head == NULL) {
        head = client;
    } else {
        client->next = head;
        head = client;
    }

    printf("Client %s connected!\n", client->name);

    while (1) {
        int bytes_read = read(sockfd, buffer, 1024);

        if (bytes_read == 0) {
            printf("Client %s disconnected.\n", client->name);
            break;
        }

        printf("Client %s: %s\n", client->name, buffer);

        write(sockfd, buffer, bytes_read);
    }

    free(client);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    int client_len = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Server listening on port 8080.\n");

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

        if (newsockfd == -1) {
            perror("Error accepting connection");
            continue;
        }

        handle_client(newsockfd);
    }

    return 0;
}