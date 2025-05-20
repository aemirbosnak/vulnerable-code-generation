//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

// Linus Torvalds style
#define SHUT_UP_AND_CODE 1
#define TALK_IS_CHEAP 0

// Function to get the IP address of a given hostname
char *get_ip_address(char *hostname) {
    struct hostent *host;
    host = gethostbyname(hostname);
    if (host == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    return inet_ntoa(*((struct in_addr *)host->h_addr));
}

// Function to measure the download speed of a given URL
double measure_download_speed(char *url) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Get the IP address of the server
    char *ip_address = get_ip_address(url);

    // Fill in the server's address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip_address);
    servaddr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send an HTTP request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: "
                     ""
                     "\r\n\r\n";
    n = write(sockfd, request, strlen(request));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    // Measure the time it takes to download the response
    clock_t start = clock();
    int bytes_received = 0;
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        bytes_received += n;
    }
    clock_t end = clock();
    double download_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Close the socket
    close(sockfd);

    // Calculate the download speed
    double download_speed = bytes_received / download_time;
    return download_speed;
}

// Function to measure the upload speed of a given URL
double measure_upload_speed(char *url) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Get the IP address of the server
    char *ip_address = get_ip_address(url);

    // Fill in the server's address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip_address);
    servaddr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send an HTTP request to the server
    char request[] = "POST / HTTP/1.1\r\nHost: "
                     ""
                     "\r\nContent-Type: application/octet-stream\r\nContent-Length: 1024\r\n\r\n";
    n = write(sockfd, request, strlen(request));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    // Measure the time it takes to upload the data
    clock_t start = clock();
    int bytes_sent = 0;
    while ((n = write(sockfd, buffer, sizeof(buffer))) > 0) {
        bytes_sent += n;
    }
    clock_t end = clock();
    double upload_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Close the socket
    close(sockfd);

    // Calculate the upload speed
    double upload_speed = bytes_sent / upload_time;
    return upload_speed;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    // Get the URL from the command line
    char *url = argv[1];

    // Measure the download speed
    double download_speed = measure_download_speed(url);

    // Measure the upload speed
    double upload_speed = measure_upload_speed(url);

    // Print the results
    printf("Download speed: %.2f Mbps\n", download_speed);
    printf("Upload speed: %.2f Mbps\n", upload_speed);

    return 0;
}