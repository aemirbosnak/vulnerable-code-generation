//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR: hostname not found\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    int len = sizeof("GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    write(sockfd, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n", len);

    int n = read(sockfd, (char *) NULL, 1);
    if (n <= 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("Round-trip time: %dms\n", (int) n);

    close(sockfd);

    return 0;
}