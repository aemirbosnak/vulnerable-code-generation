//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define MAX_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return EXIT_FAILURE;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&servaddr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    char request[MAX_SIZE];
    char response[MAX_SIZE];
    int n;

    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    while ((n = recv(sockfd, response, sizeof(response), 0)) > 0) {
        if (write(STDOUT_FILENO, response, n) < 0) {
            perror("write");
            close(sockfd);
            return EXIT_FAILURE;
        }
    }

    if (n < 0) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}