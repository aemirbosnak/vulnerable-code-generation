//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <pthread.h>

#define PACKET_SIZE 4096
#define DEFAULT_PORT 8080
#define MONITOR_INTERVAL 5

typedef struct {
    int total_packets;
    int lost_packets;
    float average_latency;
} QoSStats;

QoSStats qos_stats;

void *monitor_qos(void *arg);
bool send_packet(const char *ip, int port);
void receive_packet(int port);
void print_qos_stats();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *target_ip = argv[1];
    int target_port = atoi(argv[2]);

    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitor_qos, NULL);

    while (true) {
        if (send_packet(target_ip, target_port)) {
            qos_stats.total_packets++;
        } else {
            qos_stats.lost_packets++;
        }
        
        receive_packet(target_port);
        sleep(MONITOR_INTERVAL);
    }

    pthread_join(monitor_thread, NULL);
    return 0;
}

void *monitor_qos(void *arg) {
    while (true) {
        print_qos_stats();
        sleep(MONITOR_INTERVAL);
    }
    return NULL;
}

bool send_packet(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return false;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    char packet[PACKET_SIZE] = "Ping!";
    socklen_t addr_len = sizeof(server_addr);

    ssize_t sent_bytes = sendto(sockfd, packet, strlen(packet), 0,
                                 (struct sockaddr*)&server_addr, addr_len);
    close(sockfd);

    return sent_bytes > 0;
}

void receive_packet(int port) {
    int sockfd;
    struct sockaddr_in local_addr, src_addr;
    socklen_t addr_len = sizeof(src_addr);
    char buffer[PACKET_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(port);
    bind(sockfd, (struct sockaddr*)&local_addr, sizeof(local_addr));

    ssize_t recv_bytes = recvfrom(sockfd, buffer, PACKET_SIZE, 0,
                                   (struct sockaddr*)&src_addr, &addr_len);

    if (recv_bytes > 0) {
        qos_stats.average_latency += (float)(MONITOR_INTERVAL) / 2; // Dummy latency calculation
        printf("Received packet from %s:%d\n",
               inet_ntoa(src_addr.sin_addr), ntohs(src_addr.sin_port));
    } else {
        printf("No packet received\n");
    }

    close(sockfd);
}

void print_qos_stats() {
    printf("QoS Statistics:\n");
    printf("Total Packets Sent: %d\n", qos_stats.total_packets);
    printf("Lost Packets: %d\n", qos_stats.lost_packets);
    printf("Average Latency: %.2f ms\n", qos_stats.average_latency);
    printf("=====================\n");
    // Reset stats for next interval
    qos_stats.average_latency = 0;
}