//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <errno.h>

#define MTU 1500
#define PACKET_SIZE 1024
#define PORT 8080
#define TIMEOUT 5 // In seconds

// Function Declarations
void setupSocket(int *sock);
void monitorQoS(int sock);
float calculatePacketLoss(int sent, int received);
void printQoS(float loss, float latency, float jitter);

// Structure to hold QoS statistics
typedef struct {
    int packets_sent;
    int packets_received;
    float latency;
    float jitter;
} QoSStats;

int main() {
    int sock;
    setupSocket(&sock);
    monitorQoS(sock);
    close(sock);
    return 0;
}

void setupSocket(int *sock) {
    *sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (*sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    int optval = 1;
    setsockopt(*sock, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    
    if (bind(*sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind failed");
        close(*sock);
        exit(EXIT_FAILURE);
    }
}

void monitorQoS(int sock) {
    QoSStats stats = {0, 0, 0.0, 0.0};
    fd_set readfds;
    
    char buffer[PACKET_SIZE];
    struct sockaddr_in sender_addr;
    socklen_t addr_len = sizeof(sender_addr);
    
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        // Simulate sending packets
        stats.packets_sent++;
        ssize_t sent_bytes = sendto(sock, "Ping", 4, 0, (struct sockaddr *)&sender_addr, addr_len);
        if (sent_bytes < 0) {
            perror("Send failed");
        }
        sleep(1); // Wait for 1 second before next send
        
        // Prepare for receiving response
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        int activity = select(sock + 1, &readfds, NULL, NULL, &timeout);
        if (activity < 0) {
            perror("Select error");
            continue;
        } else if (activity == 0) {
            printf("Packet lost: Timeout reached\n");
            continue; // Timeout, packet loss
        }

        // Receiving response
        ssize_t recv_bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&sender_addr, &addr_len);
        if (recv_bytes < 0) {
            perror("Receive failed");
        } else {
            stats.packets_received++;
            // Calculate Latency as 1 for simulation
            stats.latency += 1.0; // Placeholder for actual time measurement
            
            // Further processing of received packet could be done here.
        }

        // Print QoS statistics
        float packet_loss = calculatePacketLoss(stats.packets_sent, stats.packets_received);
        printQoS(packet_loss, stats.latency, stats.jitter);
    }
}

float calculatePacketLoss(int sent, int received) {
    if (sent == 0) return 0.0;
    return ((float)(sent - received) / sent) * 100;
}

void printQoS(float loss, float latency, float jitter) {
    printf("QoS Statistics:\n");
    printf("Packet Loss: %.2f%%\n", loss);
    printf("Average Latency: %.2f ms\n", latency); // Convert to ms for real implementation
    printf("Jitter: %.2f ms\n", jitter); // Placeholder
}