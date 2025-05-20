//FormAI DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_PACKET_SIZE 65536 // Maximum size of a UDP packet
#define PING_TIMEOUT 2 // Timeout for ping in seconds
#define PORT 12345 // Port number to send and receive packets
#define MAX_PING_REQUESTS 3 // Maximum number of ping requests to send

// Structure to hold information about a single ping request
struct ping_request {
    struct sockaddr_in dest_addr; // Destination address of ping request
    int seq_number; // Sequence number of ping request
    struct timespec sent_time; // Time ping request was sent
};

// Function to compute the difference in time between two timespec structures
struct timespec timespec_subtract(const struct timespec *time1, const struct timespec *time2) {
    struct timespec result;
    if ((time2->tv_nsec - time1->tv_nsec) < 0) {
        result.tv_sec = time2->tv_sec - time1->tv_sec - 1;
        result.tv_nsec = 1000000000 + time2->tv_nsec - time1->tv_nsec;
    } else {
        result.tv_sec = time2->tv_sec - time1->tv_sec;
        result.tv_nsec = time2->tv_nsec - time1->tv_nsec;
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]); // Print usage if hostname argument is not provided
        exit(1);
    }

    // Resolve hostname to IP address
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;
    int status = getaddrinfo(argv[1], NULL, &hints, &result);
    if (status != 0) {
        perror("getaddrinfo failed");
        exit(1);
    }

    // Create socket for sending and receiving packets
    int sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock_fd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Bind socket to a port for receiving packets
    struct sockaddr_in local_addr;
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(PORT);
    if (bind(sock_fd, (const struct sockaddr *)&local_addr, sizeof(local_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Set socket options for TTL and receive timeout
    int ttl = 64;
    if (setsockopt(sock_fd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt IP_TTL failed");
        exit(1);
    }

    struct timeval recv_timeout;
    recv_timeout.tv_sec = PING_TIMEOUT;
    recv_timeout.tv_usec = 0;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&recv_timeout, sizeof(recv_timeout)) < 0) {
        perror("setsockopt SO_RCVTIMEO failed");
        exit(1);
    }

    // Create an array of ping requests
    struct ping_request requests[MAX_PING_REQUESTS];

    // Fill in destination address for ping requests
    memcpy(&requests[0].dest_addr, result->ai_addr, sizeof(struct sockaddr_in));
    for (int i = 1; i < MAX_PING_REQUESTS; i++) {
        memcpy(&requests[i].dest_addr, &requests[0].dest_addr, sizeof(struct sockaddr_in));
    }

    // Send ping requests and receive ping replies
    for (int i = 0; i < MAX_PING_REQUESTS; i++) {
        requests[i].seq_number = i;

        if (clock_gettime(CLOCK_MONOTONIC_RAW, &requests[i].sent_time) < 0) {
            perror("clock_gettime failed");
            exit(1);
        }

        // Construct UDP packet
        char packet[MAX_PACKET_SIZE];
        memset(packet, 0, MAX_PACKET_SIZE);
        sprintf(packet, "PING %d", requests[i].seq_number);

        // Send UDP packet
        int bytes_sent = sendto(sock_fd, packet, strlen(packet), 0, (const struct sockaddr *)&requests[i].dest_addr, sizeof(requests[i].dest_addr));
        if (bytes_sent < 0) {
            perror("sendto failed");
            exit(1);
        }

        printf("Sent ping request %d to %s\n", requests[i].seq_number, inet_ntoa(requests[i].dest_addr.sin_addr));

        // Receive UDP packet
        char reply[MAX_PACKET_SIZE];
        struct sockaddr_in remote_addr;
        socklen_t addr_len = sizeof(remote_addr);
        int bytes_received = recvfrom(sock_fd, reply, MAX_PACKET_SIZE, 0, (struct sockaddr *)&remote_addr, &addr_len);
        if (bytes_received < 0) {
            perror("recvfrom failed");
            printf("Ping request %d timed out\n", requests[i].seq_number);
        } else {
            // Compute round-trip time and print result
            struct timespec recv_time;
            if (clock_gettime(CLOCK_MONOTONIC_RAW, &recv_time) < 0) {
                perror("clock_gettime failed");
                exit(1);
            }
            struct timespec rtt = timespec_subtract(&requests[i].sent_time, &recv_time);
            printf("Received ping reply %d from %s in %ld.%09ld seconds\n", i, inet_ntoa(remote_addr.sin_addr), rtt.tv_sec, rtt.tv_nsec);
        }
    }

    // Close socket and free addrinfo structure
    close(sock_fd);
    freeaddrinfo(result);

    return 0;
}