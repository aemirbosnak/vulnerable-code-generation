//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>

#define MAX_DATA_SIZE (1<<20) // 1 MB
#define ITERATIONS 10

static void print_usage() {
    fprintf(stderr, "Usage: ./internet_speed_test_app <server_ip_address>\n");
    exit(1);
}

static long long get_current_time_micros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000000 + (long long)tv.tv_usec;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage();
    }

    char* server_ip_address = argv[1];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        fprintf(stderr, "Error setting socket timeout: %s\n", strerror(errno));
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, server_ip_address, &server_addr.sin_addr) != 1) {
        fprintf(stderr, "Error converting IP address to binary: %s\n", strerror(errno));
        exit(1);
    }
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: "
        "example.com\r\nConnection: close\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        fprintf(stderr, "Error sending request to server: %s\n", strerror(errno));
        exit(1);
    }

    // Receive the response from the server
    char response[MAX_DATA_SIZE];
    ssize_t bytes_received = recv(sock, response, MAX_DATA_SIZE, 0);
    if (bytes_received < 0) {
        fprintf(stderr, "Error receiving response from server: %s\n", strerror(errno));
        exit(1);
    }

    // Close the socket
    close(sock);

    // Calculate the download speed
    long long start_time = get_current_time_micros();
    for (int i = 0; i < ITERATIONS; i++) {
        // Send a request to the server
        if (send(sock, request, strlen(request), 0) < 0) {
            fprintf(stderr, "Error sending request to server: %s\n", strerror(errno));
            exit(1);
        }

        // Receive the response from the server
        ssize_t bytes_received = recv(sock, response, MAX_DATA_SIZE, 0);
        if (bytes_received < 0) {
            fprintf(stderr, "Error receiving response from server: %s\n", strerror(errno));
            exit(1);
        }
    }
    long long end_time = get_current_time_micros();
    double download_speed = (double)bytes_received * ITERATIONS * 8 / (end_time - start_time);

    // Print the download speed
    printf("Download speed: %.2f Mbps\n", download_speed);

    return 0;
}