//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define DEFAULT_HOST "google.com"
#define DEFAULT_PORT 80

struct test_result {
    double download_speed;
    double upload_speed;
};

struct test_result test_internet_speed(const char *host, int port) {
    struct test_result result = {0, 0};
    struct hostent *host_entry;
    struct sockaddr_in server_addr;
    int sockfd;
    char buffer[1024];
    int bytes_sent, bytes_received;
    struct timeval start_time, end_time;
    double download_time, upload_time;

    // Resolve the hostname to an IP address
    host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("gethostbyname");
        return result;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return result;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host_entry->h_addr_list[0];

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return result;
    }

    // Send a request to the server
    bytes_sent = send(sockfd, "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: google.com\r\n\r\n"), 0);
    if (bytes_sent == -1) {
        perror("send");
        return result;
    }

    // Start the timer
    gettimeofday(&start_time, NULL);

    // Receive the response from the server
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        return result;
    }

    // Stop the timer
    gettimeofday(&end_time, NULL);

    // Calculate the download time
    download_time = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    // Calculate the download speed
    result.download_speed = (double)bytes_received / download_time;

    // Send a request to the server
    bytes_sent = send(sockfd, "POST / HTTP/1.1\r\nHost: google.com\r\nContent-Length: 1024\r\n\r\n", strlen("POST / HTTP/1.1\r\nHost: google.com\r\nContent-Length: 1024\r\n\r\n"), 0);
    if (bytes_sent == -1) {
        perror("send");
        return result;
    }

    // Start the timer
    gettimeofday(&start_time, NULL);

    // Send the data to the server
    bytes_sent = send(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_sent == -1) {
        perror("send");
        return result;
    }

    // Stop the timer
    gettimeofday(&end_time, NULL);

    // Calculate the upload time
    upload_time = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    // Calculate the upload speed
    result.upload_speed = (double)bytes_sent / upload_time;

    // Close the socket
    close(sockfd);

    return result;
}

int main(int argc, char *argv[]) {
    char *host = DEFAULT_HOST;
    int port = DEFAULT_PORT;
    struct test_result result;

    // Parse the command line arguments
    if (argc > 1) {
        host = argv[1];
    }
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    // Test the internet speed
    result = test_internet_speed(host, port);

    // Print the results
    printf("Download speed: %.2f Mbps\n", result.download_speed);
    printf("Upload speed: %.2f Mbps\n", result.upload_speed);

    return 0;
}