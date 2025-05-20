//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip_address;
    int port;
} PortScanTask;

void *scan_port(void *task) {
    PortScanTask *port_task = (PortScanTask *)task;
    int sock;
    struct sockaddr_in server;
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation failed\n");
        pthread_exit(NULL);
    }

    // Set socket timeout
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port_task->port);
    inet_pton(AF_INET, port_task->ip_address, &server.sin_addr);

    // Try to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open on %s\n", port_task->port, port_task->ip_address);
    } else {
        // Connection failed
    }

    // Close socket
    close(sock);
    pthread_exit(NULL);
}

void usage(const char *program_name) {
    printf("Usage: %s [IP Address] [Start Port] [End Port]\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORTS || start_port > end_port) {
        printf("Invalid port range. Please specify a valid range between 1 and %d\n", MAX_PORTS);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        PortScanTask *task = malloc(sizeof(PortScanTask));
        task->ip_address = ip_address;
        task->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, task) != 0) {
            printf("Failed to create thread for port %d\n", port);
            free(task);
            continue;
        }

        thread_count++;

        // Limit the number of threads
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }
    }

    // Wait for remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s from %d to %d\n", ip_address, start_port, end_port);
    return EXIT_SUCCESS;
}