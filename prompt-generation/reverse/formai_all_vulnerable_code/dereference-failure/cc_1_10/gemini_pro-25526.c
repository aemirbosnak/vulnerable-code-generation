//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

typedef struct {
    int fd;
    struct sockaddr_in addr;
} connection_t;

connection_t connections[MAX_CONNECTIONS];
int num_connections = 0;

void add_connection(int fd, struct sockaddr_in addr) {
    if (num_connections >= MAX_CONNECTIONS) {
        printf("Error: Too many connections\n");
        close(fd);
        return;
    }

    connections[num_connections].fd = fd;
    connections[num_connections].addr = addr;
    num_connections++;
}

void remove_connection(int fd) {
    int i;

    for (i = 0; i < num_connections; i++) {
        if (connections[i].fd == fd) {
            break;
        }
    }

    if (i == num_connections) {
        printf("Error: Connection not found\n");
        return;
    }

    close(fd);
    num_connections--;

    for (; i < num_connections; i++) {
        connections[i] = connections[i+1];
    }
}

int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        printf("Error: Could not bind socket\n");
        exit(1);
    }

    if (listen(listenfd, MAX_CONNECTIONS) == -1) {
        printf("Error: Could not listen on socket\n");
        exit(1);
    }

    printf("Listening on port %d\n", PORT);

    while (1) {
        len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &len);
        if (connfd == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                printf("Error: Could not accept connection\n");
                exit(1);
            }
        }

        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        add_connection(connfd, cliaddr);
    }

    close(listenfd);

    return 0;
}