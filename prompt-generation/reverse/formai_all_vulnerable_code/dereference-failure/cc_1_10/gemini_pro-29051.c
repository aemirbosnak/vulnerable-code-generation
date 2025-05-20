//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

// Function to get the current time in milliseconds
long long get_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

int main() {
    // Create a socket for sending and receiving data
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the socket options for QoS
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Get the IP address of the host
    struct hostent *host = gethostbyname("www.google.com");
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Create a sockaddr_in structure for the host
    struct sockaddr_in host_addr;
    memset(&host_addr, 0, sizeof(host_addr));
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(80);
    memcpy(&host_addr.sin_addr, host->h_addr, host->h_length);

    // Create a buffer for the data to be sent
    char buffer[1024];
    memset(buffer, '\0', sizeof(buffer));

    // Create a buffer for the data to be received
    char recv_buffer[1024];
    memset(recv_buffer, '\0', sizeof(recv_buffer));

    // Start the QoS monitoring loop
    while (1) {
        // Get the current time
        long long start_time = get_time_ms();

        // Send a request to the host
        if (sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&host_addr, sizeof(host_addr)) < 0) {
            perror("sendto");
            continue;
        }

        // Receive the response from the host
        socklen_t recv_len = sizeof(host_addr);
        int recv_bytes = recvfrom(sockfd, recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr *)&host_addr, &recv_len);
        if (recv_bytes < 0) {
            perror("recvfrom");
            continue;
        }

        // Get the current time
        long long end_time = get_time_ms();

        // Calculate the round-trip time
        long long rtt = end_time - start_time;

        // Print the QoS metrics
        printf("Round-trip time: %lld ms\n", rtt);
    }

    // Close the socket
    close(sockfd);

    return 0;
}