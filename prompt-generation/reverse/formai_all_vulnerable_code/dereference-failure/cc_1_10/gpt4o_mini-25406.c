//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int open_ports[65536];
int port_counter = 0;

void *scan_port(void *arg) {
    int port = *(int *)arg;
    int sock;
    struct sockaddr_in server;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Configure server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        open_ports[port_counter++] = port;
        close(sock);
    }
    close(sock);
    return NULL;
}

void usage(const char *progname) {
    fprintf(stderr, "Usage: %s <start_port> <end_port>\n", progname);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Port range must be between 1 and 65535 and should be valid.\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int port;

    // Start the scanning
    printf("Starting port scan from %d to %d...\n", start_port, end_port);
    clock_t start_time = clock();

    for (port = start_port; port <= end_port; port++) {
        // Check if we have enough threads
        if (port_counter >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            port_counter = 0; // Reset counter for the next batch
        }

        int *arg = malloc(sizeof(*arg));
        *arg = port;
        if (pthread_create(&threads[port_counter], NULL, scan_port, arg) != 0) {
            perror("Thread creation failed");
            free(arg);
            return 1;
        }
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < port_counter; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    clock_t end_time = clock();
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Scan complete! Found open ports:\n");
    for (int i = 0; i < port_counter; i++) {
        printf("Port %d is open!\n", open_ports[i]);
    }
    printf("Duration: %.2f seconds\n", duration);

    return 0;
}