//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 4096
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAXLINE];
    int n;
    int err;
    int count = 0;
    int timeout = 5;
    int max_count = 0;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("connection failed\n");
        exit(1);
    }

    printf("Connection Established\n");

    while (count < max_count) {
        n = send(sockfd, "PING", strlen("PING"), 0);
        if (n == -1) {
            printf("send failed\n");
            exit(1);
        }

        memset(buffer, 0, MAXLINE);
        n = recv(sockfd, buffer, MAXLINE, 0);
        if (n <= 0) {
            printf("recv failed\n");
            exit(1);
        }

        if (strcmp(buffer, "PONG") == 0) {
            count++;
        } else {
            count = 0;
        }

        if (count == max_count) {
            printf("Host is up\n");
            exit(0);
        } else {
            printf("Host is down\n");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}