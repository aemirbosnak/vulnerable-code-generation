//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip;
    int port;
} port_arg;

void *scan_port(void *arg) {
    port_arg *p_arg = (port_arg *)arg;
    char *ip = p_arg->ip;
    int port = p_arg->port;

    int sockfd;
    struct sockaddr_in target;
    struct timeval tv;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        return NULL;
    }

    // Set timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Initialize target structure
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    // Attempt to connect
    if (connect(sockfd, (struct sockaddr*)&target, sizeof(target)) >= 0) {
        printf("Port %d is open on %s\n", port, ip);
    }

    close(sockfd);
    return NULL;
}

void scan_ports(char *ip) {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = 1; port <= 65535; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }

        port_arg *p_arg = malloc(sizeof(port_arg));
        p_arg->ip = ip;
        p_arg->port = port;

        pthread_create(&threads[thread_count++], NULL, scan_port, (void *)p_arg);
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = argv[1];
    printf("Scanning ports on %s...\n", ip);
    scan_ports(ip);

    return EXIT_SUCCESS;
}