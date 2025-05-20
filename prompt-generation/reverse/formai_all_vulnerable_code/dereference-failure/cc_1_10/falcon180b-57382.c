//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char host[MAX_HOSTNAME];
    char data[MAX_DATA];
    int rv;
    int numbytes;

    printf("Enter hostname: ");
    scanf("%s", host);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(1);
    }

    printf("Enter data to send: ");
    scanf("%s", data);

    numbytes = send(sock, data, strlen(data), 0);
    if (numbytes <= 0) {
        perror("send");
        exit(1);
    }

    memset(data, 0, MAX_DATA);
    numbytes = recv(sock, data, MAX_DATA, 0);
    if (numbytes <= 0) {
        perror("recv");
        exit(1);
    }

    printf("Received data: %s\n", data);

    close(sock);
    freeaddrinfo(servinfo);

    return 0;
}