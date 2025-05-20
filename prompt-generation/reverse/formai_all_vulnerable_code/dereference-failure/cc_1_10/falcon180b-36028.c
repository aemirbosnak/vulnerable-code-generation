//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char *host, *port;
    int rv;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <host> <port> <command>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = argv[2];
    strcpy(send_buffer, argv[3]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    sock = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    if (connect(sock, servinfo->ai_addr, servinfo->ai_addrlen)!= 0) {
        perror("connect");
        close(sock);
        return 1;
    }

    send(sock, send_buffer, strlen(send_buffer), 0);

    while (1) {
        memset(recv_buffer, 0, BUFFER_SIZE);
        if ((rv = recv(sock, recv_buffer, BUFFER_SIZE, 0)) <= 0) {
            if (rv == 0) {
                printf("Server closed connection\n");
            } else {
                perror("recv");
            }
            close(sock);
            return 1;
        }
        printf("Received: %s\n", recv_buffer);
    }

    close(sock);
    return 0;
}