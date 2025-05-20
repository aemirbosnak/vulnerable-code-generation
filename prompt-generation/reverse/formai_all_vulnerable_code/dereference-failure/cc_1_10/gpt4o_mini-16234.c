//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip_address;
    int port;
} thread_data;

void *scan_port(void *arg) {
    thread_data *data = (thread_data *)arg;
    int sock;
    struct sockaddr_in server_addr;
    
    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Socket creation error: %s\n", strerror(errno));
        free(data);
        return NULL;
    }

    // Setting timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char *)&timeout, sizeof(timeout));
    
    // Configuring server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(data->port);
    inet_pton(AF_INET, data->ip_address, &server_addr.sin_addr);

    // Connecting to the port
    int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result == 0) {
        printf("Port %d is open on %s\n", data->port, data->ip_address);
    }
    
    close(sock);
    free(data);
    return NULL;
}

void initiate_scan(char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        // Check for thread availability
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }

        // Allocating memory for thread data
        thread_data *data = malloc(sizeof(thread_data));
        data->ip_address = ip_address;
        data->port = port;

        // Creating thread for scanning
        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)data) != 0) {
            fprintf(stderr, "Error creating thread: %s\n", strerror(errno));
            free(data);
        } else {
            thread_count++;
        }
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Port range is invalid. Please enter ports between 1 and 65535.\n");
        return 1;
    }

    printf("Starting scan on IP: %s, Ports: %d to %d\n", ip_address, start_port, end_port);
    initiate_scan(ip_address, start_port, end_port);
    printf("Scan completed.\n");

    return 0;
}