//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
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

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    struct timeval start, end;
    char buf[BUF_SIZE];
    long elapsed;
    float speed;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port number>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Get the current time
    gettimeofday(&start, NULL);

    // Send a request to the server
    memset(buf, 0, BUF_SIZE);
    strcpy(buf, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(1);
    }

    // Receive the response from the server
    memset(buf, 0, BUF_SIZE);
    n = read(sockfd, buf, BUF_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }

    // Get the current time
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    // Calculate the speed
    speed = (float)n * 8 / elapsed;

    // Print the speed
    printf("Speed: %.2f Mbps\n", speed);

    // Close the socket
    close(sockfd);

    return 0;
}