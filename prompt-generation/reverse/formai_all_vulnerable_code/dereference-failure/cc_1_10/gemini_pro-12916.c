//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    // Get the hostname
    char* hostname = argv[1];

    // Get the IP address
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int err = getaddrinfo(hostname, NULL, &hints, &result);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return 1;
    }

    // Create a socket
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    // Send a request
    char* request = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";
    int n = send(sockfd, request, strlen(request), 0);
    if (n == -1) {
        perror("send");
        return 1;
    }

    // Receive the response
    char buf[BUF_SIZE];
    int total_bytes = 0;
    while (1) {
        n = recv(sockfd, buf, BUF_SIZE, 0);
        if (n == -1) {
            perror("recv");
            return 1;
        }
        if (n == 0) {
            break;
        }
        total_bytes += n;
    }

    // Calculate the speed
    time_t start = time(NULL);
    sleep(1);
    time_t end = time(NULL);
    double speed = (double)total_bytes / (end - start);

    // Print the speed
    printf("Speed: %.2f kB/s\n", speed);

    // Close the socket
    close(sockfd);

    // Free the addrinfo
    freeaddrinfo(result);

    return 0;
}