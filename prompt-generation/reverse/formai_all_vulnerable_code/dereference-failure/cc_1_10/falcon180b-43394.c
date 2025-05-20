//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, newsockfd;
    struct addrinfo server;
    struct addrinfo *servinfo = NULL;
    struct sockaddr_in *saddr = NULL;
    int opt = 1;
    char buffer[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Initialize address structure
    memset(&server, 0, sizeof(server));
    server.ai_family = AF_INET;
    server.ai_socktype = SOCK_STREAM;

    // Get address information for server
    if (getaddrinfo("localhost", "8080", &server, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(servinfo->ai_family));
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send request to server
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sockfd);

    // Print response
    printf("Response:\n%s", buffer);

    return 0;
}