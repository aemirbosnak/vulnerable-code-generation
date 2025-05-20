//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <server IP or domain name>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(server, "80", &hints, &result);
    if (status!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        printf("socket: %s\n", strerror(errno));
        return 3;
    }

    status = connect(sockfd, result->ai_addr, result->ai_addrlen);
    if (status == -1) {
        printf("connect: %s\n", strerror(errno));
        return 4;
    }

    char request[80];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", server);
    send(sockfd, request, strlen(request), 0);

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while (1) {
        int ret = recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (ret == 0) {
            printf("Connection closed by server\n");
            break;
        } else if (ret == -1) {
            printf("recv: %s\n", strerror(errno));
            return 5;
        }
        bytes_received += ret;
        if (bytes_received >= BUFFER_SIZE) {
            printf("Response too large\n");
            return 6;
        }
        if (buffer[bytes_received - 1] == '\n') {
            break;
        }
    }

    close(sockfd);

    printf("Response:\n%s\n", buffer);

    return 0;
}