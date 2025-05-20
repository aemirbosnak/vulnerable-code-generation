//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define MAXLINE 256

int main(int argc, char *argv[]) {
    int sockfd, valread, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char recvbuf[MAXLINE];

    if (argc!= 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    // set up server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: Unknown host\n");
        return 1;
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(110);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Username: ");
    fgets(recvbuf, MAXLINE, stdin);

    // send username to server
    n = send(sockfd, recvbuf, strlen(recvbuf), 0);
    if (n < 0) {
        perror("send");
        return 1;
    }

    printf("Password: ");
    fgets(recvbuf, MAXLINE, stdin);

    // send password to server
    n = send(sockfd, recvbuf, strlen(recvbuf), 0);
    if (n < 0) {
        perror("send");
        return 1;
    }

    printf("Username/password sent\n");

    // receive mail
    if (recv(sockfd, recvbuf, MAXLINE, 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("%s\n", recvbuf);

    // close socket
    close(sockfd);

    return 0;
}