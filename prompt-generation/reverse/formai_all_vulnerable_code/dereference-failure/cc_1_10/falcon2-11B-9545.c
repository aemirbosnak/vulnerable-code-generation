//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <target IP address> <port number>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server;
    int port = atoi(argv[2]);
    int sockfd;
    char buffer[1024];
    int n;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Connection established to %s:%d\n", argv[1], port);

    if (send(sockfd, "GET / HTTP/1.1\r\n", 33, 0) == -1) {
        perror("send");
        return 1;
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}