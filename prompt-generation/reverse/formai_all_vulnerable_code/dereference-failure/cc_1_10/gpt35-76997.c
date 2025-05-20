//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define MAX_HTTP_REQUEST_SIZE 2048
#define MAX_HTTP_RESPONSE_SIZE 2048

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_HTTP_RESPONSE_SIZE];
    char request[MAX_HTTP_REQUEST_SIZE];

    // Check for command line arguments
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Initialize the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid hostname or IP address");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting to server");
    }

    // Send an HTTP GET request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nContent-Type: text/html\r\n\r\n", argv[1]);
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive the HTTP response
    bzero(buffer, MAX_HTTP_RESPONSE_SIZE);
    n = read(sockfd, buffer, MAX_HTTP_RESPONSE_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Print the HTTP response
    printf("\nHTTP Response:\n%s", buffer);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}