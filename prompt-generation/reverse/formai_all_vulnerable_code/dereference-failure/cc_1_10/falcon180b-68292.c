//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &res)!= 0) {
        error("getaddrinfo");
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        error("socket");
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        close(sock);
        error("connect");
    }

    char buffer[1024];
    sprintf(buffer, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname);

    send(sock, buffer, strlen(buffer), 0);

    char response[1024];
    int bytes_received = recv(sock, response, sizeof(response), 0);
    response[bytes_received] = '\0';

    if (bytes_received <= 0) {
        close(sock);
        error("recv");
    }

    printf("Response:\n%s\n", response);

    close(sock);
    return 0;
}