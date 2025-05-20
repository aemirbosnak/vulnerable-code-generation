//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORT 65535

typedef struct {
    char *ip;
    int port;
} port_info;

void *check_port(void *arg) {
    port_info *info = (port_info *)arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(info->port);
    inet_pton(AF_INET, info->ip, &server.sin_addr);

    // Tune the socket options
    int option = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open on %s\n", info->port, info->ip);
    } else {
        // Uncomment for debugging closed ports
        // printf("Port %d is closed on %s\n", info->port, info->ip);
    }
    
    close(sock);
    free(info);
    return NULL;
}

void scan_ports(char *ip) {
    pthread_t threads[MAX_THREADS];
    int count = 0;

    for (int port = 1; port <= MAX_PORT; port++) {
        port_info *info = (port_info *)malloc(sizeof(port_info));
        info->ip = ip;
        info->port = port;

        if (count >= MAX_THREADS) {
            // Wait for threads to finish
            for (int j = 0; j < count; j++) {
                pthread_join(threads[j], NULL);
            }
            count = 0;  // Reset thread count
        }
        
        pthread_create(&threads[count++], NULL, check_port, info);
    }

    // Wait for remaining threads
    for (int j = 0; j < count; j++) {
        pthread_join(threads[j], NULL);
    }
    printf("Port scanning completed for %s\n", ip);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    printf("Starting port scan on %s...\n", ip);

    scan_ports(ip);

    return 0;
}