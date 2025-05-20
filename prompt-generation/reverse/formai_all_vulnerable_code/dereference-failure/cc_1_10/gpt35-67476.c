//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFSIZE 1024
#define PORT 110

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];
    int n;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname username password\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    n = recv(sockfd, buffer, BUFSIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);

    sprintf(buffer, "USER %s\r\n", argv[2]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    n = recv(sockfd, buffer, BUFSIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);

    sprintf(buffer, "PASS %s\r\n", argv[3]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    n = recv(sockfd, buffer, BUFSIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);

    sprintf(buffer, "LIST\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    n = recv(sockfd, buffer, BUFSIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);

    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    close(sockfd);
    return 0;
}