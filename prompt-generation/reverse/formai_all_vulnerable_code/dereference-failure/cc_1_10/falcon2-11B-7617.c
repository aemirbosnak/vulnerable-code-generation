//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080

int main() {
    struct addrinfo *server, *result;
    int rv, i;
    char buf[1024];
    char *host, *port;
    int sockfd;
    int r;

    host = "localhost";
    port = "80";

    // Get server address info
    rv = getaddrinfo(host, port, NULL, &server);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // Get first result
    result = server;

    while (result!= NULL) {
        struct sockaddr_in *sin = (struct sockaddr_in *) result->ai_addr;
        sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
            perror("connect");
            continue;
        }

        printf("Connected to server %s:%s\n", inet_ntoa(sin->sin_addr),
               inet_ntop(AF_INET, &sin->sin_port, buf, sizeof(buf)));

        // Handle incoming HTTP request
        printf("Receiving HTTP request\n");
        r = read(sockfd, buf, sizeof(buf));
        if (r <= 0) {
            perror("read");
            continue;
        }
        printf("Received %d bytes of HTTP request\n", r);

        printf("Forwarding HTTP request to server\n");
        write(sockfd, buf, r);
        r = read(sockfd, buf, sizeof(buf));
        if (r <= 0) {
            perror("read");
            continue;
        }
        printf("Received %d bytes of HTTP response\n", r);

        printf("Sending HTTP response back to client\n");
        write(sockfd, buf, r);
        break;
    }

    // Clean up
    freeaddrinfo(server);
    close(sockfd);
    return 0;
}