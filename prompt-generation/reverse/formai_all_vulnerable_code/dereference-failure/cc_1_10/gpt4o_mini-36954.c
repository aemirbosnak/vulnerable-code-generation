//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

// Structure to hold thread arguments
typedef struct {
    char *ip_address;
    int port;
} thread_args;

// Function to check if a port is open
void *check_port(void *args) {
    thread_args *arguments = (thread_args *)args;
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set socket options for timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv)) < 0) {
        perror("Error setting socket options");
        pthread_exit(NULL);
    }

    // Prepare the sockaddr_in structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(arguments->port);
    inet_pton(AF_INET, arguments->ip_address, &server_addr.sin_addr);

    // Try to connect to the port
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is OPEN on %s\n", arguments->port, arguments->ip_address);
    } else {
        printf("Port %d is CLOSED on %s\n", arguments->port, arguments->ip_address);
    }

    close(sockfd);
    free(arguments);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT_RANGE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int port_range = atoi(argv[2]);
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Iterate through port range
    for (int port = 1; port <= port_range; port++) {
        // Check if thread limit is reached
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);  // Wait for threads to finish
            }
            thread_count = 0; // Reset the thread count
        }

        // Allocate memory for thread arguments
        thread_args *args = malloc(sizeof(thread_args));
        args->ip_address = strdup(ip_address);
        args->port = port;

        // Create a thread to check the port
        if (pthread_create(&threads[thread_count], NULL, check_port, (void *)args) != 0) {
            perror("Failed to create thread");
            free(args->ip_address);
            free(args);
        } else {
            thread_count++; // Increment the number of active threads
        }
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s\n", ip_address);
    return 0;
}