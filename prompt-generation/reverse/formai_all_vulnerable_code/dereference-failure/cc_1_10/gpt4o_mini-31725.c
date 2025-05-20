//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CONNECTIONS 100
#define TIMEOUT 1

typedef struct {
    char *ip_address;
    int port_number;
} scan_params;

void *port_scan(void *params) {
    scan_params *p = (scan_params *)params;
    int sock;
    struct sockaddr_in server;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set timeout options for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Configure server address structure
    server.sin_family = AF_INET;
    server.sin_port = htons(p->port_number);
    if (inet_pton(AF_INET, p->ip_address, &server.sin_addr) <= 0) {
        perror("Invalid IP address");
        close(sock);
        pthread_exit(NULL);
    }

    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is open\n", p->port_number);
    }
    close(sock);
    pthread_exit(NULL);
}

void scan_ports(const char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_CONNECTIONS];
    scan_params params[MAX_CONNECTIONS];
    
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_CONNECTIONS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }

        params[thread_count].ip_address = (char *)ip_address;
        params[thread_count].port_number = port;

        // Create a new thread to scan the port
        if (pthread_create(&threads[thread_count], NULL, port_scan, (void *)&params[thread_count]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
        thread_count++;
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Port range must be between 1 and 65535 and start port must be less than or equal to end port.\n");
        return EXIT_FAILURE;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);
    scan_ports(ip_address, start_port, end_port);
    printf("Port scanning completed.\n");

    return EXIT_SUCCESS;
}