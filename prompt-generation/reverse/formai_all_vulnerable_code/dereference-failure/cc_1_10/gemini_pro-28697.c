//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define BUFSIZE 1024

// Get the current time in milliseconds
long long get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

// Measure the download speed from a server
int measure_download_speed(const char *host, int port) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];
    long long start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Start the timer
    start_time = get_time_ms();

    // Download the file
    while ((n = read(sockfd, buf, BUFSIZE)) > 0) {
        // Do nothing with the data
    }
    if (n < 0) {
        perror("read");
        close(sockfd);
        return -1;
    }

    // Stop the timer
    end_time = get_time_ms();

    // Calculate the download speed
    int download_speed = (int)((BUFSIZE * 8) / (end_time - start_time));

    // Close the socket
    close(sockfd);

    return download_speed;
}

// Print the download speed
void print_download_speed(int download_speed) {
    printf("Download speed: %d kbps\n", download_speed);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Measure the download speed
    int download_speed = measure_download_speed(argv[1], atoi(argv[2]));
    if (download_speed < 0) {
        perror("measure_download_speed");
        return 1;
    }

    // Print the download speed
    print_download_speed(download_speed);

    return 0;
}