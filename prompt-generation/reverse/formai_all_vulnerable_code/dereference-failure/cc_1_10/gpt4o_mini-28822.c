//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

typedef struct {
    char *ip_address;
    int port;
} scan_arg;

void *scan_port(void *arg) {
    scan_arg *scanData = (scan_arg *)arg;
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(scanData->port);
    if (inet_pton(AF_INET, scanData->ip_address, &server.sin_addr) <= 0) {
        perror("Invalid address");
        close(sock);
        return NULL;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", scanData->port);
    }

    close(sock);
    return NULL;
}

void usage() {
    printf("Usage: ./portscanner <ip_address> <start_port> <end_port>\n");
    printf("Example: ./portscanner 192.168.1.1 20 80\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage();
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < PORT_RANGE_START || end_port > PORT_RANGE_END || start_port > end_port) {
        fprintf(stderr, "Port range should be between %d and %d\n", PORT_RANGE_START, PORT_RANGE_END);
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; ++port) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; ++i) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }

        scan_arg *arg = malloc(sizeof(scan_arg));
        arg->ip_address = ip_address;
        arg->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, arg) != 0) {
            perror("Thread creation error");
            free(arg);
            return 1;
        }

        thread_count++;
    }

    // Join remaining threads if they exist
    for (int i = 0; i < thread_count; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}