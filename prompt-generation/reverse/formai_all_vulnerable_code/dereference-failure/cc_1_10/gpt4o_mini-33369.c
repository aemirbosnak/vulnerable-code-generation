//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip;
    int port;
} ScanTask;

void *scan_port(void *arg) {
    ScanTask *task = (ScanTask *)arg;
    int sockfd;
    struct sockaddr_in server_addr;
    struct timeval timeout;

    // Setting a timeout for the socket
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set timeout option for the socket
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(task->port);
    inet_pton(AF_INET, task->ip, &server_addr.sin_addr);
    
    // Try connecting to the port
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", task->port);
    } else {
        if (errno != EINPROGRESS) {
            printf("Port %d is closed\n", task->port);
        } else {
            // If we are in non-blocking mode, we can assume the port is open
            printf("Port %d is open (possibly)\n", task->port);
        }
    }

    // Close the socket
    close(sockfd);
    pthread_exit(NULL);
}

void usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", program_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    pthread_t threads[MAX_THREADS];
    ScanTask tasks[MAX_THREADS];
    int thread_count = 0;

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Error: Port range is invalid.\n");
        return EXIT_FAILURE;
    }

    // Scan ports in the specified range using threads
    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            pthread_join(threads[0], NULL);
            for (int i = 0; i < thread_count - 1; i++) {
                threads[i] = threads[i + 1];
                tasks[i] = tasks[i + 1];
            }
            thread_count--;
        }

        tasks[thread_count].ip = ip;
        tasks[thread_count].port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)&tasks[thread_count]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }

        thread_count++;
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}