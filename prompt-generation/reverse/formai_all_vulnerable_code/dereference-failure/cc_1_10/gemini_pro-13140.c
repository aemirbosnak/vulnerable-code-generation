//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

// Define the port range to scan
#define START_PORT 1
#define END_PORT 65535

// Define the maximum number of threads to use
#define MAX_THREADS 100

// Define the thread data structure
typedef struct thread_data {
    int start_port;
    int end_port;
    char *ip_address;
    int num_open_ports;
} thread_data_t;

// Define the thread function
void *port_scanner(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Connect to the target IP address and port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(data->start_port);
    addr.sin_addr.s_addr = inet_addr(data->ip_address);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open on %s\n", data->start_port, data->ip_address);
        data->num_open_ports++;
    }

    // Close the socket
    close(sockfd);

    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the command line arguments
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    // Get the IP address from the command line arguments
    char *ip_address = argv[1];

    // Create a thread pool
    pthread_t threads[MAX_THREADS];

    // Divide the port range into chunks and assign each chunk to a thread
    int chunk_size = (END_PORT - START_PORT) / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data_t data;
        data.start_port = START_PORT + i * chunk_size;
        data.end_port = START_PORT + (i + 1) * chunk_size;
        data.ip_address = ip_address;
        data.num_open_ports = 0;
        pthread_create(&threads[i], NULL, port_scanner, &data);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the number of open ports
    int total_open_ports = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        total_open_ports += ((thread_data_t *)threads[i])->num_open_ports;
    }
    printf("Total open ports: %d\n", total_open_ports);

    return 0;
}