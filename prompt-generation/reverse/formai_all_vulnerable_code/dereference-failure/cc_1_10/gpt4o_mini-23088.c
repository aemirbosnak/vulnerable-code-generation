//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORT 65535
#define MIN_PORT 1
#define BUFFER_SIZE 1024

typedef struct {
    char *ip_address;
    int start_port;
    int end_port;
} ScanParams;

void *portScan(void *params);
void displayResults(int port, char *status);
void usage(char *programName);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning IP: %s from port %d to port %d\n", ip_address, start_port, end_port);

    pthread_t threads[MAX_THREADS];
    ScanParams params[MAX_THREADS];
    int thread_count = 0;

    for (int i = start_port; i <= end_port; i++) {
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }

        params[thread_count].ip_address = ip_address;
        params[thread_count].start_port = i;
        params[thread_count].end_port = i;

        pthread_create(&threads[thread_count], NULL, portScan, (void*)&params[thread_count]);
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning complete.\n");
    return EXIT_SUCCESS;
}

void *portScan(void *params) {
    ScanParams *scanParams = (ScanParams *)params;
    char *ip_address = scanParams->ip_address;
    int port = scanParams->start_port;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server.sin_addr);

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        displayResults(port, "Open");
    } else {
        displayResults(port, "Closed");
    }
    
    close(sock);
    return NULL;
}

void displayResults(int port, char *status) {
    printf("Port %d: %s\n", port, status);
}

void usage(char *programName) {
    fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", programName);
    fprintf(stderr, "Example: %s 192.168.1.1 1 100\n", programName);
}