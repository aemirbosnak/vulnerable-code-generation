//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define SERVER_PORT    5001
#define SERVER_ADDR    "127.0.0.1"
#define BUF_SIZE        4096

double calculate_speed(uint64_t bytes_transferred, double time_taken) {
    return (bytes_transferred / time_taken) * 8 / 1000000.0;  // Convert to Mbps
}

int main() {
    int sockfd, bytes_received, bytes_sent;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buf[BUF_SIZE], speed_str[32];
    double start_time, end_time, time_taken, speed;
    uint64_t bytes_transferred = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Get the server's IP address
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        return EXIT_FAILURE;
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return EXIT_FAILURE;
    }

    // Send a message to the server
    bytes_sent = send(sockfd, "Hello from client", strlen("Hello from client"), 0);
    if (bytes_sent < 0) {
        perror("send() failed");
        return EXIT_FAILURE;
    }

    // Receive a message from the server
    bytes_received = recv(sockfd, buf, BUF_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv() failed");
        return EXIT_FAILURE;
    }

    // Calculate the time taken for the round trip
    start_time = time(NULL);
    for (int i = 0; i < 10; i++) {
        // Send a large buffer to the server
        memset(buf, 'a', BUF_SIZE);
        bytes_sent = send(sockfd, buf, BUF_SIZE, 0);
        if (bytes_sent < 0) {
            perror("send() failed");
            return EXIT_FAILURE;
        }

        // Receive the echoed buffer from the server
        bytes_received = recv(sockfd, buf, BUF_SIZE, 0);
        if (bytes_received < 0) {
            perror("recv() failed");
            return EXIT_FAILURE;
        }

        bytes_transferred += bytes_received;
    }
    end_time = time(NULL);
    time_taken = difftime(end_time, start_time);

    // Calculate the speed
    speed = calculate_speed(bytes_transferred, time_taken);

    // Print the speed
    sprintf(speed_str, "%.2f Mbps", speed);
    printf("Speed: %s\n", speed_str);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}