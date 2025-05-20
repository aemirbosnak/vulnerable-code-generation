//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_aton(hostname, &server_addr.sin_addr) == 0) {
        fprintf(stderr, "Invalid hostname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    char buffer[MAXLINE];
    while (1) {
        printf("ftp> ");
        fgets(buffer, MAXLINE, stdin);

        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        }

        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            close(sockfd);
            return EXIT_FAILURE;
        }

        int n = recv(sockfd, buffer, MAXLINE, 0);
        if (n == -1) {
            perror("recv");
            close(sockfd);
            return EXIT_FAILURE;
        } else if (n == 0) {
            printf("Connection closed by server.\n");
            close(sockfd);
            return EXIT_SUCCESS;
        }

        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}