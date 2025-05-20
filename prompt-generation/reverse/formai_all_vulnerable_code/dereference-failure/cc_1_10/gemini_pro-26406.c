//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define BACKLOG 5
#define MAX_CLIENTS 10
#define MAX_MSG_LEN 512

typedef struct {
    int sockfd;
    char username[32];
} client_info;

client_info clients[MAX_CLIENTS];
int client_count = 0;

pthread_mutex_t lock;

void *client_thread(void *arg) {
    client_info *client = (client_info *)arg;
    char buf[MAX_MSG_LEN];

    while (1) {
        memset(buf, 0, sizeof(buf));
        if (recv(client->sockfd, buf, sizeof(buf), 0) <= 0) {
            break;
        }

        pthread_mutex_lock(&lock);
        for (int i = 0; i < client_count; i++) {
            if (clients[i].sockfd != client->sockfd) {
                send(clients[i].sockfd, buf, strlen(buf), 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }

    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].sockfd == client->sockfd) {
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&lock);

    close(client->sockfd);
    free(client);
    return NULL;
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    socklen_t clilen;
    char buf[32];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(5000);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("Error on listen");
        exit(1);
    }

    pthread_mutex_init(&lock, NULL);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on accept");
            continue;
        }

        recv(newsockfd, buf, sizeof(buf), 0);
        printf("New client connected: %s\n", buf);

        client_info *client = malloc(sizeof(client_info));
        client->sockfd = newsockfd;
        strcpy(client->username, buf);

        pthread_mutex_lock(&lock);
        clients[client_count++] = *client;
        pthread_mutex_unlock(&lock);

        pthread_t tid;
        if (pthread_create(&tid, NULL, client_thread, client) != 0) {
            perror("Error creating thread");
            close(newsockfd);
            continue;
        }
    }

    pthread_mutex_destroy(&lock);
    close(sockfd);
    return 0;
}