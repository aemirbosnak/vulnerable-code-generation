//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100

int open_ports[65536] = {0};
int total_ports_scanned = 0;

void *scan_port(void *arg) {
    int port = *(int*)arg;
    int sock;
    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to target IP

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }
    
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        open_ports[port] = 1; // Mark the port as open
    }
    
    close(sock);
    return NULL;
}

void scan_ports(int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int port_ids[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        port_ids[thread_count] = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, &port_ids[thread_count]) != 0) {
            perror("Thread creation failed");
            continue;
        }
        
        thread_count++;
        total_ports_scanned++;

        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset for the next batch
        }
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

void display_results(int start_port, int end_port) {
    printf("Open ports for target IP:\n");
    for (int port = start_port; port <= end_port; port++) {
        if (open_ports[port]) {
            printf("Port %d is open\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port < 0 || end_port > 65535 || start_port > end_port) {
        printf("Please provide valid port range (0-65535).\n");
        return 1;
    }

    scan_ports(start_port, end_port);
    display_results(start_port, end_port);

    printf("Total ports scanned: %d\n", total_ports_scanned);
    
    return 0;
}