//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100

// Structure to store the results of a port scan
typedef struct port_scan_result {
    unsigned short port;
    bool open;
    char *hostname;
} port_scan_result;

// Queue to store the results of port scans
typedef struct port_scan_result_queue {
    port_scan_result *results;
    int head;
    int tail;
    int size;
} port_scan_result_queue;

// Function to create a new port scan result queue
port_scan_result_queue *create_port_scan_result_queue(int size) {
    port_scan_result_queue *queue = malloc(sizeof(port_scan_result_queue));
    queue->results = malloc(sizeof(port_scan_result) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

// Function to add a port scan result to the queue
void add_port_scan_result(port_scan_result_queue *queue, port_scan_result result) {
    queue->results[queue->tail] = result;
    queue->tail = (queue->tail + 1) % queue->size;
    if (queue->tail == queue->head) {
        queue->head = (queue->head + 1) % queue->size;
    }
}

// Function to get the next port scan result from the queue
port_scan_result get_next_port_scan_result(port_scan_result_queue *queue) {
    port_scan_result result = queue->results[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return result;
}

// Function to create a new socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to connect to a host on a given port
int connect_to_host(char *hostname, unsigned short port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(hostname);
    int sockfd = create_socket();
    int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (result == -1) {
        close(sockfd);
        return -1;
    }
    return sockfd;
}

// Function to scan a host for open ports
void *port_scan(void *args) {
    port_scan_result_queue *queue = (port_scan_result_queue *)args;
    char *hostname = queue->results[queue->head].hostname;
    for (unsigned short port = 1; port <= MAX_PORTS; port++) {
        int sockfd = connect_to_host(hostname, port);
        if (sockfd != -1) {
            port_scan_result result;
            result.port = port;
            result.open = true;
            result.hostname = hostname;
            add_port_scan_result(queue, result);
            close(sockfd);
        }
    }
    return NULL;
}

// Function to print the results of a port scan
void print_port_scan_results(port_scan_result_queue *queue) {
    while (queue->head != queue->tail) {
        port_scan_result result = get_next_port_scan_result(queue);
        printf("%s:%hu %s\n", result.hostname, result.port, result.open ? "open" : "closed");
    }
}

// Function to signal the main thread to stop
void signal_handler(int signum) {
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a port scan result queue
    port_scan_result_queue *queue = create_port_scan_result_queue(MAX_PORTS);

    // Create a thread pool to perform the port scans
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, port_scan, (void *)queue);
    }

    // Add the hostname to the queue
    port_scan_result result;
    result.port = 0;
    result.open = false;
    result.hostname = argv[1];
    add_port_scan_result(queue, result);

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results of the port scan
    print_port_scan_results(queue);

    // Free the port scan result queue
    free(queue->results);
    free(queue);

    return EXIT_SUCCESS;
}