//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netdb.h>

#define MAX_THREADS 100
#define PORT_RANGE 65535

typedef struct {
    char *ip_address;
    int start_port;
    int end_port;
} thread_data_t;

void *scan_port(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char *ip = data->ip_address;
    int port;

    for (port = data->start_port; port <= data->end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server;

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        inet_pton(AF_INET, ip, &server.sin_addr);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open on %s\n", port, ip);
        }
        close(sock);
    }
    
    return NULL;
}

void print_usage() {
    printf("Usage: ./port_scanner <IP address> <start_port> <end_port>\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > PORT_RANGE || start_port > end_port) {
        print_usage();
    }

    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            printf("Max thread limit reached. Waiting for threads to finish...\n");
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }

        thread_data[thread_count].ip_address = ip_address;
        thread_data[thread_count].start_port = port;
        thread_data[thread_count].end_port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *) &thread_data[thread_count]) != 0) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
        } else {
            thread_count++;
            usleep(5000); // Sleep for a short duration to avoid overwhelming the system
        }
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s from port %d to %d\n", ip_address, start_port, end_port);
    return 0;
}