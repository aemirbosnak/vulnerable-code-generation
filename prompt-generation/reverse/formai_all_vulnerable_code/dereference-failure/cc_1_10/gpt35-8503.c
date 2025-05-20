//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_THREADS 10 // Maximum number of threads
#define TIMEOUT 2 // Timeout in seconds

// Global variables
int PORT;
int start;
int end;
int open_ports[65536];
int num_open_ports = 0;
pthread_mutex_t mutex;

// Function to check if a port is open
void *check_port(void *thread_id) {
    int sock, status;
    struct sockaddr_in target;

    // Initialize target sockaddr structure
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = htonl(INADDR_ANY);

    // Loop through all ports assigned to this thread
    for (int port = start + (int)(thread_id) - 1; port <= end; port += MAX_THREADS) {
        // Create a socket for TCP connection
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        // Set timeout
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
        if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) < 0) {
            perror("setsockopt failed");
            exit(EXIT_FAILURE);
        }

        // Connect to port
        target.sin_port = htons(port);
        status = connect(sock, (struct sockaddr *)&target, sizeof(target));

        // If port is open, add it to the global array
        if (status == 0) {
            pthread_mutex_lock(&mutex);
            open_ports[num_open_ports++] = port;
            pthread_mutex_unlock(&mutex);
        }

        close(sock);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    // Validate command line arguments
    if (argc != 4) {
        printf("Usage: %s <IP Address> <starting port> <ending port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *ip = argv[1];
    if (inet_addr(ip) == -1) {
        printf("Invalid IP address\n");
        exit(EXIT_FAILURE);
    }
    start = atoi(argv[2]);
    end = atoi(argv[3]);
    if (start > end || start < 1 || end > 65535) {
        printf("Invalid port range\n");
        exit(EXIT_FAILURE);
    }

    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex initialization failed");
        exit(EXIT_FAILURE);
    }

    // Create threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, check_port, (void *)(i + 1)) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
    }

    // Print open ports
    printf("Open ports for %s:\n", ip);
    if (num_open_ports == 0) {
        printf("None\n");
    } else {
        for (int i = 0; i < num_open_ports; i++) {
            printf("%d\n", open_ports[i]);
        }
    }

    // Clean up
    if (pthread_mutex_destroy(&mutex) != 0) {
        perror("Mutex destruction failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}