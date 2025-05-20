//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    char* login = "a001 LOGIN user@example.com password\r\n";
    char* select = "a002 SELECT INBOX\r\n";
    char* fetch = "a003 FETCH 1:5 (BODY[HEADER]\r\n";
    char* logout = "a004 LOGOUT\r\n";

    // Send login command
    n = write(sockfd, login, strlen(login));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);

    // Send select command
    n = write(sockfd, select, strlen(select));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);

    // Send fetch command
    n = write(sockfd, fetch, strlen(fetch));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);

    // Send logout command
    n = write(sockfd, logout, strlen(logout));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}