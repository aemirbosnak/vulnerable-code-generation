//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "speed.hetzner.de" // Example speed test server (make sure it's reachable)
#define SERVER_PORT 80
#define BUFFER_SIZE 8192

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void download_test(int sockfd) {
    char request[1024];
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    size_t total_bytes = 0;

    // Prepare a simple GET request
    snprintf(request, sizeof(request), "GET /1MB.bin HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);
    
    // Send request to server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Failed to send request");
    }

    // Receive the response
    clock_t start_time = clock();
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        total_bytes += bytes_received;
    }
    if (bytes_received < 0) {
        handle_error("Failed to receive data");
    }
    clock_t end_time = clock();

    // Calculate download speed
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double speed_mbps = (total_bytes * 8) / (1024 * 1024 * elapsed_time); // Convert to Mbps
    printf("Downloaded %zu bytes in %.2f seconds.\n", total_bytes, elapsed_time);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

void upload_test(int sockfd) {
    char request[1024];
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    const size_t data_size = 1 * 1024 * 1024; // 1MB data
    char *data = malloc(data_size);
    memset(data, 'A', data_size); // Fill with dummy data

    // Prepare POST request header
    snprintf(request, sizeof(request), "POST /upload HTTP/1.1\r\nHost: %s\r\nContent-Length: %zu\r\nConnection: close\r\n\r\n", SERVER_IP, data_size);
    
    // Send request to server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Failed to send upload request");
    }
    total_bytes += send(sockfd, data, data_size, 0);
    if (total_bytes < 0) {
        handle_error("Failed to send data");
    }
    
    // Measure upload time
    clock_t start_time = clock();
    recv(sockfd, buffer, sizeof(buffer), 0); // Wait for response
    clock_t end_time = clock();

    // Calculate upload speed
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double speed_mbps = (total_bytes * 8) / (1024 * 1024 * elapsed_time); // Convert to Mbps
    printf("Uploaded %zu bytes in %.2f seconds.\n", total_bytes, elapsed_time);
    printf("Upload speed: %.2f Mbps\n", speed_mbps);
    
    free(data);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/Address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    printf("Starting download speed test...\n");
    download_test(sockfd);
    
    // To ensure we do not reuse the same socket for both tests,
    // we close the previous connection.
    close(sockfd);
    
    // Create socket again for upload test
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }
    
    // Reconnect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    printf("Starting upload speed test...\n");
    upload_test(sockfd);

    // Cleanup
    close(sockfd);
    return 0;
}