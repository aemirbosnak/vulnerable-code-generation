//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 2048

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) != 0) {
        printf("Error listening for connections: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (1) {
        socklen_t len = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
        if (connfd < 0) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        char request[MAX_REQUEST_SIZE];
        ssize_t bytes_read = read(connfd, request, MAX_REQUEST_SIZE - 1);
        if (bytes_read < 0) {
            printf("Error reading request: %s\n", strerror(errno));
            close(connfd);
            continue;
        }

        request[bytes_read] = '\0';

        char response[256] = "HTTP/1.1 200 OK\r\nServer: CyberServer\r\nContent-Length: 12\r\nContent-Type: text/html\r\n\r\nHello world!";
        ssize_t bytes_written = write(connfd, response, strlen(response));
        if (bytes_written < 0) {
            printf("Error writing response: %s\n", strerror(errno));
            close(connfd);
            continue;
        }

        close(connfd);
    }

    return 0;
}