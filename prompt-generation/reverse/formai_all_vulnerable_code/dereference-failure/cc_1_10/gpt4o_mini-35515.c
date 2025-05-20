//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define MAX_PORT 65535
#define MAX_THREADS 100
#define BUFFER_SIZE 1024

typedef struct {
    char *ip_address;
    int port;
} port_info;

void *port_scan(void *arg) {
    port_info *info = (port_info *)arg;
    int sockfd;
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(info->port);
    server.sin_addr.s_addr = inet_addr(info->ip_address);

    // Connection attempt
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is OPEN\n", info->port);
    } else {
        // Port is closed or filtered
        // Uncomment the next line to show closed ports
        // printf("Port %d is CLOSED\n", info->port);
    }
    
    close(sockfd);
    free(info);
    return NULL;
}

void display_banner() {
    printf("===========================================\n");
    printf("       C Port Scanner - Version 1.0      \n");
    printf("===========================================\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_ip = argv[1];
    display_banner();

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Time measuring
    time_t start = time(NULL);

    // Scan ports
    for (int port = 1; port <= MAX_PORT; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }

        port_info *info = malloc(sizeof(port_info));
        info->ip_address = target_ip;
        info->port = port;

        if (pthread_create(&threads[thread_count], NULL, port_scan, info) != 0) {
            perror("Failed to create thread");
            free(info);
            continue;
        }
        thread_count++;
    }

    // Await termination of threads
    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    // Measure end time
    time_t end = time(NULL);
    printf("Scanning completed in %ld seconds\n", end - start);

    return EXIT_SUCCESS;
}