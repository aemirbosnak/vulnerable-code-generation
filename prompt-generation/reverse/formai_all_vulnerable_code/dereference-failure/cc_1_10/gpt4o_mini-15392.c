//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 8192

void print_usage() {
    printf("Usage: speedtest <file_size_in_MB>\n");
}

int connect_to_server(const char *ip_address) {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    return sock;
}

double download_file(int sock, long long file_size) {
    char buffer[BUFFER_SIZE];
    long long total_received = 0;
    ssize_t bytes_received;
    time_t start_time = time(NULL);

    while (total_received < file_size) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error
        }
        total_received += bytes_received;
    }

    time_t end_time = time(NULL);
    double duration = difftime(end_time, start_time);
    
    if (duration == 0) {
        printf("Download completed in 0 seconds, might have encountered an issue!\n");
        return 0;
    }

    return (double)total_received / (1024 * 1024) * 8 / duration; // Speed in Mbps
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    long long file_size = atoll(argv[1]) * 1024 * 1024; // Convert MB to bytes
    const char *server_ip = "127.0.0.1"; // Local server for testing

    int sock = connect_to_server(server_ip);
    if (sock < 0) {
        return EXIT_FAILURE;
    }

    double speed = download_file(sock, file_size);
    close(sock);

    if (speed > 0) {
        printf("Download Speed: %.2f Mbps\n", speed);
    } else {
        printf("Failed to measure the download speed.\n");
    }

    return EXIT_SUCCESS;
}