//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char buffer[MAX_BUFFER_SIZE];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t lock;

void sigint_handler(int signum) {
    for (int i = 0; i < num_clients; i++) {
        close(clients[i].sockfd);
    }
    exit(0);
}

void *client_handler(void *arg) {
    client_t *client = (client_t *)arg;

    while (1) {
        int len = recv(client->sockfd, client->buffer, MAX_BUFFER_SIZE, 0);
        if (len <= 0) {
            pthread_mutex_lock(&lock);
            num_clients--;
            pthread_mutex_unlock(&lock);
            break;
        }

        client->buffer[len] = '\0';
        printf("Client %s:%d: %s\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port), client->buffer);

        len = send(client->sockfd, client->buffer, len, 0);
        if (len <= 0) {
            pthread_mutex_lock(&lock);
            num_clients--;
            pthread_mutex_unlock(&lock);
            break;
        }
    }

    close(client->sockfd);
    pthread_exit(NULL);
}

int main() {
    signal(SIGINT, sigint_handler);
    pthread_mutex_init(&lock, NULL);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(5000);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        pthread_t thread;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        pthread_mutex_lock(&lock);
        if (num_clients < MAX_CLIENTS) {
            clients[num_clients].sockfd = newsockfd;
            clients[num_clients].addr = client_addr;
            pthread_create(&thread, NULL, client_handler, &clients[num_clients]);
            num_clients++;
        } else {
            close(newsockfd);
        }
        pthread_mutex_unlock(&lock);
    }

    close(sockfd);
    pthread_mutex_destroy(&lock);

    return 0;
}