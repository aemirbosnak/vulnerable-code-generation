//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip_address;
    int port;
} port_scan_args_t;

void *check_port(void *args) {
    port_scan_args_t *port_args = (port_scan_args_t *)args;
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set timeout for socket
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

    // Setup the server structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(port_args->ip_address);
    server.sin_port = htons(port_args->port);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is open\n", port_args->port);
    } else {
        // Port is closed or filtered
        // Uncomment the next line to see which ports are closed
        // printf("Port %d is closed\n", port_args->port);
    }

    close(sock);
    return NULL;
}

void scan_ports(const char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    port_scan_args_t port_scan_args[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        port_scan_args[thread_count].ip_address = strdup(ip_address);
        port_scan_args[thread_count].port = port;

        if (pthread_create(&threads[thread_count], NULL, check_port, (void *)&port_scan_args[thread_count]) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
        thread_count++;

        // Limit the number of concurrent threads
        if (thread_count == MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }
    }

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate input
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 1 and 65535.\n");
        exit(EXIT_FAILURE);
    }

    printf("Starting port scan on %s from port %d to %d...\n", ip_address, start_port, end_port);
    clock_t start_time = clock();

    scan_ports(ip_address, start_port, end_port);

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Port scan completed in %.2f seconds.\n", time_taken);
    
    return 0;
}