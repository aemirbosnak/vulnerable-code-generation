//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define DEFAULT_COUNT 4
#define TIMEOUT_SECONDS 1

void get_time_diff(struct timeval *start, struct timeval *end, double *diff) {
    *diff = (end->tv_sec - start->tv_sec) + (end->tv_usec - start->tv_usec) / 1000000.0;
}

int ping(const char *ip_addr) {
    int sock;
    struct timeval start, end;
    struct sockaddr_in addr;
    char packet[PACKET_SIZE];
    
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    if (inet_pton(AF_INET, ip_addr, &addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return -1;
    }

    // Initialize packet
    memset(packet, 'A', sizeof(packet));

    // Send packet
    gettimeofday(&start, NULL);
    if (sendto(sock, packet, PACKET_SIZE, 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
        perror("Send failed");
        close(sock);
        return -1;
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SECONDS;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Receive response
    char buffer[PACKET_SIZE];
    socklen_t addr_len = sizeof(addr);
    if (recvfrom(sock, buffer, PACKET_SIZE, 0, (struct sockaddr*)&addr, &addr_len) < 0) {
        if (errno == EWOULDBLOCK) {
            printf("Request timed out.\n");
        } else {
            perror("Receive failed");
        }
        close(sock);
        return -1;
    }
    
    gettimeofday(&end, NULL);
    double elapsed_time;
    get_time_diff(&start, &end, &elapsed_time);
    
    printf("Reply from %s: time=%.2f ms\n", ip_addr, elapsed_time * 1000);
    
    close(sock);
    return 0;
}

int main(int argc, char *argv[]) {
    const char *target_ip;
    int count = DEFAULT_COUNT;

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> [count]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    target_ip = argv[1];

    if (argc == 3) {
        count = atoi(argv[2]);
        if (count <= 0) {
            fprintf(stderr, "Count must be a positive integer\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Pinging %s with %d packets:\n", target_ip, count);
    
    for (int i = 0; i < count; i++) {
        printf("Packet %d: ", i + 1);
        if (ping(target_ip) != 0) {
            printf("Failed to ping.\n");
        }
        sleep(1);
    }

    return 0;
}