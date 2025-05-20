//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_LINE];
    char *host;
    int port;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", host);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        printf("> ");
        fgets(buffer, MAX_LINE, stdin);

        if (strcmp(buffer, "quit\n") == 0) {
            break;
        }

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            exit(1);
        }

        if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
            perror("recv");
            exit(1);
        }

        printf("Received: %s", buffer);
    }

    close(sockfd);

    return 0;
}