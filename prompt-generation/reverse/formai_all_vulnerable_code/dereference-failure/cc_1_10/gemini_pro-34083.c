//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143
#define MAX_LINE_LEN 512

int main(int argc, char **argv) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_LINE_LEN];
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <server port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    while (1) {
        printf("Enter command: ");
        if (fgets(buffer, MAX_LINE_LEN, stdin) == NULL) {
            perror("fgets");
            close(sockfd);
            return EXIT_FAILURE;
        }
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("write");
            close(sockfd);
            return EXIT_FAILURE;
        }

        n = read(sockfd, buffer, MAX_LINE_LEN);
        if (n < 0) {
            perror("read");
            close(sockfd);
            return EXIT_FAILURE;
        }

        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}