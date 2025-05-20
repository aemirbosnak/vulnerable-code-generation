//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

// Socket file descriptor
int sockfd;

// Buffer size
#define BUF_SIZE 1024

void create_socket(const char *ip, unsigned short port)
{
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &addr.sin_addr.s_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
}

void send_request(const char *path)
{
    // HTTP request
    char request[BUF_SIZE];
    snprintf(request, BUF_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, "example.com");

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

void receive_response()
{
    // Buffer
    char buf[BUF_SIZE];

    // Receive the response
    int bytes_received;
    while ((bytes_received = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
        // Print the response
        printf("%s", buf);
    }
    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
}

void close_socket()
{
    // Close the socket
    if (close(sockfd) < 0) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create socket
    create_socket(argv[1], atoi(argv[2]));

    // Send request
    send_request("/");

    // Receive response
    receive_response();

    // Close socket
    close_socket();

    return EXIT_SUCCESS;
}