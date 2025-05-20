//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_info;

void *handle_client(void *arg) {
    client_info *info = (client_info *)arg;
    char buffer[1024];

    while (1) {
        int len = recv(info->sockfd, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            break;
        }
        send(info->sockfd, buffer, len, 0);
    }

    close(info->sockfd);
    free(info);
    return NULL;
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        connfd = accept(sockfd, NULL, NULL);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        client_info *info = (client_info *)malloc(sizeof(client_info));
        info->sockfd = connfd;

        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, info) < 0) {
            perror("pthread_create");
            close(connfd);
            free(info);
            continue;
        }

        pthread_detach(thread);
    }

    close(sockfd);
    return 0;
}