//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void handle_client(int sockfd, char *msg) {
    printf("Received: %s\n", msg);
    char reply[100];
    int len = sprintf(reply, "Your message was received: %s\n", msg);
    send(sockfd, reply, len, 0);
    close(sockfd);
}

void *client(void *arg) {
    int sockfd = *((int*)arg);
    char buffer[1024];
    char *msg = NULL;
    int len = recv(sockfd, buffer, 1024, 0);
    if (len > 0) {
        msg = strstr(buffer, "\n");
    }
    if (msg) {
        handle_client(sockfd, msg);
        msg = NULL;
    }
    recv(sockfd, buffer, 1024, 0);
    close(sockfd);
    return NULL;
}

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    int opt = 1;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(serv_addr);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(12345);

    if (bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return -1;
    }

    if (listen(listenfd, 3) < 0) {
        perror("listen");
        return -1;
    }

    int optval = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        return -1;
    }

    while (1) {
        connfd = accept(listenfd, (struct sockaddr *) &cli_addr, (socklen_t *) &addrlen);
        if (connfd < 0) {
            perror("accept");
            return -1;
        }

        int *arg = (int*)malloc(sizeof(int));
        *arg = connfd;
        pthread_t thread;
        pthread_create(&thread, NULL, client, arg);
    }
    return 0;
}