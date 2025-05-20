//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char name[MAX_MSG_SIZE];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void *client_handler(void *arg) {
    client_t *client = (client_t *)arg;
    char msg[MAX_MSG_SIZE];
    int len;

    while ((len = recv(client->sockfd, msg, MAX_MSG_SIZE, 0)) > 0) {
        msg[len] = '\0';
        printf("%s: %s\n", client->name, msg);

        for (int i = 0; i < num_clients; i++) {
            if (clients[i].sockfd != client->sockfd) {
                send(clients[i].sockfd, msg, len, 0);
            }
        }
    }

    close(client->sockfd);
    num_clients--;
    pthread_exit(NULL);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    pthread_t tid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9000);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, MAX_CLIENTS);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            send(newsockfd, "Server is full", 14, 0);
            close(newsockfd);
            continue;
        }

        char *name = malloc(MAX_MSG_SIZE);
        recv(newsockfd, name, MAX_MSG_SIZE, 0);

        clients[num_clients].sockfd = newsockfd;
        clients[num_clients].addr = cli_addr;
        strcpy(clients[num_clients].name, name);
        num_clients++;

        printf("%s has joined the chat\n", name);

        pthread_create(&tid, NULL, client_handler, &clients[num_clients - 1]);
    }

    close(sockfd);
    return 0;
}