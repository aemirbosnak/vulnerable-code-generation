//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_REQUEST_LENGTH 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char request[MAX_REQUEST_LENGTH] = {'\0'};
    char response[MAX_REQUEST_LENGTH] = {'\0'};

    char *host = "www.example.com"; // Default host name
    char *resource = "/"; // Default resource path

    if (argc > 1) {
        host = argv[1];
        resource = argv[2] ? argv[2] : "/";
    }

    printf("Making HTTP request to %s%s\n", host, resource);

    portno = 80;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(host);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", resource, host);

    n = write(sockfd, request, strlen(request));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(response, MAX_REQUEST_LENGTH);

    n = read(sockfd, response, MAX_REQUEST_LENGTH);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("Server response:\n%s", response);

    close(sockfd);

    return 0;
}