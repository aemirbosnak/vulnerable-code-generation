//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[MAX_LINE];
    printf("Enter a message: ");
    fgets(buffer, MAX_LINE, stdin);

    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    n = recv(sockfd, buffer, MAX_LINE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}