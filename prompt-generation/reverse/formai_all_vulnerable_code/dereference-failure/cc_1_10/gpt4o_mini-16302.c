//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define TIMEOUT_SEC 5

volatile sig_atomic_t keep_running = 1;

void handle_sigint(int sig) {
    keep_running = 0;
}

typedef struct {
    char *hostname;
    int latency;
    int packet_loss;
} QoSMonitor;

void initialize_monitor(QoSMonitor *monitor, const char *hostname) {
    monitor->hostname = strdup(hostname);
    monitor->latency = 0;
    monitor->packet_loss = 0;
}

void free_monitor(QoSMonitor *monitor) {
    free(monitor->hostname);
}

int measure_latency(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];
    int sockfd, bytes_sent, bytes_received;
    struct timeval start, end;

    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname failed");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        return -1;
    }

    gettimeofday(&start, NULL);
    bytes_sent = sendto(sockfd, "ping", strlen("ping"), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bytes_sent < 0) {
        perror("sendto failed");
        close(sockfd);
        return -1;
    }

    socklen_t addr_len = sizeof(server_addr);
    bytes_received = recvfrom(sockfd, recv_buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
    gettimeofday(&end, NULL);

    close(sockfd);

    if (bytes_received < 0) {
        return -1; // indicates packet loss
    }

    long latency = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000; // in milliseconds
    return (int)latency;
}

void monitor_qos(QoSMonitor *monitor) {
    while (keep_running) {
        int latency = measure_latency(monitor->hostname);
        if (latency >= 0) {
            monitor->latency = latency;
            printf("Latency to %s: %d ms\n", monitor->hostname, monitor->latency);
        } else {
            monitor->packet_loss += 1;
            printf("Packet loss detected to %s\n", monitor->hostname);
        }

        printf("Current Packet Loss: %d\n", monitor->packet_loss);
        sleep(TIMEOUT_SEC);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handle_sigint);
    
    QoSMonitor monitor;
    initialize_monitor(&monitor, argv[1]);

    printf("Starting QoS monitor for %s...\n", monitor.hostname);
    monitor_qos(&monitor);

    free_monitor(&monitor);
    printf("QoS monitoring stopped.\n");
    
    return EXIT_SUCCESS;
}