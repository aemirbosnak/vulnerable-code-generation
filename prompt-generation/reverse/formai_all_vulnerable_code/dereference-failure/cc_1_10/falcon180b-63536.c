//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *addrinfo;
    struct addrinfo hints;
    int status;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <hostname/ip> <port>\n", argv[0]);
        return 1;
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(argv[1], argv[2], &hints, &addrinfo);

    if (status!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    sockfd = socket(addrinfo->ai_family, addrinfo->ai_socktype, addrinfo->ai_protocol);

    if (sockfd == -1) {
        printf("socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, addrinfo->ai_addr, addrinfo->ai_addrlen) == -1) {
        printf("connect: %s\n", strerror(errno));
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    send(sockfd, "PING", strlen("PING"), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received == 0) {
            printf("Disconnected\n");
            break;
        }

        if (bytes_received == -1) {
            printf("recv: %s\n", strerror(errno));
            break;
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}