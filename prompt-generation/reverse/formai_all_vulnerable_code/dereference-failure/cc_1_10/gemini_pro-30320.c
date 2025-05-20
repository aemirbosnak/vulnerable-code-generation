//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define BUFFERSIZE 1024

// Function to get the current time in milliseconds
long long get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
}

// Function to perform the speed test
int speed_test(char *host, int port) {
    int sockfd, n;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        perror("Error getting host by name");
        return -1;
    }
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    // Send a request to the server
    char request[BUFFERSIZE];
    strcpy(request, "GET / HTTP/1.1\r\nHost: ");
    strcat(request, host);
    strcat(request, "\r\n\r\n");
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("Error writing to server");
        return -1;
    }

    // Receive a response from the server
    char response[BUFFERSIZE];
    int total_bytes = 0;
    long long start_time = get_time_ms();
    while ((n = read(sockfd, response, BUFFERSIZE)) > 0) {
        total_bytes += n;
    }
    if (n < 0) {
        perror("Error reading from server");
        return -1;
    }
    long long end_time = get_time_ms();

    // Calculate the speed
    double speed = (double)total_bytes * 8 / (end_time - start_time) / 1000; // in Mbps

    // Close the socket
    close(sockfd);

    return speed;
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host and port
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Perform the speed test
    double speed = speed_test(host, port);
    if (speed < 0) {
        fprintf(stderr, "Error performing speed test\n");
        return EXIT_FAILURE;
    }

    // Print the results
    printf("Speed: %.2f Mbps\n", speed);

    return EXIT_SUCCESS;
}