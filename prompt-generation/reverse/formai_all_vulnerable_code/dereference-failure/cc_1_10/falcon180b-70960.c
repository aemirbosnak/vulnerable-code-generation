//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *serverinfo;
    struct addrinfo hints;
    char *hostname = argv[1];
    char *port = argv[2];
    int rv;

    // Initialize hints
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info
    if ((rv = getaddrinfo(hostname, port, &hints, &serverinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol)) == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    // Send request
    char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    // Receive response
    char buffer[4096];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer + bytes_received, sizeof(buffer) - bytes_received, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    // Close socket
    close(sockfd);

    return 0;
}