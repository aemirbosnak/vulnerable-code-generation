//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT 1
#define MAX_THREADS 100

typedef struct {
    char *ip;
    int port;
} scan_data;

void *scan_port(void *arg) {
    scan_data *data = (scan_data *)arg;
    int sockfd;
    struct sockaddr_in server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set socket options
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    inet_pton(AF_INET, data->ip, &server.sin_addr);

    // Attempt to connect
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", data->port);
    } else {
        // Failed to connect; port is likely closed
    }

    close(sockfd);
    free(data);
    return NULL;
}

void scan_ports(char *ip, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        // Allocate data for this thread
        scan_data *data = malloc(sizeof(scan_data));
        data->ip = ip;
        data->port = port;

        // Create a new thread to scan the port
        if (pthread_create(&threads[thread_count], NULL, scan_port, data) != 0) {
            perror("Failed to create thread");
            free(data); // Free memory if thread creation fails
            continue;
        }

        thread_count++;
        // Limit the number of concurrent threads
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
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 1 and 65535 and start_port must be less than or equal to end_port.\n");
        return 2;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);
    scan_ports(ip, start_port, end_port);
    
    printf("Scanning complete.\n");
    return 0;
}