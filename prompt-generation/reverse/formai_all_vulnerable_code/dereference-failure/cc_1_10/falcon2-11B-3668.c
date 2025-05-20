//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXLINE];

    if (argc < 2) {
        fprintf(stderr, "usage %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, MAXLINE);
        if (n <= 0)
            break;
        printf("%s", buffer);
        n = write(sockfd, buffer, MAXLINE);
        if (n <= 0)
            break;
    }

    return 0;
}