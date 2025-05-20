//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>

// Custom data structure to store QoS metrics
typedef struct QoS_Metrics {
    double latency;
    double jitter;
    double packet_loss;
} QoS_Metrics;

// Function to calculate latency
double calculate_latency(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

// Function to calculate jitter
double calculate_jitter(double prev_latency, double curr_latency) {
    return abs(curr_latency - prev_latency);
}

// Function to calculate packet loss
double calculate_packet_loss(int num_packets_sent, int num_packets_received) {
    return 100.0 * (num_packets_sent - num_packets_received) / num_packets_sent;
}

// Function to run the QoS monitor
void run_qos_monitor(char *host, int port) {
    // Initialize QoS metrics
    QoS_Metrics metrics;
    metrics.latency = 0.0;
    metrics.jitter = 0.0;
    metrics.packet_loss = 0.0;

    // Initialize previous latency
    double prev_latency = 0.0;

    // Initialize socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Initialize variables
    int num_packets_sent = 0;
    int num_packets_received = 0;
    char buffer[1024];

    // Run the QoS monitoring loop
    while (1) {
        // Send a packet
        struct timeval start;
        gettimeofday(&start, NULL);
        if (send(sockfd, "ping", 4, 0) < 0) {
            perror("send");
            break;
        }
        num_packets_sent++;

        // Receive a packet
        struct timeval end;
        int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            perror("recv");
            break;
        }
        num_packets_received++;

        // Calculate QoS metrics
        gettimeofday(&end, NULL);
        double latency = calculate_latency(start, end);
        metrics.latency += latency;
        metrics.jitter += calculate_jitter(prev_latency, latency);
        prev_latency = latency;
        metrics.packet_loss = calculate_packet_loss(num_packets_sent, num_packets_received);

        // Print QoS metrics
        printf("Latency: %.2f ms\n", metrics.latency);
        printf("Jitter: %.2f ms\n", metrics.jitter);
        printf("Packet Loss: %.2f %%\n", metrics.packet_loss);
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    // Check arguments
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Run the QoS monitor
    run_qos_monitor(argv[1], atoi(argv[2]));

    return 0;
}