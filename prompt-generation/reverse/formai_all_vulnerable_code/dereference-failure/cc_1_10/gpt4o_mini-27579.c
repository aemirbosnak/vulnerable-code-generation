//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 1024
#define TIMEOUT 1

typedef struct {
    char *ip_addr;
    int port;
} thread_data;

void *scan_port(void *arg) {
    thread_data *data = (thread_data *)arg;
    int sock;
    struct sockaddr_in server;
    struct timeval tv;
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(data);
        return NULL;
    }
    
    // Setting the timeout for the socket
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    // Set up the sockaddr structure
    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    if (inet_pton(AF_INET, data->ip_addr, &server.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported: %s\n", data->ip_addr);
        close(sock);
        free(data);
        return NULL;
    }
    
    // Try to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open on %s\n", data->port, data->ip_addr);
    }
    
    close(sock);
    free(data);
    return NULL;
}

void scan_ports(const char *ip_addr, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        // Allocate memory for thread data
        thread_data *data = malloc(sizeof(thread_data));
        if (!data) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        data->ip_addr = strdup(ip_addr); // Duplicate the IP address string
        data->port = port;

        // Create a thread to scan the port
        if (pthread_create(&threads[thread_count++], NULL, scan_port, data)) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
            free(data->ip_addr);
            free(data);
            exit(EXIT_FAILURE);
        }

        // Limit the number of threads to avoid excessive resource consumption
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Starting port scan on %s from port %d to %d...\n", ip_addr, start_port, end_port);
    
    scan_ports(ip_addr, start_port, end_port);
    
    printf("Port scan completed.\n");
    
    return EXIT_SUCCESS;
}