//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Get the current time in milliseconds
long long get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
}

// Download a file from a URL
int download_file(char *url, char *filename) {
    // Parse the URL
    struct hostent *host;
    char *hostname;
    char *path;
    char *port;
    if (strstr(url, "://") == NULL) {
        return -1;
    }
    hostname = url + 7;
    path = strchr(hostname, '/');
    if (path == NULL) {
        path = "/";
    } else {
        *path++ = '\0';
    }
    port = strchr(hostname, ':');
    if (port == NULL) {
        port = "80";
    } else {
        *port++ = '\0';
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(atoi(port));
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        return -1;
    }

    // Send the HTTP request
    char request[BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        return -1;
    }

    // Open the file for writing
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return -1;
    }

    // Receive the file data
    char buffer[BUFFER_SIZE];
    int bytes_received;
    long long start_time = get_time_ms();
    long long total_bytes = 0;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
        total_bytes += bytes_received;
    }
    long long end_time = get_time_ms();

    // Close the file and the socket
    fclose(fp);
    close(sockfd);

    // Calculate the download speed
    double speed = (double)total_bytes / (end_time - start_time) * 1000.0 / 1024.0 / 1024.0;

    // Print the download speed
    printf("Download speed: %.2f MB/s\n", speed);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <url> <filename>\n", argv[0]);
        return -1;
    }

    // Download the file
    if (download_file(argv[1], argv[2]) != 0) {
        printf("Error downloading file\n");
        return -1;
    }

    return 0;
}