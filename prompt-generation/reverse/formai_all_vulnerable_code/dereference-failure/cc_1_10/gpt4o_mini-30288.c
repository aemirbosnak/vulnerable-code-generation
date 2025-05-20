//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

int open_ports[PORT_RANGE_END - PORT_RANGE_START + 1];
pthread_t threads[MAX_THREADS];
int thread_count = 0;
pthread_mutex_t lock;

void* scan_port(void* arg) {
    int port = *((int*)arg);
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        pthread_mutex_lock(&lock);
        open_ports[port - PORT_RANGE_START] = 1; // Mark port as open
        pthread_mutex_unlock(&lock);
    }
    close(sock);
    return NULL;
}

void print_open_ports() {
    printf("\nOpen Ports:\n");
    for (int i = 0; i < (PORT_RANGE_END - PORT_RANGE_START + 1); i++) {
        if (open_ports[i]) {
            printf("Port %d is open\n", i + PORT_RANGE_START);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    const char* target_ip = argv[1];
    memset(open_ports, 0, sizeof(open_ports));
    pthread_mutex_init(&lock, NULL);

    // Create threads for scanning ports
    for (int port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL); // Wait for all threads to complete
            }
            thread_count = 0; // Reset thread count
        }

        int* arg = malloc(sizeof(*arg));
        *arg = port;
        if (pthread_create(&threads[thread_count++], NULL, scan_port, arg) != 0) {
            perror("Failed to create thread");
            free(arg);
            return 1;
        }
        free(arg);
    }

    // Wait for remaining threads
    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    // Print results
    print_open_ports();

    pthread_mutex_destroy(&lock);
    return 0;
}