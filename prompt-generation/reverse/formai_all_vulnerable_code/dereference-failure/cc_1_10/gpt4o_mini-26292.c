//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int open_ports[65536];
int total_ports = 0;

void* scan_port(void* arg) {
    int port = *((int*)arg);
    struct sockaddr_in server;
    int sock;

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY; // Change to the target IP as necessary

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) >= 0) {
        open_ports[total_ports++] = port;
        printf("Port %d is open!\n", port);
    }

    close(sock);
    return NULL;
}

void scan_ports(int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int port_numbers[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        port_numbers[thread_count] = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, (void*)&port_numbers[thread_count]) != 0) {
            perror("Failed to create thread");
        }
        thread_count++;

        // Limit the number of concurrent threads
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }
    }

    // Wait for remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port < 0 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range! Ports should be between 0-65535.\n");
        return 1;
    }

    printf("Scanning ports from %d to %d...\n", start_port, end_port);
    scan_ports(start_port, end_port);

    printf("Scan complete! Found %d open ports.\n", total_ports);
    return 0;
}