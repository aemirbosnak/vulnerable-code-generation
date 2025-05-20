//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Constants
#define MAX_PORTS 65535
#define MAX_THREADS 100
#define TIMEOUT 1

// Thread data structure
typedef struct thread_data {
    int start_port;
    int end_port;
    char *hostname;
    int *open_ports;
} thread_data;

// Function to scan a range of ports
void *scan_ports(void *args) {
    // Get the thread data
    thread_data *data = (thread_data *)args;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Iterate over the range of ports
    for (int port = data->start_port; port <= data->end_port; port++) {
        // Create a sockaddr_in structure
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(data->hostname);

        // Connect to the port
        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            // The port is open
            data->open_ports[port] = 1;
            printf("Port %d is open on host %s\n", port, data->hostname);
        } else {
            // The port is closed
            data->open_ports[port] = 0;
        }
    }

    // Close the socket
    close(sockfd);

    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc < 3) {
        printf("Usage: %s <hostname> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the hostname, start port, and end port
    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Check the validity of the start and end ports
    if (start_port < 0 || start_port > MAX_PORTS || end_port < 0 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        exit(EXIT_FAILURE);
    }

    // Allocate an array to store the open ports
    int *open_ports = (int *)malloc(sizeof(int) * (end_port + 1));
    if (open_ports == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Create a thread pool
    pthread_t threads[MAX_THREADS];
    int num_threads = (end_port - start_port) / MAX_THREADS + 1;
    int thread_index = 0;

    // Create threads to scan the ports
    for (int i = start_port; i <= end_port; i += MAX_THREADS) {
        thread_data data;
        data.start_port = i;
        data.end_port = i + MAX_THREADS - 1;
        data.hostname = hostname;
        data.open_ports = open_ports;
        pthread_create(&threads[thread_index++], NULL, scan_ports, (void *)&data);
    }

    // Join the threads
    for (int i = 0; i < thread_index; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the open ports
    for (int port = start_port; port <= end_port; port++) {
        if (open_ports[port]) {
            printf("Port %d is open on host %s\n", port, hostname);
        }
    }

    // Free the allocated memory
    free(open_ports);

    return 0;
}