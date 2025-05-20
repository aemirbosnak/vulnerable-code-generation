//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 1024

typedef struct {
    char host[256];
    int port;
} url_t;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <resource>\n", argv[0]);
        return 1;
    }

    url_t url;
    strcpy(url.host, argv[1]);
    url.port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(url.port);

    if (inet_pton(AF_INET, url.host, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\nUser-Agent: Retro-Client/1.0\r\nAccept: text/plain\r\n\r\n", argv[2], url.host, url.port);

    write(sockfd, request, strlen(request));

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, bytes_received, 1, stdout);
    }

    close(sockfd);

    return 0;
}