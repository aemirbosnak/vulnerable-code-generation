//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define MAX_THREADS 200
#define MAX_PORT 65535
#define MIN_PORT 1
#define IP_ADDR_LEN 16

struct port_scan_params {
    char *ip;
    int port;
};

void *scan_port(void *args) {
    struct port_scan_params *params = (struct port_scan_params *)args;
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(params);
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(params->ip);
    server.sin_port = htons(params->port);

    // Connection attempt
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", params->port);
    } else {
        // Checking if the error is caused by the connection refusal (port closed)
        if (errno != ECONNREFUSED) {
            printf("Port %d is filtered\n", params->port);
        }
    }
    
    close(sock);
    free(params);
    return NULL;
}

void start_port_scan(char *ip) {
    printf("Starting scan on IP: %s\n", ip);
    pthread_t threads[MAX_THREADS];

    for (int port = MIN_PORT; port <= MAX_PORT; port++) {
        struct port_scan_params *params = malloc(sizeof(struct port_scan_params));
        params->ip = ip;
        params->port = port;

        if (pthread_create(&threads[port - 1], NULL, scan_port, params) != 0) {
            perror("Failed to create thread");
            free(params);
        }

        // To prevent too many threads spawned at once
        if ((port - MIN_PORT + 1) % 10 == 0) {
            for (int j = 0; j < port - MIN_PORT + 1; j++) {
                pthread_join(threads[j], NULL);
            }
        }
    }
    
    // Join any remaining threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scan completed on IP: %s\n", ip);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];

    // Check if valid IPv4 address
    struct sockaddr_in sa;
    int err = inet_pton(AF_INET, ip, &(sa.sin_addr));
    if (err <= 0) {
        fprintf(stderr, "Invalid IP address format.\n");
        return 1;
    }

    start_port_scan(ip);
    return 0;
}