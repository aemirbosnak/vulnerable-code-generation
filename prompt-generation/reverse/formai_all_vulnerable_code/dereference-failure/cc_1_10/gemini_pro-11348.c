//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sockfd, port;
    struct sockaddr_in servaddr;
    char *buffer;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    buffer = (char *)malloc(1024);
    if (buffer == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("> ");
        fgets(buffer, 1024, stdin);
        if (strcmp(buffer, "quit\n") == 0) {
            break;
        }

        if (write(sockfd, buffer, strlen(buffer)) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        if (read(sockfd, buffer, 1024) < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("%s", buffer);
    }

    close(sockfd);
    free(buffer);

    return EXIT_SUCCESS;
}