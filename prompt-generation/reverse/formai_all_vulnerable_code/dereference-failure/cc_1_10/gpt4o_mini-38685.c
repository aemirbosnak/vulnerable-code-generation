//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <time.h>

// Define the number of packets to monitor
#define PACKET_COUNT 5
#define PING_INTERVAL 1

// Structure to store the QoS data
typedef struct {
    char ip_address[16];
    int packet_loss;
    double avg_response_time;
    double max_response_time;
} QoSData;

// Function to ping a host and return the response time
double ping_host(const char *host) {
    struct timespec start, end;
    double elapsed;

    // Create a socket for ICMP
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Prepare the sockaddr_in structure for the host
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return -1;
    }

    // Start the timer
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Send a packet
    if (sendto(sockfd, "Ping", 4, 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Send failed");
        close(sockfd);
        return -1;
    }

    // Wait for a response
    char buffer[1024];
    socklen_t addr_len = sizeof(addr);
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len) < 0) {
        perror("Receive failed");
        close(sockfd);
        return -1;
    }

    // Stop the timer
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    
    close(sockfd);
    return elapsed / 1e6; // Convert to milliseconds
}

// Function to monitor QoS
void monitor_qos(QoSData *qos_data) {
    double total_response_time = 0;
    double max_response_time = 0;
    int packet_received = 0;

    printf("Pinging %s...\n", qos_data->ip_address);
    
    for (int i = 0; i < PACKET_COUNT; i++) {
        sleep(PING_INTERVAL);
        double response_time = ping_host(qos_data->ip_address);
        
        if (response_time >= 0) {
            total_response_time += response_time;
            packet_received++;
            if (response_time > max_response_time) {
                max_response_time = response_time;
            }
            printf("Reply from %s: time=%.2f ms\n", qos_data->ip_address, response_time);
        } else {
            printf("Request timed out for %s\n", qos_data->ip_address);
        }
    }

    if (packet_received > 0) {
        qos_data->packet_loss = (PACKET_COUNT - packet_received) * 100 / PACKET_COUNT;
        qos_data->avg_response_time = total_response_time / packet_received;
        qos_data->max_response_time = max_response_time;

        printf("\n--- QoS Statistics for %s ---\n", qos_data->ip_address);
        printf("Packets: Sent = %d, Received = %d, Lost = %d (%.2f%% loss)\n",
               PACKET_COUNT, packet_received, PACKET_COUNT - packet_received,
               qos_data->packet_loss);
        printf("Avg response time = %.2f ms, Max response time = %.2f ms\n",
               qos_data->avg_response_time, qos_data->max_response_time);
    } else {
        printf("All packets lost.\n");
        qos_data->packet_loss = 100;
        qos_data->avg_response_time = 0;
        qos_data->max_response_time = 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize QoSData
    QoSData qos_data;
    strncpy(qos_data.ip_address, argv[1], sizeof(qos_data.ip_address));

    // Monitor QoS
    monitor_qos(&qos_data);

    return EXIT_SUCCESS;
}