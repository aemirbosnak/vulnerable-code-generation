//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>

#define DEFAULT_PORT 5001
#define DEFAULT_IP "127.0.0.1"
#define PACKET_SIZE 1024

// Structure to store the QoS metrics
typedef struct {
    double jitter;
    double packet_loss;
    double delay;
} qos_metrics_t;

// Function to calculate the jitter
double calculate_jitter(struct timeval *timestamps, int num_timestamps) {
    double jitter = 0.0;
    for (int i = 1; i < num_timestamps; i++) {
        long long int diff = (timestamps[i].tv_sec - timestamps[i - 1].tv_sec) * 1000000 + (timestamps[i].tv_usec - timestamps[i - 1].tv_usec);
        jitter += abs(diff - (timestamps[i - 1].tv_sec - timestamps[i - 2].tv_sec) * 1000000 + (timestamps[i - 1].tv_usec - timestamps[i - 2].tv_usec));
    }
    return jitter / num_timestamps;
}

// Function to calculate the packet loss
double calculate_packet_loss(int num_packets_sent, int num_packets_received) {
    return 100.0 * (num_packets_sent - num_packets_received) / num_packets_sent;
}

// Function to calculate the delay
double calculate_delay(struct timeval *timestamps, int num_timestamps) {
    double delay = 0.0;
    for (int i = 0; i < num_timestamps; i++) {
        delay += (timestamps[i].tv_sec - timestamps[0].tv_sec) * 1000000 + (timestamps[i].tv_usec - timestamps[0].tv_usec);
    }
    return delay / num_timestamps;
}

// Function to send a packet
void send_packet(int sockfd, struct sockaddr_in *servaddr, char *buffer, int len) {
    if (sendto(sockfd, buffer, len, 0, (struct sockaddr *)servaddr, sizeof(*servaddr)) < 0) {
        perror("sendto");
        exit(1);
    }
}

// Function to receive a packet
void receive_packet(int sockfd, char *buffer, int len) {
    if (recvfrom(sockfd, buffer, len, 0, NULL, NULL) < 0) {
        perror("recvfrom");
        exit(1);
    }
}

// Function to monitor the QoS
void *monitor_qos(void *args) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[PACKET_SIZE];
    int num_packets_sent = 0;
    int num_packets_received = 0;
    struct timeval *timestamps;
    int num_timestamps = 0;

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(DEFAULT_PORT);
    if (inet_pton(AF_INET, DEFAULT_IP, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Allocate memory for the timestamps
    timestamps = malloc(sizeof(struct timeval) * PACKET_SIZE);
    if (timestamps == NULL) {
        perror("malloc");
        exit(1);
    }

    while (1) {
        // Send a packet
        send_packet(sockfd, &servaddr, buffer, PACKET_SIZE);
        num_packets_sent++;

        // Receive a packet
        receive_packet(sockfd, buffer, PACKET_SIZE);
        num_packets_received++;

        // Get the timestamp
        gettimeofday(&timestamps[num_timestamps], NULL);
        num_timestamps++;

        // Calculate the QoS metrics
        qos_metrics_t qos_metrics;
        qos_metrics.jitter = calculate_jitter(timestamps, num_timestamps);
        qos_metrics.packet_loss = calculate_packet_loss(num_packets_sent, num_packets_received);
        qos_metrics.delay = calculate_delay(timestamps, num_timestamps);

        // Print the QoS metrics
        printf("Jitter: %.2f ms\n", qos_metrics.jitter);
        printf("Packet loss: %.2f %%\n", qos_metrics.packet_loss);
        printf("Delay: %.2f ms\n\n", qos_metrics.delay);
    }

    // Free the memory for the timestamps
    free(timestamps);

    // Close the socket
    close(sockfd);

    return NULL;
}

int main() {
    pthread_t thread;

    // Create a thread to monitor the QoS
    if (pthread_create(&thread, NULL, monitor_qos, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}