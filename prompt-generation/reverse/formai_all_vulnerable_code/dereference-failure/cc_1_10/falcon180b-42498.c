//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

// Function to print error message and exit
void error(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[MAX_LINE];
    int rv;
    int numbytes;

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info for server
    if ((rv = getaddrinfo("localhost", "8080", &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    // Create socket
    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype,
        servinfo->ai_protocol);
    if (sockfd == -1) {
        error("socket");
    }

    // Connect to server
    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        error("connect");
    }

    // Send request to server
    sprintf(s, "GET / HTTP/1.0\r\nHost: localhost\r\n\r\n");
    numbytes = send(sockfd, s, strlen(s), 0);
    if (numbytes == -1) {
        error("send");
    }

    // Receive response from server
    memset(s, 0, MAX_LINE);
    numbytes = recv(sockfd, s, MAX_LINE, 0);
    if (numbytes == -1) {
        error("recv");
    }
    printf("%s", s);

    // Close socket
    close(sockfd);

    return 0;
}