//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <time.h>

#define MAX_PORTS 65535
#define THREAD_POOL_SIZE 50

typedef struct {
    char *ip_address;
    int port;
} PortScanJob;

void *scan_port(void *arg) {
    PortScanJob *job = (PortScanJob *)arg;
    int sock;
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(job->port);
    server.sin_addr.s_addr = inet_addr(job->ip_address);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set a timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Attempt to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is open on %s\n", job->port, job->ip_address);
    }

    close(sock);
    pthread_exit(NULL);
}

void scan_ports(const char *ip_address, int start_port, int end_port) {
    pthread_t thread_pool[THREAD_POOL_SIZE];
    PortScanJob jobs[THREAD_POOL_SIZE];
    int job_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        jobs[job_count].ip_address = (char *)ip_address;
        jobs[job_count].port = port;

        // Create thread to scan the port
        if (pthread_create(&thread_pool[job_count], NULL, scan_port, (void *)&jobs[job_count]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }

        job_count++;

        // Wait for threads to finish if we've reached the thread pool limit
        if (job_count == THREAD_POOL_SIZE) {
            for (int i = 0; i < THREAD_POOL_SIZE; i++) {
                pthread_join(thread_pool[i], NULL);
            }
            job_count = 0; // Reset job counter
        }
    }

    // Wait for any remaining threads
    for (int i = 0; i < job_count; i++) {
        pthread_join(thread_pool[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORTS || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Must be between 1 and %d.\n", MAX_PORTS);
        exit(EXIT_FAILURE);
    }

    printf("Scanning IP: %s from port %d to %d...\n", ip_address, start_port, end_port);
    time_t start_time = time(NULL);

    scan_ports(ip_address, start_port, end_port);

    time_t end_time = time(NULL);
    printf("Scanning completed in %ld seconds.\n", end_time - start_time);

    return 0;
}