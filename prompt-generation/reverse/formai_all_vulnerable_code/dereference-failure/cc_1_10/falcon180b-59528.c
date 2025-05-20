//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char *error) {
    perror(error);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s host port username\n", argv[0]);
        return 1;
    }

    char host[256];
    strncpy(host, argv[1], sizeof(host));

    char port[16];
    strncpy(port, argv[2], sizeof(port));

    char username[64];
    strncpy(username, argv[3], sizeof(username));

    struct addrinfo hints, *server;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int rc = getaddrinfo(host, port, &hints, &server);
    if (rc!= 0) {
        die("getaddrinfo");
    }

    int sock = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sock == -1) {
        die("socket");
    }

    rc = connect(sock, server->ai_addr, server->ai_addrlen);
    if (rc == -1) {
        die("connect");
    }

    char buf[BUFFER_SIZE];
    sprintf(buf, "USER %s\r\n", username);
    send(sock, buf, strlen(buf), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, sizeof(response));
    int bytes_received = recv(sock, response, sizeof(response), 0);
    if (bytes_received <= 0) {
        die("recv");
    }

    printf("Server response: %s", response);

    close(sock);
    return 0;
}