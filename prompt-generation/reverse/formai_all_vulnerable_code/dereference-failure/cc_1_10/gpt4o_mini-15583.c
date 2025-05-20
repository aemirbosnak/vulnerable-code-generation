//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_THREADS 100
#define PORT_RANGE 65535

typedef struct {
    char *ip_address;
    int port_number;
} PortScanInfo;

int open_port(const char *ip_address, int port) {
    int sockfd;
    struct sockaddr_in target;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &target.sin_addr);

    // Set a timeout for the connection attempt
    struct timeval timeout;
    timeout.tv_sec = 1;  // 1 second
    timeout.tv_usec = 0; // 0 microseconds
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Attempt to connect
    int result = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
    close(sockfd);
    return (result == 0) ? 1 : 0;
}

void *scan_port(void *arg) {
    PortScanInfo *info = (PortScanInfo *)arg;

    if (open_port(info->ip_address, info->port_number)) {
        printf("Port %d: OPEN\n", info->port_number);
    } else {
        printf("Port %d: CLOSED\n", info->port_number);
    }

    free(info);
    return NULL;
}

void scan_ports(const char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }

        PortScanInfo *info = (PortScanInfo *)malloc(sizeof(PortScanInfo));
        info->ip_address = (char *)ip_address;
        info->port_number = port;

        pthread_create(&threads[thread_count], NULL, scan_port, info);
        thread_count++;
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 0 || end_port > PORT_RANGE || start_port > end_port) {
        fprintf(stderr, "Error: invalid port range.\n");
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);
    scan_ports(ip_address, start_port, end_port);
    printf("Port scanning completed.\n");

    return 0;
}