//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUFFER_SIZE 8192
#define TEST_DURATION 10

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", program_name);
}

void perform_download_test(const char *server_ip, int server_port) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    struct timeval start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start time for download test
    gettimeofday(&start_time, NULL);

    long total_bytes = 0;
    time_t elapsed_time = 0;

    while (elapsed_time < TEST_DURATION) {
        bytes_read = read(sockfd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            break; // Stop reading if connection closes or on error
        }
        total_bytes += bytes_read;

        // Measure elapsed time after each read for accuracy
        gettimeofday(&end_time, NULL);
        elapsed_time = end_time.tv_sec - start_time.tv_sec;
    }

    close(sockfd);

    // Calculate throughput
    double speed_mbps = (total_bytes * 8.0) / (elapsed_time * 1024 * 1024);
    printf("Download Speed: %.2f Mbps\n", speed_mbps);
}

void perform_upload_test(const char *server_ip, int server_port) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_sent;
    struct timeval start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start time for upload test
    gettimeofday(&start_time, NULL);

    long total_bytes = 0;
    time_t elapsed_time = 0;

    // Fill the buffer with dummy data
    memset(buffer, 'A', BUFFER_SIZE);
    
    while (elapsed_time < TEST_DURATION) {
        bytes_sent = write(sockfd, buffer, BUFFER_SIZE);
        if (bytes_sent < 0) {
            perror("Error sending data");
            break;
        }
        total_bytes += bytes_sent;

        // Measure elapsed time after each write for accuracy
        gettimeofday(&end_time, NULL);
        elapsed_time = end_time.tv_sec - start_time.tv_sec;
    }

    close(sockfd);

    // Calculate throughput
    double speed_mbps = (total_bytes * 8.0) / (elapsed_time * 1024 * 1024);
    printf("Upload Speed: %.2f Mbps\n", speed_mbps);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    printf("Starting Internet Speed Test...\n");

    perform_download_test(server_ip, server_port);
    perform_upload_test(server_ip, server_port);

    printf("Test completed.\n");
    return 0;
}