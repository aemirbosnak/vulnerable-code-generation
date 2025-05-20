//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <pthread.h>

#define BACKLOG 10

static void *handle_connection(void *arg) {
    int sockfd = *(int *)arg;
    free(arg);

    char buffer[1024];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received %d bytes: %s\n", bytes_received, buffer);
        if (strcmp(buffer, "exit") == 0) {
            break;
        } else {
            send(sockfd, "OK", 2, 0);
        }
    }

    close(sockfd);

    return NULL;
}

int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    pthread_t tid;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0) {
            perror("accept");
            continue;
        }

        int *arg = malloc(sizeof(int));
        *arg = connfd;

        if (pthread_create(&tid, NULL, handle_connection, arg) != 0) {
            perror("pthread_create");
            close(connfd);
        }
    }

    close(listenfd);
    return 0;
}