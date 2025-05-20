//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE 65535

typedef struct {
    char *ip_address;
    int start_port;
    int end_port;
} scan_args;

void *scan_port(void *args) {
    scan_args *scan = (scan_args *)args;
    int sock;
    struct sockaddr_in server;
    
    for (int port = scan->start_port; port <= scan->end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation failed");
            pthread_exit(NULL);
        }
        
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr(scan->ip_address);
        
        // Set a timeout for the connection attempt
        struct timeval tv;
        tv.tv_sec = 1; // 1 second timeout
        tv.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

        // Attempt to connect
        if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
            printf("Port %d is open on %s\n", port, scan->ip_address);
        }
        close(sock);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > PORT_RANGE || start_port > end_port) {
        fprintf(stderr, "Error: Invalid port range.\n");
        return EXIT_FAILURE;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);
    
    pthread_t threads[MAX_THREADS];
    scan_args args[MAX_THREADS];
    int thread_count = 0;
    int range = end_port - start_port + 1;

    // Determine how many threads we need
    for (int i = start_port; i <= end_port;) {
        int ports_per_thread = range / MAX_THREADS;
        
        args[thread_count].ip_address = ip_address;
        args[thread_count].start_port = i;
        args[thread_count].end_port = i + ports_per_thread - 1;

        if (thread_count == MAX_THREADS - 1) {
            args[thread_count].end_port = end_port; // Make the last thread cover the remaining ports
        }

        pthread_create(&threads[thread_count], NULL, scan_port, (void *)&args[thread_count]);
        thread_count++;
        i += ports_per_thread;
    }

    // Wait for all threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scan completed.\n");
    return EXIT_SUCCESS;
}