//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

void *thread(void *ptr);

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    int opt = TRUE;
    int addrlen = sizeof(cliaddr);

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, thread, (void*)connfd)!= 0) {
            perror("thread create");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void *thread(void *ptr) {
    int connfd = *((int*)ptr);
    char buffer[1024];

    send(connfd, "Welcome to the surreal world of TCP/IP programming!", strlen("Welcome to the surreal world of TCP/IP programming!"), 0);

    while (TRUE) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(connfd, buffer, sizeof(buffer), 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Surreal message received: %s\n", buffer);
    }

    close(connfd);
    pthread_exit(NULL);
}