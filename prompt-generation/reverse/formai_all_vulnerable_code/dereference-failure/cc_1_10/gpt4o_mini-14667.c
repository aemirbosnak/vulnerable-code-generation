//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 100

typedef struct {
    char *ip_address;
    int start_port;
    int end_port;
} PortScanArgs;

// Function to scan a single port
void *scan_port(void *args) {
    PortScanArgs *port_args = (PortScanArgs *)args;
    int sock;
    struct sockaddr_in server;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set up the server structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port_args->start_port);
    inet_pton(AF_INET, port_args->ip_address, &server.sin_addr);

    // Attempt to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", port_args->start_port);
    }

    close(sock);
    return NULL;
}

// Function to start scanning ports
void scan_ports(char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset for the next batch
        }

        PortScanArgs *port_args = malloc(sizeof(PortScanArgs));
        port_args->ip_address = ip_address;
        port_args->start_port = port;
        port_args->end_port = end_port;

        pthread_create(&threads[thread_count++], NULL, scan_port, port_args);
    }

    // Wait for remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

// The main function where execution starts
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please enter ports between 1 and 65535.\n");
        return 1;
    }

    printf("Starting port scan on %s from port %d to port %d...\n", ip_address, start_port, end_port);
    scan_ports(ip_address, start_port, end_port);
    printf("Port scan completed!\n");

    return 0;
}