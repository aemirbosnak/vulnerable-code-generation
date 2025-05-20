//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define BLOCK_SIZE 1024 * 1024 // 1 MB for testing speed
#define TEST_DURATION 5 // in seconds

void print_speed(double speed, const char *type) {
    printf("Estimated %s speed: %.2f Mbps\n", type, speed);
}

double calculate_speed(struct timeval start, struct timeval end, size_t data_size) {
    double elapsed_time_sec = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double bits = data_size * 8; // Convert bytes to bits
    return (bits / (1024 * 1024)) / elapsed_time_sec; // Mbps
}

void simulate_download_speed(int sockfd) {
    char *buffer = (char *)malloc(BUFFER_SIZE);
    ssize_t bytes_received;
    size_t total_received = 0;
    struct timeval start, end;

    // Start measuring time
    gettimeofday(&start, NULL);
    
    while (total_received < BLOCK_SIZE) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error receiving data");
            free(buffer);
            return;
        }
        total_received += bytes_received;
    }

    // Stop measuring time
    gettimeofday(&end, NULL);
    
    double download_speed = calculate_speed(start, end, total_received);
    print_speed(download_speed, "Download");
    
    free(buffer);
}

void simulate_upload_speed(int sockfd) {
    char *buffer = (char *)malloc(BUFFER_SIZE);
    memset(buffer, 'A', BUFFER_SIZE); // Fill with dummy data
    ssize_t bytes_sent;
    size_t total_sent = 0;
    struct timeval start, end;

    // Start measuring time
    gettimeofday(&start, NULL);
    
    while (total_sent < BLOCK_SIZE) {
        bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            perror("Error sending data");
            free(buffer);
            return;
        }
        total_sent += bytes_sent;
    }

    // Stop measuring time
    gettimeofday(&end, NULL);
    
    double upload_speed = calculate_speed(start, end, total_sent);
    print_speed(upload_speed, "Upload");
    
    free(buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr)); 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Local server
    server_addr.sin_port = htons(SERVER_PORT); 

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    printf("Starting Internet Speed Test...\n");
    
    // Simulate download speed testing
    printf("Testing download speed...\n");
    simulate_download_speed(sockfd);
    
    // Simulate upload speed testing
    printf("Testing upload speed...\n");
    simulate_upload_speed(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}