//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define MAXLINE 1024

void http_client(const char *hostname, const char *port, const char *path) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Create a sockaddr_in struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the HTTP request
    char request[MAXLINE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the HTTP response
    char response[MAXLINE];
    int n;
    while ((n = recv(sockfd, response, MAXLINE, 0)) > 0) {
        // Print the response to stdout
        printf("%s", response);
    }

    if (n == -1) {
        perror("recv");
        exit(1);
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port path\n", argv[0]);
        exit(1);
    }

    http_client(argv[1], argv[2], argv[3]);

    return 0;
}