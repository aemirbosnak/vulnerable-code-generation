//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_PORT_LEN 6
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <data>\n", argv[0]);
        exit(1);
    }

    char host[MAX_HOST_LEN] = {0};
    strncpy(host, argv[1], MAX_HOST_LEN - 1);

    char port[MAX_PORT_LEN] = {0};
    strncpy(port, argv[2], MAX_PORT_LEN - 1);

    char data[MAX_DATA_LEN] = {0};
    strncpy(data, argv[3], MAX_DATA_LEN - 1);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct addrinfo hints = {
       .ai_family = AF_UNSPEC,
       .ai_socktype = SOCK_STREAM,
    };

    struct addrinfo *servinfo = NULL;
    int rv = getaddrinfo(host, port, &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    struct sockaddr *addr = servinfo->ai_addr;
    socklen_t addrlen = servinfo->ai_addrlen;

    if (connect(sockfd, addr, addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    send(sockfd, data, strlen(data), 0);

    char buffer[MAX_DATA_LEN] = {0};
    int bytes_received = recv(sockfd, buffer, MAX_DATA_LEN - 1, 0);
    if (bytes_received <= 0) {
        perror("recv");
        exit(1);
    }

    printf("Received response: %s\n", buffer);

    close(sockfd);
    freeaddrinfo(servinfo);

    return 0;
}