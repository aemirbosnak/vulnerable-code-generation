//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

typedef struct {
    char *ip_address;
    int port;
} port_scan_job_t;

void *scan_port(void *arg) {
    port_scan_job_t *job = (port_scan_job_t *)arg;
    int sock;
    struct sockaddr_in server;

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Could not create socket.\n");
        pthread_exit(NULL);
    }

    // Setting timeout for socket operations
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Initializing server structure
    server.sin_family = AF_INET;
    server.sin_port = htons(job->port);
    server.sin_addr.s_addr = inet_addr(job->ip_address);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open on %s\n", job->port, job->ip_address);
    } else {
        printf("Port %d is closed on %s\n", job->port, job->ip_address);
    }

    close(sock);
    free(job);
    pthread_exit(NULL);
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Loop through the port range
    for (int port = start_port; port <= end_port; port++) {
        // Prepare the job
        port_scan_job_t *job = malloc(sizeof(port_scan_job_t));
        job->ip_address = ip_address;
        job->port = port;

        // Create a new thread for scanning the port
        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)job) != 0) {
            printf("Failed to create thread for port %d\n", port);
            free(job);
        }
        thread_count++;

        // Join threads that have completed their work (to avoid overflow of thread count)
        for (int i = 0; i < thread_count; i++) {
            if (threads[i] != 0) {
                pthread_join(threads[i], NULL);
                threads[i] = 0;  // Reset the thread
            }
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        if (threads[i] != 0) {
            pthread_join(threads[i], NULL);
        }
    }
}

int main(int argc, char *argv[]) {
    // Input Validation
    if (argc != 4) {
        printf("Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Range validation
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        printf("Port numbers must be between 1 and 65535, and start must be less than end.\n");
        return 1;
    }

    // Begin Port Scanning
    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);
    scan_ports(ip_address, start_port, end_port);
    
    printf("Port scanning completed.\n");
    return 0;
}