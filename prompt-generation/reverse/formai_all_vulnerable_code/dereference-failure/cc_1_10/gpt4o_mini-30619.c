//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>

#define MAX_THREADS 1000
#define TIMEOUT 1 // timeout for each scan in seconds

typedef struct {
    char *ip_address;
    int port;
} scan_data;

void *scan_port(void *arg) {
    scan_data *sd = (scan_data *)arg;
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(sd->port);
    inet_pton(AF_INET, sd->ip_address, &server.sin_addr);

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    // Try to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is open on %s\n", sd->port, sd->ip_address);
    }

    close(sock);
    return NULL;
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    scan_data sd[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        sd[thread_count].ip_address = ip_address;
        sd[thread_count].port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, &sd[thread_count]) != 0) {
            perror("Failed to create thread");
        }

        thread_count++;
        if (thread_count >= MAX_THREADS) {
            break;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <IP> <Start Port> <End Port>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 0 || end_port > 65535 || start_port > end_port) {
        printf("Error: Invalid port range.\n");
        return 1;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);
    
    // Actual port scanning
    scan_ports(ip_address, start_port, end_port);

    printf("Port scan completed.\n");
    return 0;
}