//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char name[32];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t lock;

void broadcast(char *msg) {
    for (int i = 0; i < num_clients; i++) {
        if (send(clients[i].sockfd, msg, strlen(msg), 0) == -1) {
            perror("send");
            exit(1);
        }
    }
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;

    char buf[1024];
    while (1) {
        int len = recv(client->sockfd, buf, sizeof(buf), 0);
        if (len == -1) {
            perror("recv");
            pthread_exit(NULL);
        } else if (len == 0) {
            pthread_exit(NULL);
        }

        buf[len] = '\0';
        printf("%s: %s\n", client->name, buf);

        pthread_mutex_lock(&lock);
        broadcast(buf);
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    pthread_mutex_init(&lock, NULL);

    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd == -1) {
            perror("accept");
            exit(1);
        }

        if (num_clients >= MAX_CLIENTS) {
            send(newsockfd, "Server full", strlen("Server full"), 0);
            close(newsockfd);
            continue;
        }

        pthread_t tid;
        clients[num_clients].sockfd = newsockfd;
        clients[num_clients].addr = cli_addr;
        strcpy(clients[num_clients].name, inet_ntoa(cli_addr.sin_addr));
        num_clients++;

        pthread_create(&tid, NULL, handle_client, &clients[num_clients - 1]);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}