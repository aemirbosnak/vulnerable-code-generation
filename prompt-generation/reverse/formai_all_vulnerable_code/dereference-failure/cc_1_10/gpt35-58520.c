//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Constants
#define MAX_THREADS 100
#define TIMEOUT 1

// Function prototypes
void scan_port(int port);
void *thread_function(void *arg);

// Global variables
struct sockaddr_in target;
pthread_t threads[MAX_THREADS];
int num_threads = 0;

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <ip_address> [num_threads]\n", argv[0]);
        exit(1);
    }

    int num_ports = 1024;
    int thread_limit = MAX_THREADS;

    // Parse command line arguments
    if (argc == 3) {
        thread_limit = atoi(argv[2]);
        if (thread_limit > MAX_THREADS) {
            thread_limit = MAX_THREADS;
        }
    }

    // Set up target sockaddr_in structure
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    // Scan ports using multiple threads
    for (int i = 1; i <= num_ports; i++) {
        if (num_threads >= thread_limit) {
            // Wait for a thread to finish before starting a new one
            pthread_join(threads[0], NULL);
            for (int j = 1; j < num_threads; j++) {
                threads[j-1] = threads[j];
            }
            num_threads--;
        }

        // Create new thread to scan the current port
        int *port = (int*) malloc(sizeof(int));
        *port = i;
        pthread_create(&threads[num_threads], NULL, thread_function, (void*) port);
        num_threads++;
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void scan_port(int port) {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Cannot create socket\n");
        exit(1);
    }

    // Set socket options
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) == -1) {
        fprintf(stderr, "Cannot set socket options\n");
        exit(1);
    }

    // Connect to target port
    target.sin_port = htons(port);
    int result = connect(sock, (struct sockaddr*)&target, sizeof(target));
    if (result == 0) {
        printf("Port %d is open\n", port);
    }

    // Clean up
    close(sock);
}

void *thread_function(void *arg) {
    int port = *((int*) arg);
    free(arg);
    scan_port(port);
    return NULL;
}