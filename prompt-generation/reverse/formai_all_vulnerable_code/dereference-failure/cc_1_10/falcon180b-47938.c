//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define DEFAULT_PORT "80"

int main(int argc, char *argv[]) {
    char hostname[MAX_HOSTNAME] = {0};
    char data[MAX_DATA] = {0};
    int port = 0;
    int sockfd = 0;
    struct addrinfo hints, *servinfo = NULL;
    int rv;
    int numbytes;

    if (argc < 3) {
        printf("Usage: %s hostname [port]\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);

    if (argc == 3) {
        port = atoi(argv[2]);
    } else {
        port = htons(atoi(DEFAULT_PORT));
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(hostname, NULL, &hints, &servinfo);

    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    rv = connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);

    if (rv == -1) {
        perror("connect");
        exit(1);
    }

    sprintf(data, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname);

    numbytes = send(sockfd, data, strlen(data), 0);

    if (numbytes == -1) {
        perror("send");
        exit(1);
    }

    close(sockfd);

    printf("Ping successful to %s on port %d\n", hostname, port);

    return 0;
}