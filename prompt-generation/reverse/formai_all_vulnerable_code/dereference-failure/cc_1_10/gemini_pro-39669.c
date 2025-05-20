//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main() {
    // Declare variables
    int sockfd, n, bytes_received, bytes_sent;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char *hostname = "www.google.com";
    char buf[BUF_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Get the server's IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host as %s\n", hostname);
        exit(1);
    }

    // Fill in the server's address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a request to the server
    strcpy(buf, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");
    bytes_sent = send(sockfd, buf, strlen(buf), 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(1);
    }

    // Start the timer
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Receive the response from the server
    bytes_received = 0;
    while (bytes_received < BUF_SIZE) {
        n = read(sockfd, buf + bytes_received, BUF_SIZE - bytes_received);
        if (n < 0) {
            perror("read");
            exit(1);
        }
        bytes_received += n;
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Calculate the download speed
    double download_speed = (bytes_received / elapsed_time) / 1024.0 / 1024.0;

    // Print the download speed
    printf("Download speed: %.2f MB/s\n", download_speed);

    // Close the socket
    close(sockfd);

    return 0;
}