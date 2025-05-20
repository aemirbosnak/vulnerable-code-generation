//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    char *host_name = "example.com";
    char *port_number = "80";
    char *path = "/";
    int sockfd, status, bytes_received;
    struct addrinfo hints, *res;
    char sendline[MAX_LINE_SIZE], recvline[MAX_LINE_SIZE];

    if (argc == 2) {
        host_name = argv[1];
    } else if (argc == 3) {
        host_name = argv[1];
        port_number = argv[2];
    } else if (argc == 4) {
        host_name = argv[1];
        port_number = argv[2];
        path = argv[3];
    }

    // setup hints struct and get address information
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if ((status = getaddrinfo(host_name, port_number, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    // create socket and connect to the server
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect error");
        exit(1);
    }

    // send HTTP GET request to the server
    sprintf(sendline, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host_name);
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // receive and print response from the server
    bytes_received = recv(sockfd, recvline, MAX_LINE_SIZE, 0);
    while (bytes_received > 0) {
        recvline[bytes_received] = '\0';
        printf("%s", recvline);
        bytes_received = recv(sockfd, recvline, MAX_LINE_SIZE, 0);
    }

    // close the socket and free the address info struct
    close(sockfd);
    freeaddrinfo(res);

    return 0;
}