//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "www.google.com"
#define SERVER_PORT 80

int main(int argc, char *argv[]) {
    int sockfd, connfd, n;
    struct sockaddr_in serverAddr;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <test duration in seconds>\n", argv[0]);
        exit(1);
    }

    char *test_duration = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname(SERVER_IP);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char *) &serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddr.sin_addr.s_addr, server->h_length);
    serverAddr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    char request[1024];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", SERVER_IP);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    if (argc == 2) {
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        for (int i = 0; i < atoi(test_duration); i++) {
            memset(buffer, 0, sizeof(buffer));
            n = recv(connfd, buffer, 1024, 0);
            if (n < 0) {
                perror("recv failed");
                exit(1);
            }
            printf("%s", buffer);
        }
    } else {
        printf("Test duration not specified.\n");
    }

    close(sockfd);
    return 0;
}