//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int ports_to_scan[1024]; // Array to hold the ports to scan
int total_ports = 0; // Number of ports to scan
void *port_scanner(void *arg); // Function prototype for port scanning
int is_port_open(const char *ip_address, int port); // Function prototype for checking if a port is open

typedef struct {
    char *ip_address;
    int port;
} scan_args;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT_RANGE>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_range = atoi(argv[2]);
    total_ports = port_range;

    // Fill ports_to_scan array with the specified port range
    for (int i = 0; i < port_range; i++) {
        ports_to_scan[i] = i + 1; // Ports from 1 to port_range
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Create threads for scanning each port
    for (int i = 0; i < total_ports; i++) {
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < MAX_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }

        scan_args *args = malloc(sizeof(scan_args));
        args->ip_address = ip_address;
        args->port = ports_to_scan[i];

        pthread_create(&threads[thread_count], NULL, port_scanner, (void *)args);
        thread_count++;
    }

    // Join remaining threads after the main loop 
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Function to perform port scanning
void *port_scanner(void *arg) {
    scan_args *args = (scan_args *)arg;
    int open = is_port_open(args->ip_address, args->port);
    
    if (open) {
        printf("Port %d is OPEN on %s\n", args->port, args->ip_address);
    } else {
        printf("Port %d is CLOSED on %s\n", args->port, args->ip_address);
    }

    free(args); // Free the allocated memory for args
    return NULL;
}

// Function to check if a port is open
int is_port_open(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        return 0; // Socket creation failed
    }

    // Set the timeout for the connection
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &(server.sin_addr));

    // Try to establish a connection
    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));

    // Close the socket
    close(sock);

    // Return based on the result of the connection attempt
    return (result == 0);
}