//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* hostname = argv[1];
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", hostname);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: socket() failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    memcpy(&serv_addr.sin_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: connect() failed");
        return EXIT_FAILURE;
    }

    char request[] = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char buf[BUF_SIZE];
    int nbytes;

    // Send the HTTP request
    nbytes = sprintf(buf, request, hostname);
    if (send(sockfd, buf, nbytes, 0) < 0) {
        perror("Error: send() failed");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response
    clock_t start = clock();
    int total_bytes = 0;
    while ((nbytes = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
        total_bytes += nbytes;
    }
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the download speed in KB/s
    double download_speed = (double)total_bytes / elapsed_time / 1024;

    // Print the download speed
    printf("Download speed: %.2f KB/s\n", download_speed);

    close(sockfd);
    return EXIT_SUCCESS;
}