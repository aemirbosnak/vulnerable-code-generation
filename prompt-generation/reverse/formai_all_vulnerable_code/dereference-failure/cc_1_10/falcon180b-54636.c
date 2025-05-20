//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_LINE 1024
#define PORT 110
#define TIMEOUT_SEC 10
#define TIMEOUT_USEC 0

int main() {
    int sock;
    struct addrinfo hints, *server;
    struct sockaddr *addr;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    int rv;
    int status;
    char buffer[MAX_LINE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    snprintf(service, sizeof(service), "%d", PORT);
    if ((rv = getaddrinfo("localhost", service, &hints, &server))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sock = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sock == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sock, server->ai_addr, server->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Connected to POP3 server.\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (read(sock, buffer, sizeof(buffer)) <= 0) {
            fprintf(stderr, "read: %s\n", strerror(errno));
            break;
        }
        fprintf(stdout, "Received: %s", buffer);

        if (strstr(buffer, ".")!= NULL) {
            fprintf(stdout, "\nClosing connection...\n");
            break;
        }
    }

    close(sock);
    exit(0);
}