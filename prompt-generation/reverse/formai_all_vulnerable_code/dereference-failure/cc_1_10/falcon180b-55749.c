//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname/IP> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(errno));
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        printf("socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        printf("connect: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    send(sockfd, "PING", strlen("PING"), 0);

    int bytes_received;
    if ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) <= 0) {
        printf("recv: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    buffer[bytes_received] = '\0';
    printf("Received response: %s\n", buffer);

    close(sockfd);
    return 0;
}