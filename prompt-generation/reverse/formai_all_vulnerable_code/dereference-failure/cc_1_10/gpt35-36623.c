//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold Network Metrics
struct NetworkMetrics {
    char *ipAddress;
    double bandwidth;
    int packetLoss;
    int latency;
};

// Function to initialize network metrics and return a pointer
struct NetworkMetrics *initializeMetrics(char *ip, double bw, int pl, int lt) {
    struct NetworkMetrics *metrics = (struct NetworkMetrics *) malloc(sizeof(struct NetworkMetrics));
    metrics->ipAddress = ip;
    metrics->bandwidth = bw;
    metrics->packetLoss = pl;
    metrics->latency = lt;
    return metrics;
}

// Function to update metrics based on QoS thresholds
void updateMetrics(struct NetworkMetrics *metrics) {
    // Check Bandwidth
    if (metrics->bandwidth < 50.0) {
        printf("Low Bandwidth detected. Current bandwidth: %.2f Mbps. Updating...\n", metrics->bandwidth);
        metrics->bandwidth = 50.0;
    }

    // Check Packet Loss
    if (metrics->packetLoss > 0) {
        printf("Packet Loss detected. Current loss rate: %d%%. Updating...\n", metrics->packetLoss);
        metrics->packetLoss = 0;
    }

    // Check Latency
    if (metrics->latency > 100) {
        printf("High Latency detected. Current latency: %d ms. Updating...\n", metrics->latency);
        metrics->latency = 100;
    }
}

int main() {
    struct NetworkMetrics *metrics = initializeMetrics("192.168.1.1", 100.0, 0, 50);

    printf("Initial Network Metrics:\n");
    printf("IP Address: %s\n", metrics->ipAddress);
    printf("Bandwidth: %.2f Mbps\n", metrics->bandwidth);
    printf("Packet Loss Rate: %d%%\n", metrics->packetLoss);
    printf("Latency: %d ms\n\n", metrics->latency);

    srand(time(0)); // Seed for Random Number Generation

    // Simulate Network Metrics every 5 seconds and update based on QoS thresholds
    while (1) {
        printf("Simulating Network Metrics...\n");

        // Generate Random Values for Metrics
        double bandwidth = (double) rand() / RAND_MAX * 100.0;
        int packetLoss = rand() % 10;
        int latency = rand() % 200;

        printf("New Metrics:\n");
        printf("IP Address: %s\n", metrics->ipAddress);
        printf("Bandwidth: %.2f Mbps\n", bandwidth);
        printf("Packet Loss Rate: %d%%\n", packetLoss);
        printf("Latency: %d ms\n\n", latency);

        // Update Metrics based on QoS thresholds
        metrics->bandwidth = bandwidth;
        metrics->packetLoss = packetLoss;
        metrics->latency = latency;
        updateMetrics(metrics);

        // Wait for 5 seconds before simulating next set of Metrics
        sleep(5);
    }

    return 0;
}