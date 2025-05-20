//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// HTTP request
char *http_request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

// Send HTTP request
int send_http_request(int sockfd) {
    // Send the HTTP request
    int nbytes = send(sockfd, http_request, strlen(http_request), 0);
    if (nbytes < 0) {
        perror("send()");
        return -1;
    }

    return 0;
}

// Receive HTTP response
int receive_http_response(int sockfd) {
    // Receive the HTTP response
    char buffer[4096];
    int nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (nbytes < 0) {
        perror("recv()");
        return -1;
    }

    // Print the HTTP response
    printf("%s", buffer);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided a hostname
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return -1;
    }

    // Get the hostname
    char *hostname = argv[1];

    // Get the IP address of the hostname
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        perror("gethostbyname()");
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket()");
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = *((in_addr_t *)hostent->h_addr);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        return -1;
    }

    // Send the HTTP request
    if (send_http_request(sockfd) < 0) {
        return -1;
    }

    // Receive the HTTP response
    if (receive_http_response(sockfd) < 0) {
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}