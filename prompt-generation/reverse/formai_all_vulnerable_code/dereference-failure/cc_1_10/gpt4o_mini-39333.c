//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PING_COUNT 5
#define DEFAULT_PORT 8080
#define DEFAULT_IP "127.0.0.1"

typedef struct {
    char ip[16];
    int port;
    double latency;
} NetworkStats;

// Function to simulate pinging an IP address
double simulate_ping(const char* ip) {
    int sockfd;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    struct timespec start, end;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(DEFAULT_PORT);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    // Send a dummy packet
    clock_gettime(CLOCK_MONOTONIC, &start);
    sendto(sockfd, "Ping", strlen("Ping"), 0, (struct sockaddr *)&addr, sizeof(addr));
    recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);

    close(sockfd);

    // Calculate latency
    double latency = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
    return latency;
}

// Function to monitor network quality from multiple IPs
void* monitor_network_quality(void* arg) {
    NetworkStats* stats = (NetworkStats*)arg;

    printf("Monitoring network quality for IP: %s on Port: %d\n", stats->ip, stats->port);
    double total_latency = 0;
    
    for (int i = 0; i < PING_COUNT; i++) {
        double latency = simulate_ping(stats->ip);
        if (latency != -1) {
            total_latency += latency;
            printf("Ping %d: Latency to %s: %.2f ms\n", i + 1, stats->ip, latency);
        } else {
            printf("Ping %d: Failed to reach %s\n", i + 1, stats->ip);
        }
        sleep(1); // Wait a second before the next ping
    }
    
    stats->latency = total_latency / PING_COUNT;
    printf("Average latency to %s: %.2f ms\n\n", stats->ip, stats->latency);
    return NULL;
}

// Helper function to create threads for each monitor
void start_monitoring(const char* ip, int port) {
    pthread_t thread;
    NetworkStats* stats = malloc(sizeof(NetworkStats));
    strncpy(stats->ip, ip, sizeof(stats->ip) - 1);
    stats->port = port;
    stats->latency = 0;

    pthread_create(&thread, NULL, monitor_network_quality, (void*)stats);
    pthread_detach(thread); // Detach to prevent resource leak
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP1> [IP2] [...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        start_monitoring(argv[i], DEFAULT_PORT);
    }

    // Keep the program running for some time to allow monitoring
    printf("Monitoring network quality. Press Ctrl+C to stop.\n");
    while (1) {
        sleep(10);
    }

    return 0;
}