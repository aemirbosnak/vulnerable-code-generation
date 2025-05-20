//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: secure
// C program to send an email using SMTP Client

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

void error(char* msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char** argv) {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    char buffer[1024];
    char message[2048];

    if (argc < 4) {
        fprintf(stderr, "usage: %s hostname port message\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    sprintf(message,"From: sender@domain.com\r\nTo: receiver@domain.com\r\nSubject: Test E-mail\r\n\r\n%s\r\n.\r\n", argv[3]);

    n = write(sockfd, "HELO\r\n", strlen("HELO\r\n"));

    if (n < 0) {
        error("ERROR sending message");
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1024);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, "mail from: <sender@domain.com>\r\n", strlen("mail from: <sender@domain.com>\r\n"));

    if (n < 0) {
        error("ERROR sending message");
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1024);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, "rcpt to: <receiver@domain.com>\r\n", strlen("rcpt to: <receiver@domain.com>\r\n"));

    if (n < 0) {
        error("ERROR sending message");
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1024);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, "data\r\n", strlen("data\r\n"));

    if (n < 0) {
        error("ERROR sending message");
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1024);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, message, strlen(message));

    if (n < 0) {
        error("ERROR sending message");
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1024);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, "quit\r\n", strlen("quit\r\n"));

    if (n < 0) {
        error("ERROR sending message");
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1024);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}