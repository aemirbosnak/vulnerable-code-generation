//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buf[256];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(0);
    }

    while (1) {
        bzero(buf, 256);
        n = read(sockfd, buf, 255);
        if (n < 0) {
            perror("read");
            exit(0);
        }

        printf("Received data: %s\n", buf);

        bzero(buf, 256);
        n = write(sockfd, buf, 255);
        if (n < 0) {
            perror("write");
            exit(0);
        }

        printf("Sent data: %s\n", buf);
    }

    close(sockfd);
    return 0;
}