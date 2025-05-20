//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define TIMEOUT_SECONDS 2

// Structure to hold our QoS metrics
typedef struct {
    int packet_loss;
    float latency;
    float jitter;
} QoSMetrics;

// Function to create a UDP socket
int create_udp_socket() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to send a packet and measure latency
float send_packet(int sockfd, struct sockaddr_in *addr, int packet_number) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "Packet number: %d", packet_number);
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int sent_bytes = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)addr, sizeof(*addr));
    if (sent_bytes < 0) {
        perror("Error sending packet");
        exit(EXIT_FAILURE);
    }

    char recv_buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(*addr);
    recvfrom(sockfd, recv_buffer, BUFFER_SIZE, 0, (struct sockaddr *)addr, &addr_len);

    gettimeofday(&end, NULL);
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0; // Return latency in ms
}

// Function to monitor QoS metrics
QoSMetrics monitor_qos(const char *ip, int port, int packets_to_send) {
    QoSMetrics metrics = {0, 0.0, 0.0};
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    int sockfd = create_udp_socket();
    
    float previous_latency = 0.0;
    for (int i = 0; i < packets_to_send; i++) {
        float latency = send_packet(sockfd, &addr, i);
        metrics.latency += latency;

        if (latency > previous_latency) {
            metrics.jitter += (latency - previous_latency);
        }
        previous_latency = latency;

        usleep(100000); // Sleep for 100ms between packets
    }

    metrics.latency /= packets_to_send; // Average latency
    metrics.jitter /= (packets_to_send - 1); // Average jitter
    close(sockfd);
    return metrics;
}

// Function to display the QoS metrics
void display_metrics(QoSMetrics metrics) {
    printf("---------------------------------------------------\n");
    printf("Quality of Service (QoS) Metrics\n");
    printf("---------------------------------------------------\n");
    printf("Average Latency: %.2f ms\n", metrics.latency);
    printf("Jitter: %.2f ms\n", metrics.jitter);
    printf("Packet Loss: %d%%\n", metrics.packet_loss); // Not calculated in this example, assumed to be 0%
    printf("---------------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);

    printf("Starting QoS monitor for %s:%d...\n", ip, port);
    
    int packets_to_send = 10; // Example: send 10 packets
    QoSMetrics metrics = monitor_qos(ip, port, packets_to_send);

    display_metrics(metrics);

    return EXIT_SUCCESS;
}