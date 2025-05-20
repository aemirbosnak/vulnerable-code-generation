//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int target_port = 0;
char *target_ip = NULL;

void *port_scanner(void *arg) {
    int port = *(int *)arg;
    int sockfd;
    struct sockaddr_in server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Configure the server address structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, target_ip, &server.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        close(sockfd);
        return NULL;
    }

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Attempt to connect
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        }
    } else {
        printf("Port %d is open\n", port);
    }

    // Clean up
    close(sockfd);
    return NULL;
}

void scan_ports(int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int port_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        // Create a new thread for scanning each port
        if (port_count >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            port_count = 0;
        }

        printf("Scanning port %d...\n", port);
        int *port_ptr = malloc(sizeof(int));
        *port_ptr = port;
        if (pthread_create(&threads[port_count++], NULL, port_scanner, port_ptr) != 0) {
            perror("Failed to create thread");
            free(port_ptr);
            continue;
        }
        free(port_ptr);
    }

    // Ensure all threads complete after finishing the for loop
    for (int i = 0; i < port_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range specified.\n");
        exit(EXIT_FAILURE);
    }

    printf("Starting port scan on %s from port %d to port %d\n", target_ip, start_port, end_port);
    scan_ports(start_port, end_port);

    printf("Port scan completed.\n");
    return 0;
}