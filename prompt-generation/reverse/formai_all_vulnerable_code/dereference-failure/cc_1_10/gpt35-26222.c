//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 2048

typedef struct {
    int total_packets;
    int lost_packets;
    float loss_chance;
    float arrival_rate;
    float throughput;
    float average_delay;
    float max_delay;
    float jitter;
} QoS_stats;

void calculate_statistics(char* buffer, QoS_stats* stats) {
    int total_packets = 0, lost_packets = 0;
    float delay_sum = 0.0, max_delay = 0.0, jitter = 0.0;
    char* token = strtok(buffer, "\n");
    while (token != NULL) {
        total_packets++;
        char* end_ptr;
        int packet_id = strtol(token, &end_ptr, 10);
        if (end_ptr == token) {
            // Invalid packet format, skip
            token = strtok(NULL, "\n");
            continue;
        }
        if (packet_id != total_packets) {
            lost_packets++;
        } else {
            // Packet arrived correctly
            float packet_delay = strtof(end_ptr, NULL);
            delay_sum += packet_delay;
            if (packet_delay > max_delay) {
                max_delay = packet_delay;
            }
            if (total_packets > 1) {
                jitter += abs(packet_delay - stats->average_delay);
            }
        }
        token = strtok(NULL, "\n");
    }
    stats->total_packets = total_packets;
    stats->lost_packets = lost_packets;
    stats->loss_chance = (float) lost_packets / (float) total_packets;
    stats->arrival_rate = (1.0 - stats->loss_chance) * stats->throughput;
    stats->average_delay = delay_sum / (float) (total_packets - lost_packets);
    stats->max_delay = max_delay;
    stats->jitter = jitter / (float) (total_packets - 2);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: qos_monitor <port>\n");
        return 1;
    }
    int port = atoi(argv[1]);

    int socket_fd;
    if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        fprintf(stderr, "Could not create socket\n");
        return 1;
    }

    int optval = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        fprintf(stderr, "Could not set socket options\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Could not bind socket\n");
        return 1;
    }

    QoS_stats stats = {0};
    char buffer[MAX_SIZE];
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    while (1) {
        int bytes_received = recvfrom(socket_fd, buffer, MAX_SIZE - 1, 0, (struct sockaddr*) &client_addr, &client_addr_len);
        if (bytes_received < 0) {
            fprintf(stderr, "Could not receive packet\n");
            continue;
        }
        buffer[bytes_received] = '\0';

        calculate_statistics(buffer, &stats);

        printf("Total packets: %d\n", stats.total_packets);
        printf("Lost packets: %d\n", stats.lost_packets);
        printf("Loss chance: %.2f%%\n", stats.loss_chance * 100);
        printf("Arrival rate: %.2f packets/second\n", stats.arrival_rate);
        printf("Throughput: %.2f bytes/second\n", stats.throughput);
        printf("Average delay: %.2f milliseconds\n", stats.average_delay);
        printf("Max delay: %.2f milliseconds\n", stats.max_delay);
        printf("Jitter: %.2f milliseconds\n", stats.jitter);

        // Reset stats (may not be necessary based on requirements)
        memset(&stats, 0, sizeof(stats));
    }

    close(socket_fd);
    return 0;
}