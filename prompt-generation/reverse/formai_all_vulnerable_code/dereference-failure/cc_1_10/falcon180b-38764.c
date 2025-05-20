//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *) arg;
    char buf[BUF_SIZE];
    while (1) {
        memset(buf, 0, BUF_SIZE);
        int bytes_received = recv(client->sockfd, buf, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buf[bytes_received] = '\0';
        printf("Received: %s\n", buf);
        send(client->sockfd, buf, strlen(buf), 0);
    }
    close(client->sockfd);
    free(client);
}

int main() {
    int listenfd, connfd, opt = 1;
    struct sockaddr_in serveraddr, clientaddr;
    pthread_t thread_id;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(errno);
    }

    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("bind");
        exit(errno);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(errno);
    }

    while (1) {
        socklen_t addrlen = sizeof(clientaddr);
        connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &addrlen);
        if (connfd == -1) {
            perror("accept");
            exit(errno);
        }
        client_t *client = (client_t *) malloc(sizeof(client_t));
        client->sockfd = connfd;
        memcpy(&client->addr, &clientaddr, sizeof(clientaddr));
        pthread_create(&thread_id, NULL, handle_client, client);
    }

    return 0;
}