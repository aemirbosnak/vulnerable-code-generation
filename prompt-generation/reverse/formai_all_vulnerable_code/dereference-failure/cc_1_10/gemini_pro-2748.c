//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char request[MAX_REQUEST_SIZE];
    int request_len;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void add_client(int sockfd, struct sockaddr_in addr) {
    if (num_clients >= MAX_CLIENTS) {
        fprintf(stderr, "Too many clients!\n");
        close(sockfd);
        return;
    }

    clients[num_clients].sockfd = sockfd;
    clients[num_clients].addr = addr;
    clients[num_clients].request_len = 0;
    num_clients++;
}

void remove_client(int sockfd) {
    int i;

    for (i = 0; i < num_clients; i++) {
        if (clients[i].sockfd == sockfd) {
            break;
        }
    }

    if (i == num_clients) {
        return;
    }

    memmove(&clients[i], &clients[i + 1], (num_clients - i - 1) * sizeof(client_t));
    num_clients--;
}

int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    int i;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listenfd, 5) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &len);
        if (connfd < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("accept");
                return 1;
            }
        }

        add_client(connfd, cliaddr);
    }

    return 0;
}