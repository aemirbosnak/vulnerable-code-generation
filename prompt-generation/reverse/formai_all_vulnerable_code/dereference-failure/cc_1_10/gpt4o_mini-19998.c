//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char* ip_address;
    int port;
} port_scan_task_t;

void* scan_port(void* arg) {
    port_scan_task_t* task = (port_scan_task_t*)arg;
    int sock;
    struct sockaddr_in addr;
    struct timeval tv;

    // Set timeout for the socket
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        free(task);
        return NULL;
    }

    // Set timeout for the socket
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

    // Prepare the sockaddr_in structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(task->port);
    inet_pton(AF_INET, task->ip_address, &addr.sin_addr);

    // Try to connect to the port
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open on %s\n", task->port, task->ip_address);
    }
    close(sock);
    free(task);
    return NULL;
}

void scan_ports(const char* ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }

        port_scan_task_t* task = (port_scan_task_t*)malloc(sizeof(port_scan_task_t));
        task->ip_address = strdup(ip_address);
        task->port = port;

        if (pthread_create(&threads[thread_count++], NULL, scan_port, task) != 0) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
            free(task->ip_address);
            free(task);
        }
    }

    // Wait for all remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please specify ports between 1 and 65535.\n");
        return EXIT_FAILURE;
    }

    printf("Scanning %s from port %d to %d...\n", ip_address, start_port, end_port);
    scan_ports(ip_address, start_port, end_port);

    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}