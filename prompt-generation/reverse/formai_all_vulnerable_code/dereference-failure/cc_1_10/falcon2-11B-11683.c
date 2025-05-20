//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 512

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char recvbuf[MAXLINE];
    char sendbuf[MAXLINE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host> [<port>]\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host\n");
        exit(1);
    }

    memset((char *) &servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (argc == 3) {
        fprintf(stderr, "Pinging %s (%s) with %s bytes of data\n",
                inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port), argv[2]);
    } else {
        fprintf(stderr, "Pinging %s (%s) with 56 bytes of data\n",
                inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error connecting\n");
        exit(1);
    }

    sprintf(sendbuf, "PING %s (%s) %d\r\n", argv[1], ntohs(servaddr.sin_port), 56);
    n = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (n < 0) {
        fprintf(stderr, "Error sending data\n");
        exit(1);
    }

    recv(sockfd, recvbuf, MAXLINE, 0);
    printf("%s\n", recvbuf);

    close(sockfd);
    return 0;
}