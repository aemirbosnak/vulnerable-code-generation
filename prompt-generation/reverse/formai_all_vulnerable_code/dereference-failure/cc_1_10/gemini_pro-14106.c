//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

#define MAX_DOWNLOAD_SIZE 1024 * 1024 // 1MB
#define MAX_PING_ATTEMPTS 5

// Function to calculate the difference between two timevals
long int timeval_diff(struct timeval *start, struct timeval *end) {
    long int diff = (end->tv_sec - start->tv_sec) * 1000000 + (end->tv_usec - start->tv_usec);
    return diff;
}

// Function to perform a ping test
long int ping_test(char *hostname) {
    struct sockaddr_in addr;
    struct timeval start, end;
    int sockfd, rc;
    long int elapsed;

    // Create a socket for the ping test
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Set the destination address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ((struct in_addr *)host->h_addr)->s_addr;

    // Send a ping request
    char ping_request[1024];
    memset(ping_request, 0, sizeof(ping_request));
    size_t ping_request_size = sizeof(ping_request);
    gettimeofday(&start, NULL);
    rc = sendto(sockfd, ping_request, ping_request_size, 0, (struct sockaddr *)&addr, sizeof(addr));
    if (rc < 0) {
        perror("sendto");
        close(sockfd);
        return -1;
    }

    // Wait for a ping response
    char ping_response[1024];
    memset(ping_response, 0, sizeof(ping_response));
    size_t ping_response_size = sizeof(ping_response);
    struct pollfd pfd;
    pfd.fd = sockfd;
    pfd.events = POLLIN;
    gettimeofday(&end, NULL);
    elapsed = timeval_diff(&start, &end);
    while (elapsed < 1000 && poll(&pfd, 1, 10) > 0) {
        rc = recvfrom(sockfd, ping_response, ping_response_size, 0, (struct sockaddr *)&addr, &ping_response_size);
        if (rc < 0) {
            perror("recvfrom");
            close(sockfd);
            return -1;
        }
        gettimeofday(&end, NULL);
        elapsed = timeval_diff(&start, &end);
    }

    // Calculate the ping time
    if (elapsed >= 1000) {
        fprintf(stderr, "Ping timeout\n");
        close(sockfd);
        return -1;
    }
    elapsed = timeval_diff(&start, &end);

    // Close the socket
    close(sockfd);

    return elapsed;
}

// Function to perform a download speed test
long int download_speed_test(char *url) {
    struct sockaddr_in addr;
    struct timeval start, end;
    int sockfd, rc;
    long int elapsed, total_bytes_received;
    char buffer[MAX_DOWNLOAD_SIZE];

    // Create a socket for the download speed test
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(url);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Set the destination address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ((struct in_addr *)host->h_addr)->s_addr;
    addr.sin_port = htons(80);

    // Connect to the server
    rc = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (rc < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send an HTTP GET request
    char http_request[1024];
    memset(http_request, 0, sizeof(http_request));
    sprintf(http_request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
    size_t http_request_size = strlen(http_request);
    gettimeofday(&start, NULL);
    rc = send(sockfd, http_request, http_request_size, 0);
    if (rc < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the HTTP response
    total_bytes_received = 0;
    while (1) {
        rc = recv(sockfd, buffer, sizeof(buffer), 0);
        if (rc < 0) {
            perror("recv");
            close(sockfd);
            return -1;
        }
        if (rc == 0) {
            break;
        }
        total_bytes_received += rc;
    }

    // Calculate the download speed
    gettimeofday(&end, NULL);
    elapsed = timeval_diff(&start, &end);
    if (elapsed == 0) {
        return -1;
    }
    long int download_speed = total_bytes_received * 8 / elapsed; // in bits per second

    // Close the socket
    close(sockfd);

    return download_speed;
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname or URL>\n", argv[0]);
        return 1;
    }

    // Perform a ping test
    long int ping_time = ping_test(argv[1]);
    if (ping_time == -1) {
        fprintf(stderr, "Ping test failed\n");
        return 1;
    }
    printf("Ping time: %ld ms\n", ping_time);

    // Perform a download speed test
    long int download_speed = download_speed_test(argv[1]);
    if (download_speed == -1) {
        fprintf(stderr, "Download speed test failed\n");
        return 1;
    }
    printf("Download speed: %ld bps\n", download_speed);

    return 0;
}