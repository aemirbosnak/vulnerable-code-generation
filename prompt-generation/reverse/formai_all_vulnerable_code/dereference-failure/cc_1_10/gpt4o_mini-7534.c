//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <errno.h>

#define MAX_THREADS 100
#define TIMEOUT 1
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

typedef struct {
    char *ip_address;
    int port;
} port_scan_t;

void *check_port(void *arg) {
    port_scan_t *port_info = (port_scan_t *)arg;
    int sockfd;
    struct sockaddr_in target;

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port_info->port);

    if (inet_pton(AF_INET, port_info->ip_address, &target.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", port_info->ip_address);
        pthread_exit(NULL);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set timeout for the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT;  // seconds
    tv.tv_usec = 0;       // microseconds
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

    // Try to connect to the port
    if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d is open on %s\n", port_info->port, port_info->ip_address);
    } else {
        if (errno == EINPROGRESS) {
            printf("Port %d is closed on %s\n", port_info->port, port_info->ip_address);
        }
    }

    close(sockfd);
    free(port_info);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    printf("Starting port scan on %s\n", ip_address);
    
    for (int port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;  // Reset thread count
        }

        port_scan_t *port_info = malloc(sizeof(port_scan_t));
        port_info->ip_address = strdup(ip_address);
        port_info->port = port;

        if (pthread_create(&threads[thread_count], NULL, check_port, port_info) != 0) {
            perror("Failed to create thread");
            free(port_info->ip_address);
            free(port_info);
        } else {
            thread_count++;
        }
    }

    // Wait for any remaining threads
    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("Port scan completed.\n");
    return EXIT_SUCCESS;
}