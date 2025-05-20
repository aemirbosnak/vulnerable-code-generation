//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10 // Define maximum number of threads the program is allowed to launch.

void *scan(void *arg);
bool is_port_open(const char *host, int port);

// Struct to hold the data that will be passed to each thread.
typedef struct {
    char *ip;
    int start_port;
    int end_port;
} scan_data;

int main(int argc, char **argv) {

    if(argc != 4) {
        fprintf(stderr, "Usage: %s [ip address] [starting port] [ending port]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning ports on %s from %d to %d\n", ip, start_port, end_port);

    // Calculate the range of ports to scan per thread.
    int range_per_thread = (end_port - start_port) / MAX_THREADS;

    pthread_t threads[MAX_THREADS];
    scan_data thread_data[MAX_THREADS];

    // Launch one thread for each part of the range of ports.
    for(int i = 0; i < MAX_THREADS; i++) {

        thread_data[i].ip = ip;
        thread_data[i].start_port = start_port + i * range_per_thread;
        thread_data[i].end_port = start_port + (i+1) * range_per_thread - 1;

        if(i == MAX_THREADS - 1) {
            // Make sure the last thread also scans the last ports that were not assigned due to integer division rounding.
            thread_data[i].end_port = end_port;
        }

        if(pthread_create(&threads[i], NULL, scan, &thread_data[i]) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish.
    for(int i = 0; i < MAX_THREADS; i++) {
        if(pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Failed to join thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    printf("Scan finished\n");
    return EXIT_SUCCESS;
}

void *scan(void *arg) {
    scan_data *data = (scan_data*) arg;

    for(int port = data->start_port; port <= data->end_port; port++) {
        if(is_port_open(data->ip, port)) {
            printf("Port %d on %s is open\n", port, data->ip);
        }
    }

    return NULL;
}

bool is_port_open(const char *host, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        fprintf(stderr, "Failed to create socket for port %d: %s\n", port, strerror(errno));
        return false;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, host, &address.sin_addr);

    if(connect(sockfd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        close(sockfd);
        return false;
    }

    close(sockfd);
    return true;
}