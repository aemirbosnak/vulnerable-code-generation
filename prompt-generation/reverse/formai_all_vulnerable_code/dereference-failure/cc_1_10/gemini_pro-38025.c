//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <linux/filter.h>
#include <sys/time.h>

#define BUFSIZE 4096
#define MAX_PKT_LEN 1500

// Custom QoS metrics
typedef struct {
    int num_packets;
    long long total_bytes;
    double avg_latency;
} QoSMetrics;

// Initialize QoS metrics
void init_metrics(QoSMetrics *metrics) {
    metrics->num_packets = 0;
    metrics->total_bytes = 0;
    metrics->avg_latency = 0.0;
}

// Update QoS metrics
void update_metrics(QoSMetrics *metrics, int num_bytes, double latency) {
    metrics->num_packets++;
    metrics->total_bytes += num_bytes;
    metrics->avg_latency = (metrics->avg_latency * (metrics->num_packets - 1) + latency) / metrics->num_packets;
}

// Print QoS metrics
void print_metrics(QoSMetrics *metrics) {
    printf("QoS Metrics:\n");
    printf("Number of packets: %d\n", metrics->num_packets);
    printf("Total bytes: %lld\n", metrics->total_bytes);
    printf("Average latency: %.2f ms\n", metrics->avg_latency);
}

// Custom header for QoS tracking
struct qos_header {
    uint32_t sequence_num;
    uint64_t timestamp;
};

// Create a raw socket and initialize it with the specified IP address and port
int create_socket(char *ip_address, int port) {
    int sockfd;
    struct sockaddr_in addr;

    // Create a raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Bind the socket to the specified IP address and port
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    return sockfd;
}

// Analyze incoming packets and update QoS metrics
void analyze_packets(int sockfd, QoSMetrics *metrics) {
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    uint8_t buf[BUFSIZE];
    struct timeval recv_time;

    while (1) {
        // Receive a packet
        int num_bytes = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&src_addr, &src_addr_len);
        if (num_bytes < 0) {
            perror("recvfrom");
            exit(1);
        }

        // Get the current time
        gettimeofday(&recv_time, NULL);

        // Check if the packet is a QoS tracking packet
        struct qos_header *qos_header = (struct qos_header *)buf;
        if (qos_header->sequence_num != 0) {
            // Calculate the latency
            double latency = (double)(recv_time.tv_sec - qos_header->timestamp / 1000000) * 1000.0 +
                             (double)(recv_time.tv_usec - qos_header->timestamp % 1000000) * 0.001;

            // Update QoS metrics
            update_metrics(metrics, num_bytes - sizeof(struct qos_header), latency);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
        exit(1);
    }

    // Create a raw socket
    int sockfd = create_socket(argv[1], atoi(argv[2]));

    // Initialize QoS metrics
    QoSMetrics metrics;
    init_metrics(&metrics);

    // Analyze incoming packets and update QoS metrics
    analyze_packets(sockfd, &metrics);

    // Print QoS metrics
    print_metrics(&metrics);

    return 0;
}