//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define TIMEOUT 1
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

typedef struct {
    char *ip_address;
    int start_port;
    int end_port;
} scan_data;

void *scan_port(void *arg) {
    int sock;
    struct sockaddr_in server;
    scan_data *data = (scan_data *)arg;

    for (int port = data->start_port; port <= data->end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
            return NULL;
        }

        // Set timeout for the socket
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        if (inet_pton(AF_INET, data->ip_address, &server.sin_addr) <= 0) {
            fprintf(stderr, "Invalid address: %s\n", data->ip_address);
            close(sock);
            return NULL; 
        }

        // Attempt to connect
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
            printf("Port %d is open\n", port);
        }

        // Close socket
        close(sock);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < PORT_RANGE_START || end_port > PORT_RANGE_END || start_port > end_port) {
        fprintf(stderr, "Port range must be between %d and %d, and start port must be less than or equal to end port.\n", PORT_RANGE_START, PORT_RANGE_END);
        exit(EXIT_FAILURE);
    }

    pthread_t threads[MAX_THREADS];
    scan_data data[MAX_THREADS];
    int thread_count = 0;

    // Calculate the number of port ranges per thread
    int ports_per_thread = (end_port - start_port + 1) / MAX_THREADS;
    
    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].ip_address = ip_address;
        data[i].start_port = start_port + i * ports_per_thread;
        if (i == MAX_THREADS - 1) {
            data[i].end_port = end_port;  // Last thread takes all remaining ports
        } else {
            data[i].end_port = data[i].start_port + ports_per_thread - 1;
        }

        if (data[i].start_port <= end_port) {
            pthread_create(&threads[i], NULL, scan_port, (void *)&data[i]);
            thread_count++;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}