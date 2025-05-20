//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>

#define PORT_COUNT 65535
#define THREAD_COUNT 100

typedef struct {
    char *ip_address;
    int *ports;
    int start;
    int end;
} scan_args;

void *scan_port(void *args) {
    scan_args *scanArgs = (scan_args *)args;
    char *ip = scanArgs->ip_address;
    int *ports = scanArgs->ports;

    for (int i = scanArgs->start; i < scanArgs->end; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation failed");
            continue;
        }

        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(ports[i]);
        inet_pton(AF_INET, ip, &server.sin_addr);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", ports[i]);
        }

        close(sock);
    }
    return NULL;
}

void scan_ports(char *ip_address, int *ports, int port_count) {
    pthread_t threads[THREAD_COUNT];
    int thread_index = 0;

    for (int i = 0; i < port_count; i += (port_count / THREAD_COUNT)) {
        scan_args *args = malloc(sizeof(scan_args));
        args->ip_address = ip_address;
        args->ports = ports;
        args->start = i;
        args->end = i + (port_count / THREAD_COUNT);
        if (args->end > port_count) args->end = port_count;

        if (pthread_create(&threads[thread_index++], NULL, scan_port, args) != 0) {
            perror("Failed to create thread");
            free(args);
            continue;
        }

        if (thread_index >= THREAD_COUNT) {
            for (int j = 0; j < thread_index; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_index = 0;
        }
    }
    
    // Join remaining threads
    for (int i = 0; i < thread_index; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free any dynamically allocated memory if needed (not used here)
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > PORT_COUNT || start_port > end_port) {
        fprintf(stderr, "Port range must be between 1 and %d, and start must be less than end.\n", PORT_COUNT);
        return 1;
    }

    int port_count = end_port - start_port + 1;
    int *ports = malloc(port_count * sizeof(int));
    if (ports == NULL) {
        perror("Memory allocation for ports failed");
        return 1;
    }

    for (int i = 0; i < port_count; i++) {
        ports[i] = start_port + i;
    }

    scan_ports(ip_address, ports, port_count);
    free(ports);

    return 0;
}