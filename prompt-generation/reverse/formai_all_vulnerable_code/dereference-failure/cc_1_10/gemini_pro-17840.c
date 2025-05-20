//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 4096

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &serv_addr.sin_addr) == 0) {
        perror("inet_aton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        bzero(buffer, BUFSIZE);
        printf("IMAP> ");
        fgets(buffer, BUFSIZE - 1, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("write");
            exit(1);
        }

        bzero(buffer, BUFSIZE);
        n = read(sockfd, buffer, BUFSIZE - 1);
        if (n < 0) {
            perror("read");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}