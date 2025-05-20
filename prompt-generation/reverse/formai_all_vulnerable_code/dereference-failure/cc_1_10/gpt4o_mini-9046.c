//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "8.8.8.8" // Google's public DNS server
#define PACKET_SIZE 64
#define TIMEOUT 1 // seconds
#define PING_COUNT 5

void print_title() {
    printf("\n\n🎉 Dynamic Network Quality of Service (QoS) Monitor 🎉\n");
    printf("=====================================\n");
    printf("Monitoring Latency to %s...\n", SERVER_IP);
    printf("\n");
}

double ping_server(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in server_addr;
    char packet[PACKET_SIZE];
    struct timeval start, end;
    double time_taken;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1.0;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = 0; // No port for ICMP
    inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

    memset(packet, 0, PACKET_SIZE);
    gettimeofday(&start, NULL);

    // Send packet (simple ICMP echo request)
    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) <= 0) {
        perror("Failed to send packet");
        close(sockfd);
        return -1.0;
    }

    // Wait for response with timeout
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    if (select(sockfd + 1, &readfds, NULL, NULL, &tv) > 0) {
        // Receive packet
        recvfrom(sockfd, packet, PACKET_SIZE, 0, NULL, NULL);
        gettimeofday(&end, NULL);

        // Calculate latency
        time_taken = (end.tv_sec - start.tv_sec) * 1000.0; // Convert to milliseconds
        time_taken += (end.tv_usec - start.tv_usec) / 1000.0; // Add microseconds
    } else {
        printf("Request timed out.\n");
        time_taken = -1.0;
    }

    close(sockfd);
    return time_taken;
}

void monitor_qos() {
    for (int i = 0; i < PING_COUNT; i++) {
        double latency = ping_server(SERVER_IP);
        
        if (latency >= 0) {
            printf("Ping #%d: Latency = %.2f ms\n", i + 1, latency);
        } else {
            printf("Ping #%d: Error occurred\n", i + 1);
        }
        sleep(1); // Wait before the next ping
    }
}

int main() {
    print_title();
    monitor_qos();
    printf("\nDone monitoring! 🎈\n");
    return 0;
}