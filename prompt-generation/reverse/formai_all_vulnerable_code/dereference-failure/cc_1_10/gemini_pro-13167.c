//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define IMAP_PORT 143

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if (argc != 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("%.*s", n, buffer);

    sprintf(buffer, "a001 LOGIN %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("%.*s", n, buffer);

    close(sockfd);
    return 0;
}