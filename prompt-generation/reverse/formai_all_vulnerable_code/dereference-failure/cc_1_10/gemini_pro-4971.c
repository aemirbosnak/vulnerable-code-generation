//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_HOPS 30
#define MAX_PACKET_SIZE 1024
#define TIMEOUT 1

// QoS metrics
struct qos_metrics {
    int loss_count;
    int duplicate_count;
    int reordering_count;
    int delay_sum;
    int delay_count;
};

// Packet header
struct packet_header {
    int seq_num;
    int timestamp;
};

// Send a packet and measure the QoS metrics
struct qos_metrics send_packet(int sockfd, const char *host, int port, int seq_num, int prev_timestamp) {
    struct qos_metrics metrics = {0};

    // Create the packet
    struct packet_header header = {seq_num, (int)time(NULL)};
    char packet[MAX_PACKET_SIZE];
    memcpy(packet, &header, sizeof(header));

    // Send the packet
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("sendto");
        exit(1);
    }

    // Receive the response
    struct sockaddr_in recv_addr;
    socklen_t recv_addr_len = sizeof(recv_addr);
    char recv_packet[MAX_PACKET_SIZE];
    if (recvfrom(sockfd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr *)&recv_addr, &recv_addr_len) < 0) {
        perror("recvfrom");
        exit(1);
    }

    // Parse the response
    struct packet_header *recv_header = (struct packet_header *)recv_packet;
    if (recv_header->seq_num != seq_num) {
        metrics.loss_count++;
    } else if (recv_header->timestamp < prev_timestamp) {
        metrics.reordering_count++;
    } else if (recv_header->timestamp == prev_timestamp) {
        metrics.duplicate_count++;
    }

    // Calculate the delay
    metrics.delay_sum += (recv_header->timestamp - header.timestamp);
    metrics.delay_count++;

    return metrics;
}

// Measure the QoS of a network path
struct qos_metrics measure_qos(const char *host, int port, int hops) {
    struct qos_metrics metrics = {0};

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int ttl = hops;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Send and receive packets
    int prev_timestamp = 0;
    for (int i = 0; i < hops; i++) {
        metrics = send_packet(sockfd, host, port, i, prev_timestamp);
        prev_timestamp = metrics.delay_sum / metrics.delay_count;
    }

    // Close the socket
    close(sockfd);

    return metrics;
}

// Print the QoS metrics
void print_metrics(struct qos_metrics metrics) {
    printf("Loss count: %d\n", metrics.loss_count);
    printf("Duplicate count: %d\n", metrics.duplicate_count);
    printf("Reordering count: %d\n", metrics.reordering_count);
    printf("Average delay: %.2f ms\n", (double)metrics.delay_sum / metrics.delay_count);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <host> <port> <hops>\n", argv[0]);
        return 1;
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);
    int hops = atoi(argv[3]);

    struct qos_metrics metrics = measure_qos(host, port, hops);
    print_metrics(metrics);

    return 0;
}