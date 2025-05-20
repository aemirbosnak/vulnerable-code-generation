//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

typedef struct {
    char* ip;
    int port;
} ScanTask;

void* scan_port(void* arg) {
    ScanTask* task = (ScanTask*) arg;
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    // Configure server structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(task->ip);
    server.sin_port = htons(task->port);

    // Try to connect
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
        printf("Port %d is open on %s\n", task->port, task->ip);
    } else {
        // Connection failed, port is closed
    }
    
    close(sock);
    free(task);
    return NULL;
}

void start_scan(char* ip) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    
    for (int port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        // Check if threads can be created
        if (thread_count >= MAX_THREADS) {
            // Wait for threads to finish before continuing
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count after waiting
        }

        ScanTask* task = malloc(sizeof(ScanTask));
        task->ip = ip;
        task->port = port;

        // Create a thread to scan the port
        pthread_create(&threads[thread_count++], NULL, scan_port, task);
    }

    // Wait for all remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        return 1;
    }
    
    char* ip = argv[1];
    printf("Scanning ports on %s...\n", ip);
    
    start_scan(ip);
    
    printf("Scan complete.\n");
    return 0;
}