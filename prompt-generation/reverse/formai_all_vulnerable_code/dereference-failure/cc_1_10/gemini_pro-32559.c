//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

// Forward declarations
int create_socket(const char *hostname, const char *port);
void send_request(int sockfd, const char *request);
void receive_response(int sockfd, char *response);
void close_socket(int sockfd);

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Extract the hostname and port number from the command line arguments
    const char *hostname = argv[1];
    const char *port = argv[2];

    // Create a socket
    int sockfd = create_socket(hostname, port);

    // Send the HTTP request
    const char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    send_request(sockfd, request);

    // Receive the HTTP response
    char response[4096];
    receive_response(sockfd, response);

    // Print the HTTP response
    printf("%s", response);

    // Close the socket
    close_socket(sockfd);

    return 0;
}

int create_socket(const char *hostname, const char *port) {
    // Get the address info for the hostname and port
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int err = getaddrinfo(hostname, port, &hints, &res);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        exit(1);
    }

    // Create a socket
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    err = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (err == -1) {
        perror("connect");
        exit(1);
    }

    // Free the address info
    freeaddrinfo(res);

    return sockfd;
}

void send_request(int sockfd, const char *request) {
    // Send the request
    int len = strlen(request);
    int sent = 0;
    while (sent < len) {
        int n = send(sockfd, request + sent, len - sent, 0);
        if (n == -1) {
            perror("send");
            exit(1);
        }
        sent += n;
    }
}

void receive_response(int sockfd, char *response) {
    // Receive the response
    int len = 0;
    while (1) {
        int n = recv(sockfd, response + len, 4096 - len, 0);
        if (n == -1) {
            perror("recv");
            exit(1);
        } else if (n == 0) {
            break;
        }
        len += n;
    }
}

void close_socket(int sockfd) {
    // Close the socket
    close(sockfd);
}