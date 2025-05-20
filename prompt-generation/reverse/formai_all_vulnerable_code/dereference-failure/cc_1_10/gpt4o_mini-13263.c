//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE 1024

typedef struct {
    char *ip_address;
    int port;
} port_scan_t;

void *scan_port(void *args) {
    port_scan_t *port_info = (port_scan_t *)args;
    int sock;
    struct sockaddr_in server;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port_info->port);
    inet_pton(AF_INET, port_info->ip_address, &server.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is OPEN on %s\n", port_info->port, port_info->ip_address);
    }

    close(sock);
    free(port_info);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    if (start_port < 0 || start_port >= PORT_RANGE) {
        fprintf(stderr, "Please enter a start port between 0 and %d.\n", PORT_RANGE - 1);
        return EXIT_FAILURE;
    }

    printf("Scanning ports on %s starting from port %d...\n", ip_address, start_port);

    for (int port = start_port; port < PORT_RANGE; port++) {
        port_scan_t *port_info = malloc(sizeof(port_scan_t));
        port_info->ip_address = ip_address;
        port_info->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)port_info) != 0) {
            perror("Failed to create thread");
            free(port_info);
            continue;
        }

        thread_count++;
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;  // Reset thread count for the next batch
        }
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s.\n", ip_address);
    return EXIT_SUCCESS;
}