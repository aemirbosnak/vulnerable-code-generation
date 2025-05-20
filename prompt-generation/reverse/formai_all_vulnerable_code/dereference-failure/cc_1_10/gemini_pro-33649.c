//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 5000
#define MAX_CLIENTS 10
#define MAX_NAME_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

typedef struct client {
    int sockfd;
    char name[MAX_NAME_LENGTH];
} client;

client clients[MAX_CLIENTS];
int num_clients = 0;

void add_client(int sockfd, char *name) {
    if (num_clients >= MAX_CLIENTS) {
        printf("Error: Maximum number of clients reached.\n");
        return;
    }

    clients[num_clients].sockfd = sockfd;
    strncpy(clients[num_clients].name, name, MAX_NAME_LENGTH);
    num_clients++;

    printf("Client '%s' connected.\n", name);
}

void remove_client(int sockfd) {
    int i;

    for (i = 0; i < num_clients; i++) {
        if (clients[i].sockfd == sockfd) {
            break;
        }
    }

    if (i == num_clients) {
        printf("Error: Client not found.\n");
        return;
    }

    for (; i < num_clients - 1; i++) {
        clients[i] = clients[i + 1];
    }

    num_clients--;

    printf("Client '%s' disconnected.\n", clients[i].name);
}

void broadcast_message(char *message) {
    int i;

    for (i = 0; i < num_clients; i++) {
        send(clients[i].sockfd, message, strlen(message) + 1, 0);
    }
}

void handle_client(int sockfd) {
    char buffer[MAX_MESSAGE_LENGTH];
    int n;

    while ((n = recv(sockfd, buffer, MAX_MESSAGE_LENGTH, 0)) > 0) {
        buffer[n] = '\0';

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        printf("Client '%s': %s\n", clients[sockfd].name, buffer);

        broadcast_message(buffer);
    }

    remove_client(sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: socket()");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: bind()");
        return 1;
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Error: listen()");
        return 1;
    }

    printf("Server listening on port %d.\n", portno);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error: accept()");
            continue;
        }

        char name[MAX_NAME_LENGTH];
        recv(newsockfd, name, MAX_NAME_LENGTH, 0);

        add_client(newsockfd, name);

        handle_client(newsockfd);
    }

    close(sockfd);

    return 0;
}