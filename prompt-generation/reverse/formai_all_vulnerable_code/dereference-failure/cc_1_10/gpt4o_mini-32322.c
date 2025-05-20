//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define MAX_THREADS 100
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

typedef struct {
    char *ip_address;
    int port;
} thread_data_t;

void* check_port(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int sock;
    struct sockaddr_in target;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(data->port);
    target.sin_addr.s_addr = inet_addr(data->ip_address);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d is open.\n", data->port);
    } else {
        // Uncomment to see closed ports
        // printf("Port %d is closed.\n", data->port);
    }

    close(sock);
    free(data);
    return NULL;
}

void scan_ports(char *ip_address) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }

        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->ip_address = ip_address;
        data->port = port;

        if (pthread_create(&threads[thread_count], NULL, check_port, data) != 0) {
            perror("Failed to create thread");
            free(data);
        } else {
            thread_count++;
        }
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];

    // Scan the provided IP address
    printf("Scanning IP: %s\n", ip_address);
    scan_ports(ip_address);

    printf("Port scanning completed.\n");
    return EXIT_SUCCESS;
}