//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define HTTP_PORT 80
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

int main(int argc, char *argv[]) {
    const char *server_address = argv[1];
    const char *url_path = argv[2];
    int sockfd = INVALID_SOCKET;
    struct sockaddr_in server;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <url_path>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR) {
        perror("socket");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(HTTP_PORT);

    if (inet_pton(AF_INET, server_address, &server.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        perror("connect");
        exit(1);
    }

    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", url_path, server_address);

    if (send(sockfd, buffer, strlen(buffer), 0) == SOCKET_ERROR) {
        perror("send");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    int total_bytes = 0;

    while (1) {
        int bytes = recv(sockfd, buffer + total_bytes, MAX_BUFFER_SIZE - total_bytes, 0);

        if (bytes < 0) {
            perror("recv");
            exit(1);
        } else if (bytes == 0) {
            break;
        } else {
            total_bytes += bytes;
        }
    }

    close(sockfd);

    printf("Response:\n%s\n", buffer);

    return 0;
}