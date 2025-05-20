//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100

typedef struct {
    char *ip;
    int start_port;
    int end_port;
    int thread_id;
} ScanData;

void *scan_port(void *arg) {
    ScanData *data = (ScanData *)arg;
    char *ip = data->ip;
    int start_port = data->start_port;
    int end_port = data->end_port;
    int thread_id = data->thread_id;
    
    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server;

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr(ip);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Thread %d: Port %d is open\n", thread_id, port);
        }
        close(sock);
    }
    
    return NULL;
}

void create_threads(char *ip, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    ScanData thread_data[MAX_THREADS];
    int ports_per_thread = (end_port - start_port + 1) / MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].ip = ip;
        thread_data[i].start_port = start_port + i * ports_per_thread;
        
        if (i == MAX_THREADS - 1) {
            thread_data[i].end_port = end_port;
        } else {
            thread_data[i].end_port = start_port + (i + 1) * ports_per_thread - 1;
        }
        
        thread_data[i].thread_id = i;

        if (pthread_create(&threads[i], NULL, scan_port, (void *)&thread_data[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Port range is invalid. Use ports between 1 and 65535.\n");
        exit(EXIT_FAILURE);
    }

    printf("Scanning IP: %s from port %d to %d\n", ip, start_port, end_port);

    create_threads(ip, start_port, end_port);

    return 0;
}