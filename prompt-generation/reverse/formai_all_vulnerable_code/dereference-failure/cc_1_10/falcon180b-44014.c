//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 5000
#define BUFLEN 1024

typedef struct {
    char *ip;
    int port;
} target;

int ping(target *t);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    target t = {.ip = ip,.port = port};

    int result = ping(&t);

    if (result == TRUE) {
        printf("%s is reachable.\n", ip);
    } else {
        printf("%s is not reachable.\n", ip);
    }

    return 0;
}

int ping(target *t) {
    int sockfd, ret;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket.\n");
        return FALSE;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(t->port);
    inet_pton(AF_INET, t->ip, &servaddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    if (ret == -1) {
        if (errno == ECONNREFUSED) {
            printf("%s:%d is not reachable.\n", t->ip, t->port);
            return FALSE;
        } else if (errno == ETIMEDOUT) {
            printf("%s:%d is not reachable.\n", t->ip, t->port);
            return FALSE;
        } else {
            printf("Error connecting to %s:%d.\n", t->ip, t->port);
            return FALSE;
        }
    } else {
        close(sockfd);
        printf("%s:%d is reachable.\n", t->ip, t->port);
        return TRUE;
    }
}