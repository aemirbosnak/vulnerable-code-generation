//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s on port %d\n", argv[1], ntohs(servaddr.sin_port));

    n = read(sockfd, &n, sizeof(n));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    printf("Number of hosts: %d\n", n);

    for (int i = 0; i < n; i++) {
        printf("Host %d: %s\n", i, argv[1]);
    }

    return 0;
}