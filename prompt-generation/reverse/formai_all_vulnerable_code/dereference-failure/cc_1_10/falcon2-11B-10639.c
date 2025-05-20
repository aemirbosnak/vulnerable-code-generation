//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <client_port>\n", argv[0]);
        return 1;
    }

    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    int addrlen = sizeof(cliaddr);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set up server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Create a socket for the client
    newsockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (newsockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set up client address
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_addr.s_addr = inet_addr(argv[3]);
    cliaddr.sin_port = htons(atoi(argv[4]));

    // Connect to client
    if (connect(newsockfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read request from client
    char buffer[1024];
    int n = read(newsockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }

    // Send request to server
    write(sockfd, buffer, n);

    // Read response from server
    buffer[n] = '\0';
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }

    // Send response to client
    write(newsockfd, buffer, n);

    // Close connections
    close(sockfd);
    close(newsockfd);

    return 0;
}