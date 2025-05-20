//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip;
    int port;
} ScanArgs;

void *scan_port(void *args) {
    ScanArgs *scan_args = (ScanArgs *)args;
    int sock;
    struct sockaddr_in server;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set the timeout value for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Define the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(scan_args->port);
    if (inet_pton(AF_INET, scan_args->ip, &server.sin_addr) <= 0) {
        perror("Invalid address");
        close(sock);
        return NULL;
    }

    // Attempt to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is open.\n", scan_args->port);
    } else {
        // Uncomment below for debugging
        // perror("Connection failed");
    }

    // Clean up
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate port range
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range.\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }

        ScanArgs *scan_args = malloc(sizeof(ScanArgs));
        scan_args->ip = ip_address;
        scan_args->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, scan_args) != 0) {
            perror("Failed to create thread");
            free(scan_args);
            continue;
        }
        thread_count++;
    }

    // Wait for any remaining threads to finish
    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("Scanning complete.\n");
    return EXIT_SUCCESS;
}