//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define THREAD_COUNT 100

typedef struct {
    char *ip_address;
    int port;
} ScanJob;

int open_socket(const char *ip_address, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result < 0) {
        close(sockfd);
        return 0; // Port is closed
    }
    
    close(sockfd);
    return 1; // Port is open
}

void *scan_port(void *arg) {
    ScanJob *job = (ScanJob *)arg;
    if (open_socket(job->ip_address, job->port)) {
        printf("Port %d is open on %s\n", job->port, job->ip_address);
    } else {
        printf("Port %d is closed on %s\n", job->port, job->ip_address);
    }
    free(job);
    return NULL;
}

void scan_ports(const char *ip_address) {
    pthread_t threads[THREAD_COUNT];
    int thread_count = 0;

    for (int port = MIN_PORT; port <= MAX_PORT; port++) {
        ScanJob *job = malloc(sizeof(ScanJob));
        job->ip_address = strdup(ip_address);
        job->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, job) != 0) {
            perror("Failed to create thread");
            free(job->ip_address);
            free(job);
            continue;
        }

        thread_count++;
        if (thread_count >= THREAD_COUNT) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread counter
        }
    }
    
    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    printf("Starting port scan on %s...\n", ip_address);
    scan_ports(ip_address);
    printf("Port scan completed.\n");

    return EXIT_SUCCESS;
}