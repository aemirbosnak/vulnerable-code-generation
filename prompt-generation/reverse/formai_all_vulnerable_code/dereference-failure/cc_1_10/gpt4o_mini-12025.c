//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 1024
#define TIMEOUT 1  // Timeout for socket connection in seconds
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

// Structure to hold thread data
typedef struct {
    char *ip_address;
    int port;
} thread_data_t;

// Function to scan a port on a given IP address
void *scan_port(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set timeout for connection
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    inet_pton(AF_INET, data->ip_address, &server.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open on %s\n", data->port, data->ip_address);
    }

    close(sock);
    free(data);
    return NULL;
}

// Function to display usage
void display_usage(char *program_name) {
    printf("=== Futuristic Port Scanner ===\n");
    printf("Usage: %s <IP Address>\n", program_name);
    printf("Example: %s 192.168.1.1\n", program_name);
    printf("Scanning ports from %d to %d...\n", PORT_RANGE_START, PORT_RANGE_END);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage(argv[0]);
        return 1;
    }

    // Get the IP address from the command line
    char *ip_address = argv[1];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }

        // Allocate memory for thread data
        thread_data_t *data = malloc(sizeof(thread_data_t));
        if (data == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        data->ip_address = ip_address;
        data->port = port;

        // Create a thread for scanning a port
        if (pthread_create(&threads[thread_count], NULL, scan_port, data) != 0) {
            perror("Thread creation failed");
            free(data);
            return 1;
        }
        thread_count++;
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scanning completed on %s\n", ip_address);
    return 0;
}