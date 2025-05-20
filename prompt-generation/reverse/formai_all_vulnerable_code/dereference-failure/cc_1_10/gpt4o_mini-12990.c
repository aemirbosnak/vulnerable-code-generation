//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_URL "http://example.com/testfile" // change this to a real endpoint
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

double download_speed_test(const char *url) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    double total_bytes = 0;
    time_t start_time, end_time;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) 
        error("ERROR opening socket");

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, "93.184.216.34", &server_addr.sin_addr); // example.com IP for demonstration

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    // Send HTTP GET request
    char request[256];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n", "/testfile");
    write(sock, request, strlen(request));

    start_time = time(NULL);

    // Receive data
    while ((bytes_received = read(sock, buffer, sizeof(buffer))) > 0) {
        total_bytes += bytes_received;
    }
    end_time = time(NULL);
    
    close(sock);

    double seconds = difftime(end_time, start_time);
    double speed_mbps = (total_bytes * 8) / (seconds * 1000000); // Convert to Mbps
    return speed_mbps;
}

double upload_speed_test(const char *url, const char *file_path) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_sent;
    double total_bytes = 0;
    time_t start_time, end_time;

    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Could not open file for upload");
        return -1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) 
        error("ERROR opening socket");

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, "93.184.216.34", &server_addr.sin_addr); // example.com IP for demonstration

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    // Prepare HTTP PUT request
    // Here just simulating upload with POST, more complex for real file uploads
    char request[256];
    snprintf(request, sizeof(request), "POST /upload HTTP/1.1\r\nHost: example.com\r\nContent-Length: %ld\r\nConnection: close\r\n\r\n", 
             strlen(buffer));
   
    write(sock, request, strlen(request));
    
    start_time = time(NULL);

    // Send the file
    while ((bytes_sent = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(sock, buffer, bytes_sent, 0);
        total_bytes += bytes_sent;
    }

    end_time = time(NULL);
    fclose(file);
    close(sock);

    double seconds = difftime(end_time, start_time);
    double speed_mbps = (total_bytes * 8) / (seconds * 1000000); // Convert to Mbps
    return speed_mbps;
}

int main() {
    printf("Starting Internet Speed Test...\n");
    
    double download_speed = download_speed_test(SERVER_URL);
    if (download_speed < 0) {
        printf("Download test failed.\n");
    } else {
        printf("Download Speed: %.2f Mbps\n", download_speed);
    }

    double upload_speed = upload_speed_test(SERVER_URL, "testfile.txt"); // Ensure this file exists
    if (upload_speed < 0) {
        printf("Upload test failed.\n");
    } else {
        printf("Upload Speed: %.2f Mbps\n", upload_speed);
    }

    printf("Speed Test Completed.\n");
    return 0;
}