//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
/* 
 * The following program is a HTTP client implemented in C, inspired by the versatile Donald Knuth.
 * As always, Knuth's style will be followed with clean and thoughtful code.
 * This program uses sockets to send HTTP requests and receive responses.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT "80" // Default HTTP port
#define MAX_BUFFER_SIZE 1024 // Maximum buffer size to read response.

// Error message handler.
void errorHandler(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Resolve host to IP address.
int resolveHost(char *host, char *ipAddr) {
    struct addrinfo hints, *servinfo, *p;
    int res;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((res = getaddrinfo(host, PORT, &hints, &servinfo)) != 0) {
        return -1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        void *addr;

        if (p->ai_family == AF_INET) //IPv4
            addr = &((struct sockaddr_in *)p->ai_addr)->sin_addr;
        else
            addr = &((struct sockaddr_in6 *)p->ai_addr)->sin6_addr; //IPv6

        inet_ntop(p->ai_family, addr, ipAddr, INET6_ADDRSTRLEN);

        break;
    }

    freeaddrinfo(servinfo);

    if (p == NULL) {
        return -1;
    }

    return 0;
}

int main() {
    int sockfd;
    struct addrinfo hints, *p, *servinfo;
    char *host = "www.google.com";
    char *message = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    char buffer[MAX_BUFFER_SIZE];
    char ipAddr[INET6_ADDRSTRLEN];

    if (resolveHost(host, ipAddr) != 0) {
        errorHandler("resolveHost error");
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ipAddr, PORT, &hints, &servinfo) != 0) {
        errorHandler("getaddrinfo error");
    }

    // Traverse the linked list servinfo and create socket.
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        errorHandler("failed to connect");
    }

    freeaddrinfo(servinfo);

    // Send HTTP request.
    if (send(sockfd, message, strlen(message), 0) == -1) {
        errorHandler("send error");
    }

    printf("HTTP request sent...\n");

    // Receive HTTP response.
    int bytesReceived;
    while ((bytesReceived = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytesReceived] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}