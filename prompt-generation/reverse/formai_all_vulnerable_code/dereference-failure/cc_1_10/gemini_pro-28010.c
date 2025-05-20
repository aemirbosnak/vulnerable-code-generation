//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>

#define MAX_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} connection_t;

connection_t connections[MAX_CONNECTIONS];
int num_connections = 0;

void handle_connection(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        printf("Received %d bytes from %s:%d\n", n, inet_ntoa(connections[sockfd].addr.sin_addr), ntohs(connections[sockfd].addr.sin_port));
        if (strstr(buffer, "attack") != NULL) {
            printf("Attack detected from %s:%d\n", inet_ntoa(connections[sockfd].addr.sin_addr), ntohs(connections[sockfd].addr.sin_port));
            close(sockfd);
            connections[sockfd].sockfd = -1;
            num_connections--;
            break;
        }
    }

    if (n == 0) {
        printf("Connection closed from %s:%d\n", inet_ntoa(connections[sockfd].addr.sin_addr), ntohs(connections[sockfd].addr.sin_port));
        close(sockfd);
        connections[sockfd].sockfd = -1;
        num_connections--;
    } else {
        perror("recv");
    }
}

void accept_connection(int listenfd) {
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int sockfd;

    if ((sockfd = accept(listenfd, (struct sockaddr *)&addr, &addrlen)) < 0) {
        perror("accept");
        exit(1);
    }

    if (num_connections >= MAX_CONNECTIONS) {
        printf("Too many connections, closing new connection from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        close(sockfd);
        return;
    }

    connections[sockfd].sockfd = sockfd;
    connections[sockfd].addr = addr;
    num_connections++;

    printf("New connection from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
}

int main(int argc, char **argv) {
    int listenfd, port;
    struct sockaddr_in addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        fd_set readfds;
        int maxfd = listenfd;
        int i;

        FD_ZERO(&readfds);
        FD_SET(listenfd, &readfds);

        for (i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].sockfd != -1) {
                FD_SET(connections[i].sockfd, &readfds);
                if (connections[i].sockfd > maxfd) {
                    maxfd = connections[i].sockfd;
                }
            }
        }

        if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(1);
        }

        if (FD_ISSET(listenfd, &readfds)) {
            accept_connection(listenfd);
        }

        for (i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].sockfd != -1 && FD_ISSET(connections[i].sockfd, &readfds)) {
                handle_connection(connections[i].sockfd);
            }
        }
    }

    return 0;
}