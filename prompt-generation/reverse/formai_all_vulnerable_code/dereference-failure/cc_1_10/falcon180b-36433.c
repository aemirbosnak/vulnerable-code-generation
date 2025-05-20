//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sock, ret;
    struct addrinfo hints, *res;
    char host[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host data\n", argv[0]);
        exit(1);
    }

    strncpy(host, argv[1], MAX_HOST_LEN - 1);
    strncpy(data, argv[2], MAX_DATA_LEN - 1);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(host, NULL, &hints, &res);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    ret = connect(sock, res->ai_addr, res->ai_addrlen);
    if (ret == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    ret = send(sock, data, strlen(data), 0);
    if (ret == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[MAX_DATA_LEN];
    memset(buffer, 0, MAX_DATA_LEN);
    ret = recv(sock, buffer, MAX_DATA_LEN, 0);
    if (ret == -1) {
        fprintf(stderr, "recv: %s\n", strerror(errno));
        exit(1);
    }

    close(sock);

    printf("Sent: %s\n", data);
    printf("Received: %s\n", buffer);

    return 0;
}