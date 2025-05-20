//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the range of ports to scan
#define MIN_PORT 1
#define MAX_PORT 65535

// Define the timeout for each port scan
#define TIMEOUT 1

// Define the number of threads to use for scanning
#define NUM_THREADS 10

// Structure to store the results of a port scan
typedef struct {
    int port;
    int state;
} port_scan_result;

// Function to scan a single port
void *scan_port(void *arg) {
    // Get the port to scan
    port_scan_result *result = (port_scan_result *)arg;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Connect to the port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(result->port);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        result->state = 0;
    } else {
        result->state = 1;
    }

    // Close the socket
    close(sockfd);

    return NULL;
}

// Function to scan a range of ports
void scan_ports(int min_port, int max_port) {
    // Create a thread pool
    pthread_t threads[NUM_THREADS];

    // Create an array of port scan results
    port_scan_result results[MAX_PORTS];

    // Initialize the port scan results
    for (int i = 0; i < MAX_PORTS; i++) {
        results[i].port = i;
        results[i].state = -1;
    }

    // Create threads to scan the ports
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, scan_port, &results[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    for (int i = 0; i < MAX_PORTS; i++) {
        if (results[i].state == 1) {
            printf("Port %d is open\n", results[i].port);
        } else if (results[i].state == 0) {
            printf("Port %d is closed\n", results[i].port);
        } else {
            printf("Port %d could not be scanned\n", results[i].port);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a range of ports to scan
    if (argc != 3) {
        printf("Usage: %s <min_port> <max_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the range of ports to scan
    int min_port = atoi(argv[1]);
    int max_port = atoi(argv[2]);

    // Check if the range of ports is valid
    if (min_port < MIN_PORT || min_port > MAX_PORT || max_port < MIN_PORT || max_port > MAX_PORT) {
        printf("Invalid range of ports: %d-%d\n", min_port, max_port);
        exit(EXIT_FAILURE);
    }

    // Scan the range of ports
    scan_ports(min_port, max_port);

    return 0;
}