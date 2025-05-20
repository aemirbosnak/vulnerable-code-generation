//Falcon-180B DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *servinfo;
    char *node = "localhost";
    char *service = "8080";
    int rv;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(node, service, &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sock = socket(servinfo->ai_family, servinfo->ai_socktype,
        servinfo->ai_protocol);
    if (sock == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sock, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    freeaddrinfo(servinfo);

    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
        send(sock, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }
        memset(buffer, 0, sizeof(buffer));
        if (recv(sock, buffer, sizeof(buffer), 0) == 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}