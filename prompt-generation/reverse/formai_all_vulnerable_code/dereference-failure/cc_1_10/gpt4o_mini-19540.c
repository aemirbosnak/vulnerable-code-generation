//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100

// Define a structure to pass multiple arguments to the thread function
typedef struct {
    char *ip_address;
    int port;
} thread_data_t;

// Function to check if a port is open
void *check_port(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int sock;
    struct sockaddr_in server;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    inet_pton(AF_INET, data->ip_address, &server.sin_addr);

    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is open\n", data->port);
    } else {
        printf("Port %d is closed\n", data->port);
    }

    // Close socket
    close(sock);
    free(data);
    return NULL;
}

// Function to validate the command line arguments
void validate_args(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <Port range>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}

// Function to parse the port range from user input
void parse_port_range(char *port_range, int *start, int *end) {
    char *delimiter = "-";
    char *ptr = strtok(port_range, delimiter);
    *start = atoi(ptr);
    
    ptr = strtok(NULL, delimiter);
    *end = atoi(ptr);
}

// Main function
int main(int argc, char *argv[]) {
    validate_args(argc, argv);
    
    int start_port, end_port;
    parse_port_range(argv[2], &start_port, &end_port);
    
    if (start_port < 0 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 0-65535.\n");
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }

        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->ip_address = ip_address;
        data->port = port;

        if (pthread_create(&threads[thread_count++], NULL, check_port, data) != 0) {
            perror("Failed to create thread");
            free(data);
        }
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for IP: %s\n", ip_address);
    return 0;
}