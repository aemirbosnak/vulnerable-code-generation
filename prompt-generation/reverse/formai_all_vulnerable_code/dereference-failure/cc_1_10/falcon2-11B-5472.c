//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(53);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Pinging %s...\n", argv[1]);
    n = write(sockfd, "A", 1);
    if (n == -1) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, &n, sizeof(n));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    if (n == 0) {
        printf("No response from %s\n", argv[1]);
    } else {
        printf("Response from %s: %s bytes\n", argv[1], n);
    }

    close(sockfd);
    exit(0);
}