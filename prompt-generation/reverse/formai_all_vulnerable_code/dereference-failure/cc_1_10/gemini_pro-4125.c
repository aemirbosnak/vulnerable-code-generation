//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUF_SIZE];
    struct timeval start, end;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    memset(buf, 'A', BUF_SIZE);
    gettimeofday(&start, NULL);
    n = write(sockfd, buf, BUF_SIZE);
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the server
    memset(buf, 0, BUF_SIZE);
    gettimeofday(&end, NULL);
    n = read(sockfd, buf, BUF_SIZE);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Calculate the time taken for the round trip
    double elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    // Calculate the bandwidth
    double bandwidth = (BUF_SIZE * 8) / (elapsed / 1000.0);

    // Print the results
    printf("Round trip time: %.2f ms\nBandwidth: %.2f Mbps\n", elapsed, bandwidth);

    close(sockfd);
    return 0;
}