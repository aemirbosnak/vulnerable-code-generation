//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

#define TIMEOUT 1
#define NUM_THREADS 100

typedef struct {
    char *ip_address;
    int start_port;
    int end_port;
} scanner_args;

void *scan_ports(void *args) {
    scanner_args *scan_args = (scanner_args *)args;
    char *ip = scan_args->ip_address;
    int start_port = scan_args->start_port;
    int end_port = scan_args->end_port;

    for (int port = start_port; port <= end_port; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip, &server_addr.sin_addr);

        // Set socket timeout
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

        int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (result >= 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            // The connection was refused, meaning the port is closed
        } else {
            printf("Port %d is closed (error: %s)\n", port, strerror(errno));
        }
        
        close(sockfd);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please specify 1-65535 for start and end ports\n");
        exit(EXIT_FAILURE);
    }

    pthread_t threads[NUM_THREADS];
    int range_per_thread = (end_port - start_port + 1) / NUM_THREADS;
    
    scanner_args args[NUM_THREADS];

    // Start scanning using multiple threads
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].ip_address = ip_address;
        args[i].start_port = start_port + i * range_per_thread;
        args[i].end_port = (i == NUM_THREADS - 1) ? end_port : (start_port + (i + 1) * range_per_thread - 1);
        
        if (pthread_create(&threads[i], NULL, scan_ports, (void *)&args[i]) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s\n", ip_address);
    return 0;
}