//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main() {
    // Get the hostname of the server
    char hostname[256];
    printf("Enter the hostname of the server you want to test: ");
    scanf("%s", hostname);

    // Get the IP address of the server
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        printf("Could not resolve hostname %s\n", hostname);
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *) host->h_addr);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        return -1;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";
    if (send(sockfd, request, sizeof(request), 0) < 0) {
        perror("Could not send request to server");
        return -1;
    }

    // Receive the response from the server
    char buf[BUF_SIZE];
    int bytes_received = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while ((bytes_received = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
        gettimeofday(&end, NULL);
        bytes_received += bytes_received;
    }

    // Calculate the download speed
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double download_speed = bytes_received / elapsed_time;

    // Print the download speed
    printf("Download speed: %.2f MB/s\n", download_speed / 1024 / 1024);

    // Close the socket
    close(sockfd);

    return 0;
}