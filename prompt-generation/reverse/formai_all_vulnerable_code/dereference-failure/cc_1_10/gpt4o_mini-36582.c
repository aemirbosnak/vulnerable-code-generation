//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

// Defines the size of data to be sent for speed testing in bytes
#define DATA_SIZE 1500000  // 1.5 MB

// Function to create a TCP socket and connect to the server
int create_socket(const char *server_ip, const int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Convert IPv4 address from text to binary
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to perform the speed test
void speed_test(const char *server_ip, int port) {
    char *buffer = (char *)malloc(DATA_SIZE);
    if (!buffer) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Fill buffer with dummy data
    memset(buffer, 'A', DATA_SIZE);

    // Create a socket and connect to the server
    int sockfd = create_socket(server_ip, port);

    // Measure send time
    clock_t start = clock();
    int total_sent = 0;
    while (total_sent < DATA_SIZE) {
        int bytes_sent = send(sockfd, buffer + total_sent, DATA_SIZE - total_sent, 0);
        if (bytes_sent < 0) {
            perror("Send failed");
            free(buffer);
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        total_sent += bytes_sent;
    }
    clock_t end = clock();

    // Calculate time taken and speed
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; 
    double speed_mbps = (total_sent * 8) / (time_taken * 1e6);  // Convert to Mbps

    printf("Total data sent: %d bytes\n", total_sent);
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Speed: %.2f Mbps\n", speed_mbps);

    // Clean up
    free(buffer);
    close(sockfd);
}

// Entry point of the program
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    int port = atoi(argv[2]);

    // Perform the speed test
    speed_test(server_ip, port);
    
    return EXIT_SUCCESS;
}