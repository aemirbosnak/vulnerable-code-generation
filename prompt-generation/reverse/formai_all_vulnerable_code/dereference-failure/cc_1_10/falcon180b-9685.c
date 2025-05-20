//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc!= 2) {
        printf("Usage:./program hostname\n");
        return 1;
    }

    char hostname[256];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int status;
    if((status = getaddrinfo(hostname, NULL, &hints, &result))!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(sockfd == -1) {
        printf("socket: %s\n", strerror(errno));
        return 1;
    }

    if(connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        printf("connect: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    send(sockfd, "PING", strlen("PING"), 0);

    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(bytes_received == -1) {
        printf("recv: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    close(sockfd);

    if(strncmp(buffer, "PONG", strlen("PONG"))!= 0) {
        printf("PING failed\n");
        return 1;
    }

    printf("PING succeeded\n");

    return 0;
}