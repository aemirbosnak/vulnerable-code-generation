//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1
#define MAX_PORT 65535
#define MIN_PORT 1

typedef struct {
    char *ip;
    int port;
} port_scan_arg_t;

void *scan_port(void *args) {
    port_scan_arg_t *scan_arg = (port_scan_arg_t *)args;
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set timeout option
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Set up the server structure
    server.sin_family = AF_INET;
    server.sin_port = htons(scan_arg->port);
    if (inet_pton(AF_INET, scan_arg->ip, &server.sin_addr) <= 0) {
        perror("Invalid address");
        close(sock);
        pthread_exit(NULL);
    }

    // Try to connect to the port
    int connection_status = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (connection_status == 0) {
        printf("Port %d is open on %s\n", scan_arg->port, scan_arg->ip);
    } 
    close(sock);
    pthread_exit(NULL);
}

void usage(char *program_name) {
    printf("Usage: %s <IP_ADDRESS> [<START_PORT> <END_PORT>]\n", program_name);
    printf("\nExample: %s 192.168.1.1 20 100\n", program_name);
    printf("If no ports are specified, default scanning from 1 to 65535.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = (argc >= 3) ? atoi(argv[2]) : MIN_PORT;
    int end_port = (argc == 4) ? atoi(argv[3]) : MAX_PORT;

    // Validate port range
    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between %d and %d\n", MIN_PORT, MAX_PORT);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    port_scan_arg_t scan_args[MAX_THREADS];
    int thread_count = 0;

    // Start scanning ports
    for (int port = start_port; port <= end_port; ++port) {
        scan_args[thread_count].ip = ip_address;
        scan_args[thread_count].port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, &scan_args[thread_count]) != 0) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
            continue; // Skip to the next port
        }

        thread_count++;
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }
    }

    // Wait for any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed.\n");
    return EXIT_SUCCESS;
}