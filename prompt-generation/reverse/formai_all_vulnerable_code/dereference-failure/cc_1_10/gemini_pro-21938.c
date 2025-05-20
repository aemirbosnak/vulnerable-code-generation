//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Defines the maximum size for the HTTP request and response
#define MAX_HTTP_LENGTH 4096

// Initializes the socket for the HTTP client
int init_socket(char *host, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Creates a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Sets the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    // Connects to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return -1;
    }

    return sockfd;
}

// Sends the HTTP request to the server
int send_http_request(int sockfd, char *request) {
    int ret = send(sockfd, request, strlen(request), 0);
    if (ret < 0) {
        perror("send");
        return -1;
    }

    return ret;
}

// Receives the HTTP response from the server
int recv_http_response(int sockfd, char *response) {
    int ret = recv(sockfd, response, MAX_HTTP_LENGTH, 0);
    if (ret < 0) {
        perror("recv");
        return -1;
    }

    return ret;
}

// Closes the socket
void close_socket(int sockfd) {
    close(sockfd);
}

// Entry point of the HTTP client
int main(int argc, char **argv) {
    int sockfd, ret;
    char request[MAX_HTTP_LENGTH], response[MAX_HTTP_LENGTH];

    // Checks the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return -1;
    }

    // Initializes the HTTP client
    sockfd = init_socket(argv[1], atoi(argv[2]));
    if (sockfd < 0) {
        return -1;
    }

    // Creates the HTTP request
    snprintf(request, MAX_HTTP_LENGTH, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

    // Sends the HTTP request
    ret = send_http_request(sockfd, request);
    if (ret < 0) {
        close_socket(sockfd);
        return -1;
    }

    // Receives the HTTP response
    ret = recv_http_response(sockfd, response);
    if (ret < 0) {
        close_socket(sockfd);
        return -1;
    }

    // Prints the HTTP response
    printf("%s\n", response);

    // Closes the socket
    close_socket(sockfd);

    return 0;
}