//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <server IP address> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a request to the server
    strcpy(buffer, "GET / HTTP/1.1\r\nHost: ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    int total_bytes = 0;
    while ((n = recv(sockfd, buffer, BUFSIZE, 0)) > 0) {
        total_bytes += n;
    }
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    // Calculate the download speed
    double speed = (double)total_bytes / 1024 / 1024;
    printf("Download speed: %.2f MB/s\n", speed);

    // Close the socket
    close(sockfd);

    return 0;
}