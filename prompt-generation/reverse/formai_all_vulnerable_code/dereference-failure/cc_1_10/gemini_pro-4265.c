//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Get the host and port from the command line arguments
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Resolve the host name to an IP address
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a GET request to the server
    char *request = "GET / HTTP/1.1\nHost: %s\n\n";
    char buf[BUFSIZE];
    snprintf(buf, BUFSIZE, request, host);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    char *response = malloc(BUFSIZE);
    int nbytes;
    while ((nbytes = recv(sockfd, response, BUFSIZE - 1, 0)) > 0) {
        response[nbytes] = '\0';
        printf("%s", response);
    }
    if (nbytes == -1) {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}