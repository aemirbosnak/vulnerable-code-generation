//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

// Some global variables to store user input
char *target_host;
int target_port_start;
int target_port_end;
int num_threads;
int timeout;

// Thread function to scan a single port
void *scan_port(void *arg) {
    int port = *(int *)arg;
    int sockfd;
    struct sockaddr_in addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket timeout
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Initialize the sockaddr_in structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(target_host);

    // Connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
    }

    // Close the socket
    close(sockfd);

    return NULL;
}

// Function to create and manage threads
void scan_ports() {
    // Create a pool of threads
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));

    // Create a thread for each port
    for (int i = target_port_start; i <= target_port_end; i++) {
        if (pthread_create(&threads[i - target_port_start], NULL, scan_port, (void *)&i) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Join all the threads
    for (int i = target_port_start; i <= target_port_end; i++) {
        if (pthread_join(threads[i - target_port_start], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    // Free the memory allocated for the threads
    free(threads);
}

// Function to parse user input
void parse_input(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 6) {
        printf("Usage: %s <target_host> <target_port_start> <target_port_end> <num_threads> <timeout>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse the target host
    target_host = argv[1];

    // Parse the target port range
    target_port_start = atoi(argv[2]);
    target_port_end = atoi(argv[3]);

    // Parse the number of threads
    num_threads = atoi(argv[4]);

    // Parse the timeout
    timeout = atoi(argv[5]);
}

// Main function
int main(int argc, char *argv[]) {
    // Parse user input
    parse_input(argc, argv);

    // Scan the ports
    scan_ports();

    return EXIT_SUCCESS;
}