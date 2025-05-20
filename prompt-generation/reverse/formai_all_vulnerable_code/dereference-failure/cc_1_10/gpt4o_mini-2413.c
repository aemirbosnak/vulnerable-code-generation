//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip;
    int port;
} ScanInput;

void *port_scan(void *arg) {
    ScanInput *input = (ScanInput *)arg;
    int sock;
    struct sockaddr_in target;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Setup the target address
    target.sin_family = AF_INET;
    target.sin_port = htons(input->port);
    inet_pton(AF_INET, input->ip, &target.sin_addr);

    // Attempt to connect
    int connection_status = connect(sock, (struct sockaddr *)&target, sizeof(target));

    // Check connection status
    if (connection_status == 0) {
        printf("Port %d is open on %s\n", input->port, input->ip);
    } else {
        printf("Port %d is closed on %s\n", input->port, input->ip);
    }

    close(sock);
    pthread_exit(NULL);
}

void usage(char *prog_name) {
    fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", prog_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range: %d-%d\n", start_port, end_port);
        exit(EXIT_FAILURE);
    }

    pthread_t threads[MAX_THREADS];
    ScanInput inputs[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        inputs[thread_count].ip = ip_address;
        inputs[thread_count].port = port;

        // Create a new thread for each port scan
        if (pthread_create(&threads[thread_count], NULL, port_scan, (void *)&inputs[thread_count]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }

        thread_count++;

        // Limiting number of concurrent threads
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }
    }

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s.\n", ip_address);
    return 0;
}