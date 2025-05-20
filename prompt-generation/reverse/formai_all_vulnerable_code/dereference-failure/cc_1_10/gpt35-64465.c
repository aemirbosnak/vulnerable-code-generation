//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024 * 1024 * 10  // 10 MB
#define PORT 5000
#define IP_ADDRESS "127.0.0.1"

double get_time() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec + currentTime.tv_usec / 1000000.0;  // Get current time in seconds
}

double test_download_speed() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_aton(IP_ADDRESS, &server_address.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to the server");
        exit(1);
    }

    char *buffer = malloc(BUFFER_SIZE);
    double start_time = get_time();
    ssize_t n_bytes_read = 0;

    do {
        ssize_t bytes_read = read(sock, buffer, BUFFER_SIZE);  // Read data from the server
        if (bytes_read < 0) {
            perror("Failed to read from server");
            exit(1);
        }
        n_bytes_read += bytes_read;
    } while (n_bytes_read < BUFFER_SIZE);

    double end_time = get_time();
    double download_time = end_time - start_time; // Calculate time taken to download 10MB of data
    free(buffer);
    close(sock);
    return (BUFFER_SIZE / (download_time * 1024 * 1024)); // Return download speed in Mbps
}

double test_upload_speed() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_aton(IP_ADDRESS, &server_address.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to the server");
        exit(1);
    }

    char *buffer = malloc(BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = rand() % 256; // Fill buffer with random data
    }

    double start_time = get_time();
    ssize_t n_bytes_sent = 0;

    do {
        ssize_t bytes_sent = write(sock, buffer, BUFFER_SIZE);  // Send data to server
        if (bytes_sent < 0) {
            perror("Failed to send data");
            exit(1);
        }
        n_bytes_sent += bytes_sent;
    } while (n_bytes_sent < BUFFER_SIZE);

    double end_time = get_time();
    double upload_time = end_time - start_time; // Calculate time taken to upload 10MB of data
    free(buffer);
    close(sock);
    return (BUFFER_SIZE / (upload_time * 1024 * 1024)); // Return upload speed in Mbps
}

int main() {
    double download_speed = test_download_speed();
    double upload_speed = test_upload_speed();
    printf("Download speed = %.2f Mbps\n", download_speed);
    printf("Upload speed = %.2f Mbps\n", upload_speed);
    return 0;
}