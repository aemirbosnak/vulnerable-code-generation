//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXSIZE];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error, no such host\n");
        exit(1);
    }

    memset((void*) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char*) server -> h_addr, (char*) &serv_addr.sin_addr.s_addr, server -> h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    bzero(buffer, MAXSIZE);
    recv(sockfd, buffer, MAXSIZE - 1, 0);

    printf("%s\n", buffer);

    bzero(buffer, MAXSIZE);
    sprintf(buffer, "USER %s\r\n", "example@email.com");

    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, MAXSIZE);
    recv(sockfd, buffer, MAXSIZE - 1, 0);

    printf("%s\n", buffer);

    bzero(buffer, MAXSIZE);
    sprintf(buffer, "PASS %s\r\n", "mypassword");

    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, MAXSIZE);
    recv(sockfd, buffer, MAXSIZE - 1, 0);

    printf("%s\n", buffer);

    bzero(buffer, MAXSIZE);
    sprintf(buffer, "LIST\r\n");

    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, MAXSIZE);
    recv(sockfd, buffer, MAXSIZE - 1, 0);

    printf("%s\n", buffer);

    bzero(buffer, MAXSIZE);
    sprintf(buffer, "RETR %s\r\n", "1");

    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    while ((n = recv(sockfd, buffer, MAXSIZE - 1, 0)) > 0) {
        printf("%s", buffer);
        bzero(buffer, MAXSIZE);
    }

    close(sockfd);

    return 0;
}