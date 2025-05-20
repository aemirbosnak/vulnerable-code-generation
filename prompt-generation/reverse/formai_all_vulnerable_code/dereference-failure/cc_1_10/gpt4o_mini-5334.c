//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netdb.h>

#define MAX_THREADS 50
#define TIMEOUT 1

void *scan_port(void *arg);
void handle_error(const char *msg);

typedef struct {
    char *ip;
    int port;
} port_scan_args;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <start_port>-<end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *endptr;
    int start_port = strtol(argv[2], &endptr, 10);
    int end_port = strtol(endptr + 1, NULL, 10);

    if (start_port < 0 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Error: Invalid port range specified.\n");
        return EXIT_FAILURE;
    }

    char *ip = argv[1];

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }

        port_scan_args *args = malloc(sizeof(port_scan_args));
        args->ip = ip;
        args->port = port;

        if (pthread_create(&threads[thread_count++], NULL, scan_port, args) != 0) {
            handle_error("Failed to create thread");
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning complete.\n");
    return EXIT_SUCCESS;
}

void *scan_port(void *arg) {
    port_scan_args *args = (port_scan_args *)arg;

    int sockfd;
    struct sockaddr_in server_addr;
    struct timeval timeout;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        free(arg);
        pthread_exit(NULL);
    }

    // Set timeout for socket
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(args->port);
    inet_pton(AF_INET, args->ip, &server_addr.sin_addr);

    // Attempt to connect
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open.\n", args->port);
    } else {
        // Connection failed, indicating the port is closed
        // Optionally, use a specific log message if desired
    }

    close(sockfd);
    free(arg);
    pthread_exit(NULL);
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}