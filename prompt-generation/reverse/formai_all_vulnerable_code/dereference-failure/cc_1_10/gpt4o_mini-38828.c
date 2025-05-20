//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 200
#define BUFFER_SIZE 1024

typedef struct {
    char *ip_address;
    int port;
} port_scan_data;

void *scan_port(void *data) {
    port_scan_data *psd = (port_scan_data *)data;
    int sock;
    struct sockaddr_in server;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(psd);
        pthread_exit(NULL);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(psd->ip_address);
    server.sin_port = htons(psd->port);

    // Set a timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = 1;  // 1 second
    timeout.tv_usec = 0; // 0 microseconds
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is OPEN\n", psd->port);
    } else {
        printf("Port %d is CLOSED\n", psd->port);
    }

    close(sock);
    free(psd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP Address> <Start Port>-<End Port>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;

    // Parsing the port range
    char *dash = strchr(port_range, '-');
    if (dash == NULL) {
        fprintf(stderr, "Invalid port range format. Please use <Start Port>-<End Port>\n");
        return 1;
    }

    *dash = '\0';
    start_port = atoi(port_range);
    end_port = atoi(dash + 1);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port numbers. Port must be between 1 and 65535.\n");
        return 1;
    }

    printf("Initiating port scan on %s from port %d to %d...\n", ip_address, start_port, end_port);

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Scan ports
    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            // Wait for threads to finish before spawning new ones
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }

        port_scan_data *psd = malloc(sizeof(port_scan_data));
        psd->ip_address = strdup(ip_address);
        psd->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, psd) != 0) {
            perror("Failed to create thread");
            free(psd);
            continue;
        }
        thread_count++;
    }

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scan completed.\n");
    return 0;
}