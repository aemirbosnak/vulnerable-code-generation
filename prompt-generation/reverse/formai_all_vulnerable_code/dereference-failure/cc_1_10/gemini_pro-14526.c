//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send an HTTP request
    char request[BUFSIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the HTTP response
    char response[BUFSIZE];
    int n;
    while ((n = recv(sockfd, response, BUFSIZE, 0)) > 0) {
        fwrite(response, 1, n, stdout);
    }
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return 0;
}