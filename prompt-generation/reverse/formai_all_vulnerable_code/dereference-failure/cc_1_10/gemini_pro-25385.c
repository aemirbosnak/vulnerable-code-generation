//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_ITERATIONS 5
#define DEFAULT_PORT 8080
#define DEFAULT_IP "127.0.0.1"

double calculate_speed(struct timespec start, struct timespec end, size_t bytes_received) {
    double time_elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    return (bytes_received / time_elapsed) / 1e6; // Convert to Mbps
}

int main(int argc, char **argv) {
    // Parse command-line arguments
    char *ip = DEFAULT_IP;
    int port = DEFAULT_PORT;
    if (argc >= 3) {
        ip = argv[1];
        port = atoi(argv[2]);
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n";
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char buffer[BUF_SIZE];
    ssize_t bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, BUF_SIZE, 0)) > 0) {
        printf("%s", buffer);
    }
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Calculate the download speed
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        memset(buffer, 0, BUF_SIZE);
        if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double speed = calculate_speed(start, end, BUF_SIZE * MAX_ITERATIONS);

    // Print the download speed
    printf("Download speed: %.2f Mbps\n", speed);

    // Close the socket
    close(sock);
    return EXIT_SUCCESS;
}