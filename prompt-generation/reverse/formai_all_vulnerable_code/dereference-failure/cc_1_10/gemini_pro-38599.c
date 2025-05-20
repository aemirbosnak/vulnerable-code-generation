//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 80

int main(int argc, char** argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <ip> <port> <path>\n", argv[0]);
        return 1;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);
    const char* path = argv[3];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    char request[MAX_LINE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s:%d\r\n\r\n", path, ip, port);

    if (write(sockfd, request, strlen(request)) == -1) {
        perror("write");
        return 1;
    }

    char response[MAX_LINE];
    while (read(sockfd, response, MAX_LINE) > 0) {
        fwrite(response, 1, strlen(response), stdout);
    }

    close(sockfd);
    return 0;
}