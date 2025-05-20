//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int target_port = 0;
char target_ip[16];

void *scan_port(void *arg) {
    int port = *((int *)arg);
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set socket timeout
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

    // Define server
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, target_ip, &server.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d: Open\n", port);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d: Closed\n", port);
    } else {
        printf("Port %d: Filtered\n", port);
    }

    close(sock);
    return NULL;
}

void display_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <target_ip> <start_port> <end_port>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Read command line arguments
    strcpy(target_ip, argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range specified.\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Scan ports
    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }

        // Assign port scanning to thread
        int *port_to_scan = malloc(sizeof(int));
        *port_to_scan = port;
        pthread_create(&threads[thread_count++], NULL, scan_port, port_to_scan);
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}