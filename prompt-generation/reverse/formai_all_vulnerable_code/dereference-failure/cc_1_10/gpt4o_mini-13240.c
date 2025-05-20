//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip_address;
    int port;
} port_scan_info;

void *scan_port(void *arg) {
    port_scan_info *info = (port_scan_info *)arg;
    int sock;
    struct sockaddr_in server;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set socket options
    struct timeval tv;
    tv.tv_sec = TIMEOUT; // timeout in seconds
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    server.sin_family = AF_INET;
    server.sin_port = htons(info->port);
    inet_pton(AF_INET, info->ip_address, &server.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is OPEN on %s\n", info->port, info->ip_address);
    } else {
        printf("Port %d is CLOSED on %s\n", info->port, info->ip_address);
    }

    close(sock);
    return NULL;
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        port_scan_info *info = malloc(sizeof(port_scan_info));
        info->ip_address = ip_address;
        info->port = port;

        // Create a new thread for scanning the port
        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)info) != 0) {
            perror("Failed to create thread");
            free(info);
            continue;
        }
        
        thread_count++;

        // Limit number of concurrent threads to prevent overload
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range! Ports must be between 1 and 65535.\n");
        return EXIT_FAILURE;
    }

    printf("Starting port scan on %s from port %d to port %d...\n", ip_address, start_port, end_port);
    scan_ports(ip_address, start_port, end_port);
    printf("Port scanning completed.\n");

    return EXIT_SUCCESS;
}