//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv) {

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Resolve the hostname to an IP address
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in sockaddr_in;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(port);
    memcpy(&sockaddr_in.sin_addr, hostent->h_addr, hostent->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&sockaddr_in, sizeof(sockaddr_in)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a GET request to the server
    char *request = "GET / HTTP/1.1\r\nHost: " "hostname" "\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    char buffer[1024];
    int nbytes;
    while ((nbytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        if (write(STDOUT_FILENO, buffer, nbytes) < 0) {
            perror("write");
            return 1;
        }
    }

    // Close the socket
    if (close(sockfd) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}