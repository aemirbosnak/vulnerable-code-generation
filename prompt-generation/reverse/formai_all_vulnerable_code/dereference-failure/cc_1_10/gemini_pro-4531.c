//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>

// Structure to hold the port scanning results
typedef struct port_scan_result {
    int port;
    int state; // 0: closed, 1: open
} port_scan_result;

// Structure to hold the thread arguments
typedef struct thread_args {
    char *hostname;
    int start_port;
    int end_port;
    port_scan_result *results;
} thread_args;

// Function to scan a single port
int scan_port(char *hostname, int port) {
    struct addrinfo hints, *res;
    int sockfd;

    // Initialize the hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get the address info for the hostname
    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        return -1;
    }

    // Create a socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        freeaddrinfo(res);
        return -1;
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        close(sockfd);
        freeaddrinfo(res);
        return -1;
    }

    // Connect to the port
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == 0) {
        close(sockfd);
        freeaddrinfo(res);
        return 1;
    } else {
        close(sockfd);
        freeaddrinfo(res);
        return 0;
    }
}

// Function to scan a range of ports
void *scan_ports(void *args) {
    thread_args *arg = (thread_args *)args;

    // Scan the ports
    for (int port = arg->start_port; port <= arg->end_port; port++) {
        arg->results[port - arg->start_port].port = port;
        arg->results[port - arg->start_port].state = scan_port(arg->hostname, port);
    }

    return NULL;
}

// Function to print the port scanning results
void print_results(port_scan_result *results, int num_ports) {
    printf("Port scanning results:\n");
    for (int i = 0; i < num_ports; i++) {
        if (results[i].state == 1) {
            printf("Port %d is open\n", results[i].port);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Create the port scan results array
    int num_ports = end_port - start_port + 1;
    port_scan_result results[num_ports];

    // Create the thread pool
    int num_threads = 4;
    pthread_t threads[num_threads];

    // Divide the ports into chunks and assign each chunk to a thread
    int chunk_size = num_ports / num_threads;
    for (int i = 0; i < num_threads; i++) {
        thread_args *args = malloc(sizeof(thread_args));
        args->hostname = hostname;
        args->start_port = start_port + i * chunk_size;
        args->end_port = (i == num_threads - 1) ? end_port : start_port + (i + 1) * chunk_size - 1;
        args->results = results;

        if (pthread_create(&threads[i], NULL, scan_ports, (void *)args) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    // Print the port scanning results
    print_results(results, num_ports);

    return EXIT_SUCCESS;
}