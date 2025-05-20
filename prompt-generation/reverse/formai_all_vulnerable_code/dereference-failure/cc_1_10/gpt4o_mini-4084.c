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
} scan_params;

void *scan_port(void *params) {
    scan_params *p = (scan_params *)params;
    struct sockaddr_in server;
    int sockfd;
    struct timeval tv;
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set socket timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));
    
    // Setup the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(p->port);
    server.sin_addr.s_addr = inet_addr(p->ip);

    // Try to connect
    int result = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d is open on %s\n", p->port, p->ip);
    } else {
        // Uncomment the next line if you want verbose output
        // printf("Port %d is closed on %s\n", p->port, p->ip);
    }

    close(sockfd);
    return NULL;
}

void start_scan(char *ip, int from_port, int to_port) {
    pthread_t threads[MAX_THREADS];
    scan_params params[MAX_THREADS];
    int thread_count = 0;

    printf("Starting scan on %s from port %d to %d...\n", ip, from_port, to_port);

    for (int port = from_port; port <= to_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }

        params[thread_count].ip = ip;
        params[thread_count].port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)&params[thread_count]) != 0) {
            perror("Failed to create thread");
            return;
        }

        thread_count++;
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scan complete!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <FROM_PORT> <TO_PORT>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = argv[1];
    int from_port = atoi(argv[2]);
    int to_port = atoi(argv[3]);

    // Validate input ports
    if (from_port < 1 || to_port > 65535 || from_port > to_port) {
        fprintf(stderr, "Port range is invalid. Valid range is 1-65535.\n");
        return EXIT_FAILURE;
    }

    start_scan(ip, from_port, to_port);

    return EXIT_SUCCESS;
}