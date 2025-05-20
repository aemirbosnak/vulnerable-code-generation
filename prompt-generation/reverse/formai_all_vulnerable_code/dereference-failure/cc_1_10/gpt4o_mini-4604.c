//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

void* scan_port(void* arg);

typedef struct {
    char* ip_address;
    int port;
} port_scan_t;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Port range must be between 1 and 65535 and start must be less than or equal to end.\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        port_scan_t* p = malloc(sizeof(port_scan_t));
        p->ip_address = ip_address;
        p->port = port;

        if (pthread_create(&threads[thread_count++], NULL, scan_port, (void*)p) != 0) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
            free(p);
            continue;
        }

        // Limit number of concurrent threads
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;  // Reset for next batch
        }
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}

void* scan_port(void* arg) {
    port_scan_t* p = (port_scan_t*)arg;
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(p);
        return NULL;
    }

    // Set timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("Failed to set socket options");
        close(sock);
        free(p);
        return NULL;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(p->ip_address);
    server.sin_port = htons(p->port);

    // Attempt to connect
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", p->port);
    }

    close(sock);
    free(p);
    return NULL;
}