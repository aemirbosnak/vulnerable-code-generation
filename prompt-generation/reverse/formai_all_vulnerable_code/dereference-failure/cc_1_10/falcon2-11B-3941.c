//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int n;

    if (argc!= 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(23);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    if (send(sockfd, "PING\n", strlen("PING\n"), 0) < 0) {
        perror("ERROR sending");
        exit(1);
    }

    if (recv(sockfd, &n, 1, 0) < 0) {
        perror("ERROR receiving");
        exit(1);
    }

    if (n == 0) {
        printf("PONG\n");
    } else {
        printf("ERROR, received %d\n", n);
    }

    close(sockfd);
    return 0;
}