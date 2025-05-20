//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

// Structure to hold the data for each thread
typedef struct {
    const char *ip;
    int port;
} ThreadData;

// Function to check if a port is open
void *check_port(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int sock;
    struct sockaddr_in server;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set up the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    server.sin_addr.s_addr = inet_addr(data->ip);

    // Set socket to non-blocking
    struct timeval timeout;      
    timeout.tv_sec = 1;          // 1 second timeout
    timeout.tv_usec = 0;         // 0 microseconds
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Try to connect to the port
    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));

    // If the connection is established (result is 0), the port is open
    if (result == 0) {
        printf("Port %d is open\n", data->port);
    }

    close(sock);
    free(data);
    return NULL;
}

// Main function to set up the port scanning
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <max port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    int max_port = atoi(argv[2]);
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Loop through the ports from 1 to max_port
    for (int port = 1; port <= max_port; port++) {
        if (thread_count >= MAX_THREADS) {
            // Wait for threads to finish if we reach the limit
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }

        // Allocate memory for thread data
        ThreadData *data = malloc(sizeof(ThreadData));
        if (!data) {
            perror("Memory allocation for thread data failed");
            exit(EXIT_FAILURE);
        }
        data->ip = ip;
        data->port = port;

        // Create a new thread for checking the port
        if (pthread_create(&threads[thread_count], NULL, check_port, data) != 0) {
            perror("Failed to create thread");
            free(data);
        } else {
            thread_count++;
        }
    }

    // Wait for any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}