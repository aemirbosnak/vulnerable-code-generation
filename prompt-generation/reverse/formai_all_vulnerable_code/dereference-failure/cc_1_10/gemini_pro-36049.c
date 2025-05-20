//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

typedef struct client_info {
    int sockfd;
    char name[32];
} client_info_t;

pthread_mutex_t mutex;
client_info_t clients[MAX_CLIENTS];
int num_clients = 0;

void send_message(int sockfd, char *message) {
    int len = strlen(message);
    if (send(sockfd, &len, sizeof(int), 0) < 0) {
        perror("send");
        exit(1);
    }
    if (send(sockfd, message, len, 0) < 0) {
        perror("send");
        exit(1);
    }
}

void *client_thread(void *arg) {
    int sockfd = *(int *)arg;
    char buffer[MAX_MSG_LEN];
    int len;

    while (1) {
        if (recv(sockfd, &len, sizeof(int), 0) <= 0) {
            perror("recv");
            exit(1);
        }
        if (recv(sockfd, buffer, len, 0) <= 0) {
            perror("recv");
            exit(1);
        }

        pthread_mutex_lock(&mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].sockfd != sockfd) {
                send_message(clients[i].sockfd, buffer);
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int listenfd, sockfd;
    struct sockaddr_in servaddr, cliaddr;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    pthread_mutex_init(&mutex, NULL);

    while (1) {
        socklen_t len = sizeof(cliaddr);
        sockfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
        if (sockfd < 0) {
            perror("accept");
            exit(1);
        }

        pthread_mutex_lock(&mutex);
        if (num_clients < MAX_CLIENTS) {
            clients[num_clients].sockfd = sockfd;
            sprintf(clients[num_clients].name, "Client %d", num_clients + 1);
            num_clients++;

            pthread_t thread;
            pthread_create(&thread, NULL, client_thread, &sockfd);
            pthread_detach(thread);
        } else {
            send_message(sockfd, "Server is full. Please try again later.");
            close(sockfd);
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_destroy(&mutex);
    close(listenfd);
    return 0;
}