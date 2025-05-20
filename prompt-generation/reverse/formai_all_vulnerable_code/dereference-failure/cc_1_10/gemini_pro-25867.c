//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define SERVER_ADDR "google.com"
#define SERVER_PORT 80
#define BUF_SIZE 1024

// Function to get the current time in milliseconds
long long get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
}

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the server's IP address
    struct hostent *server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char buf[BUF_SIZE];
    int bytes_received = 0;
    long long start_time = get_time_ms();
    while (bytes_received < BUF_SIZE) {
        int n = recv(sock, buf + bytes_received, BUF_SIZE - bytes_received, 0);
        if (n == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }
        bytes_received += n;
    }
    long long end_time = get_time_ms();

    // Calculate the download speed
    double download_speed = (double)bytes_received / (double)(end_time - start_time) * 1000;

    // Print the download speed
    printf("Download speed: %.2f kbps\n", download_speed);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}