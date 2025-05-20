//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints;
    struct addrinfo *servinfo;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // Use both IPv4 and IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP

    status = getaddrinfo(host, "http", &hints, &servinfo);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    struct sockaddr_in *sin = (struct sockaddr_in *)servinfo->ai_addr;

    int sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        goto error;
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        goto error;
    }

    char buf[1024];
    int n;

    while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
        printf("%s", buf);
    }

    printf("\n");

error:
    freeaddrinfo(servinfo);

    return 0;
}