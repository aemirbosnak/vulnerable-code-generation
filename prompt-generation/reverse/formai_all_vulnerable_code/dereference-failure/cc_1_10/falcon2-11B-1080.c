//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: ping <hostname> <packet count>\n");
        return 1;
    }

    char hostname[100];
    int packetCount = atoi(argv[2]);
    int port = 80;

    printf("Pinging %s with %d packets\n", argv[1], packetCount);
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(argv[1], NULL, &hints, &servinfo);
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            printf("ERROR opening socket\n");
            continue;
        }

        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &tv, sizeof(tv))) {
            perror("setsockopt");
            exit(1);
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)) {
            perror("connect");
            exit(1);
        }

        int num = 0;
        for (int i = 0; i < packetCount; i++) {
            char sendbuf[100];
            sprintf(sendbuf, "GET / HTTP/1.1\r\n\r\n");
            send(sockfd, sendbuf, strlen(sendbuf), 0);
            if (recv(sockfd, sendbuf, sizeof(sendbuf), 0) == 0) {
                printf("Received %d bytes from %s\n", i, argv[1]);
            } else {
                printf("Received %d bytes from %s\n", i, argv[1]);
            }
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}