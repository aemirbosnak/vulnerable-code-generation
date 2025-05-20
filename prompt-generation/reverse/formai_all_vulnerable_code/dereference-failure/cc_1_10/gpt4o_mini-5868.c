//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define DEFAULT_PORT 8080
#define PACKET_SIZE 64
#define MAX_BUFFER 1500

typedef struct {
    struct sockaddr_in address;
    int sockfd;
    char buffer[MAX_BUFFER];
    int packet_count;
    time_t start_time;
} QoSMonitor;

void init_qos_monitor(QoSMonitor *monitor, int port) {
    monitor->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (monitor->sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&(monitor->address), 0, sizeof(monitor->address));
    monitor->address.sin_family = AF_INET;
    monitor->address.sin_addr.s_addr = INADDR_ANY;
    monitor->address.sin_port = htons(port);

    if (bind(monitor->sockfd, (struct sockaddr *)&(monitor->address), sizeof(monitor->address)) < 0) {
        perror("Bind failed");
        close(monitor->sockfd);
        exit(EXIT_FAILURE);
    }

    monitor->packet_count = 0;
    monitor->start_time = time(NULL);
}

void log_packet_info(const struct sockaddr_in *client_addr, int packet_size) {
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(client_addr->sin_addr), client_ip, INET_ADDRSTRLEN);
    printf("Received packet from %s:%d | Size: %d bytes\n",
           client_ip, ntohs(client_addr->sin_port), packet_size);
}

void monitor_qos(QoSMonitor *monitor) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    ssize_t bytes_received;

    while (1) {
        bytes_received = recvfrom(monitor->sockfd, monitor->buffer, MAX_BUFFER, 0,
                                  (struct sockaddr *)&client_addr, &addr_len);
        if (bytes_received < 0) {
            perror("Receive failed");
            continue; // Continue monitoring on error
        }

        log_packet_info(&client_addr, bytes_received);
        monitor->packet_count++;

        // Calculate elapsed time to determine statistics
        time_t current_time = time(NULL);
        double elapsed_seconds = difftime(current_time, monitor->start_time);
        if (elapsed_seconds >= 1.0) {
            printf("Packets received in the last second: %d\n", monitor->packet_count);
            monitor->packet_count = 0;
            monitor->start_time = current_time;
        }
    }
}

void cleanup(QoSMonitor *monitor) {
    close(monitor->sockfd);
    printf("QoS Monitor stopped. Socket closed.\n");
}

int main(int argc, char *argv[]) {
    int port = DEFAULT_PORT;
    if (argc > 1) {
        port = atoi(argv[1]);
        if (port <= 0 || port > 65535) {
            fprintf(stderr, "Invalid port number. Using default port %d.\n", DEFAULT_PORT);
            port = DEFAULT_PORT;
        }
    }

    QoSMonitor monitor;
    init_qos_monitor(&monitor, port);
    printf("QoS Monitor running on port %d...\n", port);

    // Start monitoring
    monitor_qos(&monitor);

    // Cleanup resources on exit
    cleanup(&monitor);
    return 0;
}