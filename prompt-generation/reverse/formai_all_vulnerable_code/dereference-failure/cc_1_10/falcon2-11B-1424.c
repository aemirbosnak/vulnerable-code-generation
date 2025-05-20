//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    struct sockaddr_in server;
    int sockfd = -1;
    socklen_t addr_len = sizeof(server);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(25);
    if (inet_pton(AF_INET, hostname, &server.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("connect");
        return 1;
    }

    char command[256];
    sprintf(command, "EHLO %s\r\n", hostname);
    send(sockfd, command, strlen(command), 0);

    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) <= 0) {
        perror("recv");
        return 1;
    }

    printf("Response: %s\n", response);

    close(sockfd);

    return 0;
}