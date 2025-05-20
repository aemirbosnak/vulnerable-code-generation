//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Received %d bytes: %s\n", n, buffer);

    char request[1024];
    sprintf(request, "HEAD / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    printf("Sent request: %s\n", request);

    char response[1024];
    n = read(sockfd, response, sizeof(response));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Received %d bytes: %s\n", n, response);

    close(sockfd);
    return 0;
}