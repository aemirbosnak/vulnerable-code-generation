//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct client {
    int sockfd;
    char ip[INET_ADDRSTRLEN];
    int port;
};

void *
handle_client(void *arg) {
    struct client *client = (struct client *)arg;
    char buffer[1024];

    while (1) {
        int n = read(client->sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            perror("read");
            break;
        }

        printf("Received %d bytes from %s:%d: %s\n", n, client->ip, client->port, buffer);

        int m = write(client->sockfd, buffer, n);
        if (m <= 0) {
            perror("write");
            break;
        }
    }

    close(client->sockfd);
    free(client);
    return NULL;
}

int
main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        return 1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listenfd, 5) < 0) {
        perror("listen");
        return 1;
    }

    clilen = sizeof(cliaddr);
    while (1) {
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        struct client *client = malloc(sizeof(*client));
        client->sockfd = connfd;
        strcpy(client->ip, inet_ntoa(cliaddr.sin_addr));
        client->port = ntohs(cliaddr.sin_port);

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)client) != 0) {
            perror("pthread_create");
            close(connfd);
            free(client);
            continue;
        }
    }

    return 0;
}