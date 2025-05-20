//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

// Global variables
int port_start, port_end;
char *ip_address;
int num_threads;
pthread_t *threads;

// Function to scan a single port
void *scan_port(void *arg) {
    int port = (int)arg;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Connect to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip_address);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
    }

    // Close the socket
    close(sockfd);

    return NULL;
}

// Main function
int main(int argc, char **argv) {
    // Parse command-line arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <ip_address> <port_start> <port_end> <num_threads>\n", argv[0]);
        exit(1);
    }
    ip_address = argv[1];
    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);
    num_threads = atoi(argv[4]);

    // Create threads
    threads = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, scan_port, (void *)(port_start + i)) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    // Free memory
    free(threads);

    return 0;
}