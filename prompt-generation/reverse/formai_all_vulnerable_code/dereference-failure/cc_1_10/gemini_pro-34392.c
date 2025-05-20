//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define HTTP_PORT 80
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    // Get the hostname from the command line
    char *hostname = argv[1];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(HTTP_PORT);
    addr.sin_addr = *(struct in_addr *) host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the HTTP request
    char request[] = "GET / HTTP/1.1\nHost: ";
    strcat(request, hostname);
    strcat(request, "\nConnection: close\n\n");
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the HTTP response
    char response[MAX_LINE];
    while (recv(sockfd, response, MAX_LINE, 0) > 0) {
        printf("%s", response);
    }

    // Close the socket
    close(sockfd);

    return 0;
}