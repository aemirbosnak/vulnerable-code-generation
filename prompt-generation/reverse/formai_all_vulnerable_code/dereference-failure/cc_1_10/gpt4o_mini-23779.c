//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define DEFAULT_TIMEOUT 1
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

typedef struct {
    char *ip_address;
    int port;
} PortScanArgument;

void *scan_port(void *arg) {
    PortScanArgument *ps_arg = (PortScanArgument *)arg;
    int sock;
    struct sockaddr_in server;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(ps_arg->port);
    inet_pton(AF_INET, ps_arg->ip_address, &server.sin_addr);

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = DEFAULT_TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof timeout);

    // Try to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d on %s is open\n", ps_arg->port, ps_arg->ip_address);
    } else {
        // Optionally print closed ports (comment if not needed)
        // printf("Port %d on %s is closed\n", ps_arg->port, ps_arg->ip_address);
    }
    
    close(sock);
    free(ps_arg);
    return NULL;
}

void scan_ports(char *ip_address) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        PortScanArgument *arg = malloc(sizeof(PortScanArgument));
        arg->ip_address = strdup(ip_address);
        arg->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, arg) != 0) {
            perror("Failed to create thread");
            free(arg->ip_address);
            free(arg);
        }

        thread_count++;
        
        // Limit the number of threads running simultaneously 
        if (thread_count >= 100) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread counter
        }
    }

    // Wait for remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    printf("Starting port scan on %s...\n", ip_address);
    scan_ports(ip_address);
    printf("Port scan completed.\n");
    
    return EXIT_SUCCESS;
}