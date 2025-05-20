//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip;
    int port;
} PortScanTask;

void *scan_port(void *arg) {
    PortScanTask *task = (PortScanTask *)arg;
    int sockfd;
    struct sockaddr_in target;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(task->port);
    inet_pton(AF_INET, task->ip, &target.sin_addr);

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT; // Timeout in seconds
    tv.tv_usec = 0;      // Timeout in microseconds
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    
    if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) < 0) {
        printf("Port %d: Closed\n", task->port);
    } else {
        printf("Port %d: Open\n", task->port);
    }

    close(sockfd);
    pthread_exit(NULL);
}

void print_usage() {
    printf("Usage: ./port_scanner <IP Address> <Start Port> <End Port>\n");
    printf("Example: ./port_scanner 127.0.0.1 1 1024\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    
    if (start_port < 0 || end_port > 65535 || start_port > end_port) {
        printf("Please enter valid port range (0 - 65535)\n");
        return 1;
    }

    printf("Starting port scan on %s from port %d to %d...\n", ip_address, start_port, end_port);

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    
    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }
        
        PortScanTask *task = malloc(sizeof(PortScanTask));
        task->ip = ip_address;
        task->port = port;
        
        pthread_create(&threads[thread_count], NULL, scan_port, task);
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scan complete!\n");
    return 0;
}