//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_MIN 1
#define PORT_MAX 65535

typedef struct {
    char *ip_address;
    int port;
} ScanTask;

void *scan_port(void *arg) {
    ScanTask *task = (ScanTask *) arg;
    struct sockaddr_in server;
    int sock;
    
    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(task->port);
    inet_pton(AF_INET, task->ip_address, &server.sin_addr);
    
    // Attempt to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d: OPEN\n", task->port);
    } else {
        printf("Port %d: CLOSED\n", task->port);
    }
    
    close(sock);
    free(task);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *ip_address = argv[1];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    
    for (int port = PORT_MIN; port <= PORT_MAX; port++) {
        if (thread_count >= MAX_THREADS) {
            // Wait for all threads to complete before continuing
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // reset thread count after all threads are joined
        }
        
        ScanTask *task = malloc(sizeof(ScanTask));
        task->ip_address = ip_address;
        task->port = port;

        if (pthread_create(&threads[thread_count++], NULL, scan_port, task) != 0) {
            perror("Failed to create thread");
            free(task);
            exit(EXIT_FAILURE);
        }
    }
    
    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Port scanning completed for %s.\n", ip_address);
    return 0;
}