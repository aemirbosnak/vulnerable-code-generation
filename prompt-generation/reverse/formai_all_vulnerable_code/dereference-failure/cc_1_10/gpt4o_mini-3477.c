//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE 65535

// Global variables
int port_range_start = 0;
int port_range_end = PORT_RANGE;
char *target_ip;
int open_ports[PORT_RANGE];
int total_open_ports = 0;

// Structure to hold thread arguments
typedef struct {
    char *ip;
    int port;
} thread_arg;

// Function to check if a port is open
void *port_scanner(void *args) {
    thread_arg *arg = (thread_arg*)args;
    int sock;
    struct sockaddr_in server;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1; // 1 second
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Configure server address structure
    server.sin_family = AF_INET;
    server.sin_port = htons(arg->port);
    server.sin_addr.s_addr = inet_addr(arg->ip);

    // Try connecting to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d: Open\n", arg->port);
        open_ports[total_open_ports++] = arg->port;
    }

    // Clean up and close the socket
    close(sock);
    pthread_exit(NULL);
}

void print_open_ports() {
    printf("\nOpen Ports:\n");
    for (int i = 0; i < total_open_ports; i++) {
        printf("%d\n", open_ports[i]);
    }
}

int main(int argc, char *argv[]) {
    // Ensure proper usage
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP> [port_start] [port_end]\n", argv[0]);
        return 1;
    }

    target_ip = argv[1]; // Target IP address

    // Process optional port range arguments
    if (argc >= 3) {
        port_range_start = atoi(argv[2]);
        if (port_range_start < 1 || port_range_start > PORT_RANGE) {
            fprintf(stderr, "Invalid starting port. Must be between 1 and %d.\n", PORT_RANGE);
            return 1;
        }
    }
    if (argc == 4) {
        port_range_end = atoi(argv[3]);
        if (port_range_end < port_range_start || port_range_end > PORT_RANGE) {
            fprintf(stderr, "Invalid ending port. Must be between %d and %d.\n", port_range_start, PORT_RANGE);
            return 1;
        }
    }

    pthread_t threads[MAX_THREADS];
    thread_arg args[MAX_THREADS];
    int thread_count = 0;

    // Create threads to scan ports
    for (int port = port_range_start; port <= port_range_end; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }

        // Fill thread arguments
        args[thread_count].ip = target_ip;
        args[thread_count].port = port;

        // Create a new thread for scanning
        if (pthread_create(&threads[thread_count], NULL, port_scanner, (void*)&args[thread_count]) != 0) {
            perror("Failed to create thread");
            return 1;
        }

        thread_count++;
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    print_open_ports();

    return 0;
}