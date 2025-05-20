//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

typedef struct {
    char *ip_address;
    int start_port;
    int end_port;
} ThreadData;

void *scan_ports(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int sock;
    struct sockaddr_in server;

    for (int port = data->start_port; port <= data->end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation failed");
            return NULL;
        }

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        inet_pton(AF_INET, data->ip_address, &server.sin_addr);

        // Try to connect
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }
    return NULL;
}

void distribute_scan(char *ip_address, int total_ports, int num_threads) {
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int ports_per_thread = total_ports / num_threads;
    int extra_ports = total_ports % num_threads;

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].ip_address = ip_address;
        thread_data[i].start_port = i * ports_per_thread + 1;

        // Distribute remainder ports among threads if needed
        if (i == num_threads - 1) {
            thread_data[i].end_port = (i + 1) * ports_per_thread + extra_ports; // Last thread gets extra ports
        } else {
            thread_data[i].end_port = (i + 1) * ports_per_thread;
        }

        if (pthread_create(&threads[i], NULL, scan_ports, (void *)&thread_data[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORTS || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 1 and %d.\n", MAX_PORTS);
        exit(EXIT_FAILURE);
    }

    // Calculate total ports to scan and number of threads
    int total_ports = end_port - start_port + 1;
    int num_threads = (total_ports < MAX_THREADS) ? total_ports : MAX_THREADS;

    distribute_scan(ip_address, end_port - start_port + 1, num_threads);

    return 0;
}