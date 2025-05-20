//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip_address;
    int port;
} PortScanArgs;

void *scan_port(void *args) {
    PortScanArgs *portArgs = (PortScanArgs *)args;
    int sockfd;
    struct sockaddr_in server_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portArgs->port);
    
    if (inet_pton(AF_INET, portArgs->ip_address, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        pthread_exit(NULL);
    }

    int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result == 0) {
        printf("Port %d is open\n", portArgs->port);
    }

    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        PortScanArgs *args = malloc(sizeof(PortScanArgs));
        args->ip_address = ip_address;
        args->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, args) != 0) {
            perror("Failed to create thread");
            free(args);
            continue;
        }
        
        thread_count++;
        
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

    return EXIT_SUCCESS;
}