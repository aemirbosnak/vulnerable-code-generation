//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080 // Change to your server port
#define BUFFER_SIZE 8192 // Buffer size for data transfer
#define TEST_SIZE (10 * 1024 * 1024) // 10 MB for test

// Function declarations
void uploadTest(int sockfd);
void downloadTest(int sockfd);
void calculateSpeed(double timeTaken, size_t dataSize);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    // Replace "127.0.0.1" with your server address
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        return EXIT_FAILURE;
    }

    printf("Connected to server. Starting upload test...\n");
    uploadTest(sockfd);

    printf("Starting download test...\n");
    downloadTest(sockfd);

    // Close socket
    close(sockfd);
    return 0;
}

void uploadTest(int sockfd) {
    char *data = (char*)malloc(TEST_SIZE);
    memset(data, 'A', TEST_SIZE); // Fill the buffer with dummy data
    size_t totalBytesSent = 0;
    time_t startTime, endTime;
    double elapsedTime;

    // Start the timer
    startTime = time(NULL);
    while (totalBytesSent < TEST_SIZE) {
        ssize_t bytesSent = send(sockfd, data + totalBytesSent, TEST_SIZE - totalBytesSent, 0);
        if (bytesSent < 0) {
            perror("Upload failed");
            free(data);
            return;
        }
        totalBytesSent += bytesSent;
    }
    // Stop the timer
    endTime = time(NULL);
    
    // Calculate speed
    elapsedTime = difftime(endTime, startTime);
    calculateSpeed(elapsedTime, totalBytesSent);
    
    free(data);
}

void downloadTest(int sockfd) {
    char buffer[BUFFER_SIZE];
    size_t totalBytesReceived = 0;
    time_t startTime, endTime;
    double elapsedTime;

    // Start the timer
    startTime = time(NULL);
    while (totalBytesReceived < TEST_SIZE) {
        ssize_t bytesReceived = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytesReceived < 0) {
            perror("Download failed");
            return;
        } else if (bytesReceived == 0) {
            break; // Server closed the connection
        }
        totalBytesReceived += bytesReceived;
    }
    // Stop the timer
    endTime = time(NULL);

    // Calculate speed
    elapsedTime = difftime(endTime, startTime);
    calculateSpeed(elapsedTime, totalBytesReceived);
}

void calculateSpeed(double timeTaken, size_t dataSize) {
    double speedMbps = (dataSize * 8) / (1024.0 * 1024.0) / timeTaken;
    printf("Test completed.\n");
    printf("Data size: %.2f MB\n", dataSize / (1024.0 * 1024.0));
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Speed: %.2f Mbps\n", speedMbps);
}