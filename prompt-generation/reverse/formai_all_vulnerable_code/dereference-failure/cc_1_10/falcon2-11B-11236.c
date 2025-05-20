//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT 25
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[BUFSIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    portno = htons(PORT);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    if (send(sockfd, "EHLO localhost\r\n", 11, 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, buf, BUFSIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buf);

    close(sockfd);

    return 0;
}