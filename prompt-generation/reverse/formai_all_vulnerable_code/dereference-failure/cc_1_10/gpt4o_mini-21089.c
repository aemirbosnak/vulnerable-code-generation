//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip;
    int port;
} scan_arg;

void *scan_port(void *arg) {
    scan_arg *s_arg = (scan_arg *)arg;
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        free(arg);
        return NULL;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(s_arg->ip);
    server_addr.sin_port = htons(s_arg->port);

    // Set timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT; 
    tv.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    if (result >= 0) {
        printf("Port %d is open on %s\n", s_arg->port, s_arg->ip);
    }

    close(sockfd);
    free(arg);
    return NULL;
}

int main() {
    char ip[16];
    int start_port, end_port;
    
    printf("Enter IP address to scan: ");
    scanf("%15s", ip);
    
    printf("Enter start port: ");
    scanf("%d", &start_port);
    
    printf("Enter end port: ");
    scanf("%d", &end_port);
    
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range!\n");
        return 1;
    }
    
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        scan_arg *arg = malloc(sizeof(scan_arg));
        arg->ip = strdup(ip);
        arg->port = port;

        if (pthread_create(&threads[thread_count++], NULL, scan_port, arg) != 0) {
            perror("Failed to create thread");
            free(arg->ip);
            free(arg);
            continue; // Skip this port
        }

        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset count after joining
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}