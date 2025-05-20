//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CONNECTIONS 1024
#define TIMEOUT 1  // seconds
#define PORT_START 1
#define PORT_END 65535

typedef struct {
    char *ip_address;
    int port;
} port_scan_t;

void *scan_port(void *arg) {
    port_scan_t *port_info = (port_scan_t *)arg;

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Socket creation failed!\n");
        pthread_exit(NULL);
    }

    // Setting socket options
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char *)&tv, sizeof(tv));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_info->port);
    inet_pton(AF_INET, port_info->ip_address, &server_addr.sin_addr);

    // Attempt to connect
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is OPEN on %s\n", port_info->port, port_info->ip_address);
    } else {
        printf("Port %d is CLOSED on %s\n", port_info->port, port_info->ip_address);
    }

    close(sockfd);
    free(port_info);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    pthread_t threads[MAX_CONNECTIONS];

    printf("Initiating port scan on %s...\n", ip_address);

    int thread_count = 0;
    for (int port = PORT_START; port <= PORT_END; port++) {
        port_scan_t *port_info = malloc(sizeof(port_scan_t));
        if (port_info == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        port_info->ip_address = ip_address;
        port_info->port = port;

        // Create a new thread for port scanning
        if (pthread_create(&threads[thread_count], NULL, scan_port, port_info) != 0) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
            free(port_info);
            continue;
        }

        thread_count++;

        // Limit number of threads to MAX_CONNECTIONS
        if (thread_count >= MAX_CONNECTIONS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scan on %s completed.\n", ip_address);
    return EXIT_SUCCESS;
}