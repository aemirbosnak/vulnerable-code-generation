//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buffer[1024];
    if (send(sockfd, "USER test\r\n", 11, 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Received: %s\n", buffer);

    if (send(sockfd, "PASS test\r\n", 12, 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Received: %s\n", buffer);

    if (send(sockfd, "QUIT\r\n", 7, 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}