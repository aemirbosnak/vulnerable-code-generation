//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define TEST_SIZE (10 * BUFFER_SIZE) // Size of data to transfer in bytes
#define SERVER_IP "127.0.0.1" // Example localhost for testing
#define SERVER_PORT 8080

// Function to calculate the speed based on time and data size
double calculate_speed(struct timeval start, struct timeval end, size_t data_size) {
    double seconds = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    return (data_size * 8) / seconds; // Speed in bits per second
}

// Function to run the speed test
void run_speed_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *buffer;
    struct timeval start, end;
    
    // Step 1: Create the buffer for sending and receiving data
    buffer = (char *)malloc(BUFFER_SIZE);
    memset(buffer, 'A', BUFFER_SIZE); // Fill buffer with data

    // Step 2: Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation failed");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Step 3: Define server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Step 4: Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Step 5: Perform the speed test
    gettimeofday(&start, NULL); // Start time
    for (size_t total_sent = 0; total_sent < TEST_SIZE; total_sent += BUFFER_SIZE) {
        ssize_t sent_bytes = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (sent_bytes < 0) {
            perror("Send failed");
            close(sockfd);
            free(buffer);
            exit(EXIT_FAILURE);
        }
    }
    gettimeofday(&end, NULL); // End time

    // Step 6: Calculate and display results
    double speed = calculate_speed(start, end, TEST_SIZE);
    printf("Speed: %.2f bits/s\n", speed);

    // Step 7: Clean up
    close(sockfd);
    free(buffer);
}

// Main function
int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please wait while we conduct the test...\n");
    run_speed_test();
    printf("Test completed. Thank you for using our application!\n");
    return 0;
}