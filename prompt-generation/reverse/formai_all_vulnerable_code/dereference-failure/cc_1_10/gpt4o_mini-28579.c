//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE 1024
#define TIMEOUT 1

typedef struct {
    char *ip;
    int port;
} scan_args;

void *scan_port(void *args) {
    scan_args *scan_info = (scan_args *)args;
    int sock;
    struct sockaddr_in target;
    
    // Initialize the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }
    
    // Set the timeout option for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    
    // Set up the target address structure
    target.sin_family = AF_INET;
    target.sin_port = htons(scan_info->port);
    inet_pton(AF_INET, scan_info->ip, &target.sin_addr);
    
    // Attempt to connect to the target port
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d is open on %s\n", scan_info->port, scan_info->ip);
    } else {
        // Uncomment the line below to print closed ports as well
        // printf("Port %d is closed on %s\n", scan_info->port, scan_info->ip);
    }
    
    close(sock);
    free(scan_info);
    pthread_exit(NULL);
}

void scan_ports(const char *ip) {
    pthread_t threads[PORT_RANGE];
    int thread_count = 0;

    printf("Scanning ports on IP Address: %s\n", ip);
    
    for (int port = 1; port <= PORT_RANGE; port++) {
        // Allocate memory for thread arguments
        scan_args *args = malloc(sizeof(scan_args));
        args->ip = strdup(ip);
        args->port = port;
        
        // Create a new thread for the port scan
        if (pthread_create(&threads[thread_count++], NULL, scan_port, args) != 0) {
            perror("Failed to create thread");
            free(args->ip);
            free(args);
        }

        // Join threads periodically to avoid exceeding MAX_THREADS
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

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *target_ip = argv[1];

    // Start the port scan
    scan_ports(target_ip);

    return 0;
}