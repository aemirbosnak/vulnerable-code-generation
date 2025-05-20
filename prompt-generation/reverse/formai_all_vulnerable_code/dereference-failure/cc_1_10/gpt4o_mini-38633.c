//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int target_port;
char *target_ip;
int port_status[65536] = {0}; // Array to keep track of port status

void *port_scanner(void *arg) {
    int sockfd;
    struct sockaddr_in server_addr;
    int port = *(int *)arg;

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Setting timeout for connection
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Server address setup
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    // Try connecting to the port
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        port_status[port] = 1; // Port is open
    }

    close(sockfd);
    return NULL;
}

void start_scanning(int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            // Wait for threads to finish
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0; // Reset count for new threads
        }

        printf("Starting scan on port %d...\n", port);
        int *port_ptr = malloc(sizeof(int));
        *port_ptr = port;

        // Create new thread for each port
        if (pthread_create(&threads[thread_count++], NULL, port_scanner, port_ptr) != 0) {
            perror("Failed to create thread");
            free(port_ptr);
            return;
        }
        
        // Free memory for the port pointer
        free(port_ptr);
    }

    // Wait for any remaining threads
    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }
}

void print_results(int start_port, int end_port) {
    printf("\nPort Scan Results for %s:\n", target_ip);
    for (int port = start_port; port <= end_port; port++) {
        if (port_status[port]) {
            printf("Port %d: OPEN\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start port> <end port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range!\n");
        return EXIT_FAILURE;
    }

    printf("Initiating scan on %s from port %d to %d...\n", target_ip, start_port, end_port);
    start_scanning(start_port, end_port);
    print_results(start_port, end_port);

    return EXIT_SUCCESS;
}