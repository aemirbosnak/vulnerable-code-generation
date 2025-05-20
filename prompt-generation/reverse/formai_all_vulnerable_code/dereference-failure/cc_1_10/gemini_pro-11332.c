//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFERSIZE 1024

int main() {
    // Get the server's IP address
    struct hostent *host = gethostbyname("www.google.com");
    if (!host) {
        perror("gethostbyname");
        return -1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Send a request to the server
    const char *request = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return -1;
    }

    // Receive the response from the server
    char buffer[BUFFERSIZE];
    int bytes_received = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while ((bytes_received = recv(sockfd, buffer, BUFFERSIZE, 0)) > 0) {
        gettimeofday(&end, NULL);
    }
    if (bytes_received < 0) {
        perror("recv");
        return -1;
    }

    // Calculate the download speed
    double download_speed = (double)bytes_received / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);
    printf("Download speed: %.2f KB/s\n", download_speed);

    // Close the socket
    close(sockfd);

    return 0;
}