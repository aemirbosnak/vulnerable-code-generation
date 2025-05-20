//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    char *url = argv[1];
    char *host;
    int port;

    if (strncmp(url, "http://", 7) == 0) {
        host = url + 7;
        port = 80;
    } else if (strncmp(url, "https://", 8) == 0) {
        host = url + 8;
        port = 443;
    } else {
        fprintf(stderr, "Invalid URL: %s\n", url);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        exit(1);
    }

    char buf[BUFSIZE];
    sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        close(sockfd);
        exit(1);
    }

    int n;
    while ((n = recv(sockfd, buf, BUFSIZE, 0)) > 0) {
        fwrite(buf, 1, n, stdout);
    }

    if (n == -1) {
        perror("recv");
    }

    close(sockfd);

    return 0;
}