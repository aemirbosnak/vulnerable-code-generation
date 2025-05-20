//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int open_ports[1024];
int port_count = 0;

void *port_scanner(void *arg) {
    int port = *(int *)arg;
    int sock;
    struct sockaddr_in server;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return NULL;
    }

    // Set timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Initialize server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Scanning localhost

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        // Port is open
        open_ports[port_count++] = port;
    }
    
    close(sock);
    return NULL;
}

void scan_ports(int start, int end) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start; port <= end; port++) {
        if (thread_count < MAX_THREADS) {
            // Create a new thread for each port
            pthread_create(&threads[thread_count], NULL, port_scanner, &port);
            thread_count++;
        } else {
            // Wait for all threads to finish
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

void print_open_ports() {
    if (port_count == 0) {
        printf("No open ports found.\n");
    } else {
        printf("Open ports:\n");
        for (int i = 0; i < port_count; i++) {
            printf("%d\n", open_ports[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    int start_port, end_port;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 1 and 65535.\n");
        return EXIT_FAILURE;
    }

    scan_ports(start_port, end_port);
    print_open_ports();

    return EXIT_SUCCESS;
}