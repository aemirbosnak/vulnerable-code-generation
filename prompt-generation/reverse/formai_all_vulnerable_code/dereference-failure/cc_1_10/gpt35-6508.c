//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
        error("ERROR invalid address");

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    snprintf(buffer, BUFSIZE, "USER %s\r\n", "username");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    snprintf(buffer, BUFSIZE, "PASS %s\r\n", "password");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    snprintf(buffer, BUFSIZE, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    snprintf(buffer, BUFSIZE, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}