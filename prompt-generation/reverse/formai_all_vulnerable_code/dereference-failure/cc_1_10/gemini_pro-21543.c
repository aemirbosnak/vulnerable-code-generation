//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Function to get the current time in milliseconds
long long get_current_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000 + (long long)ts.tv_nsec / 1000000;
}

// Function to perform the speed test
void speed_test(char *hostname, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create the address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: hostname\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    long long start_time = get_current_time_ms();
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        long long end_time = get_current_time_ms();
        double elapsed_time = (double)(end_time - start_time) / 1000.0;
        double download_speed = (double)bytes_received / elapsed_time;
        printf("Download speed: %.2f MB/s\n", download_speed);
        start_time = end_time;
    }

    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the hostname and port
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Perform the speed test
    speed_test(hostname, port);

    return EXIT_SUCCESS;
}