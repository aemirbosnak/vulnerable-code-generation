//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the maximum number of threads to use
#define MAX_THREADS 100

// Define the port range to scan
#define MIN_PORT 1
#define MAX_PORT 65535

// Define the timeout value for each thread
#define TIMEOUT 1

// Define the maximum number of ports to scan per thread
#define PORTS_PER_THREAD 100

// Create a struct to hold the arguments for each thread
typedef struct thread_args {
    int start_port;
    int end_port;
    char *target_ip;
} thread_args;

// Create a mutex to protect the shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a condition variable to signal when all threads have finished
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Create an array to store the results of the scan
int *results;

// Create a function to scan a range of ports
void *scan_ports(void *args) {
    // Get the arguments from the struct
    thread_args *targs = (thread_args *)args;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Convert the target IP address to a binary format
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(targs->target_ip);

    // Iterate over the range of ports
    for (int port = targs->start_port; port <= targs->end_port; port++) {
        // Set the port number in the target address
        target_addr.sin_port = htons(port);

        // Attempt to connect to the port
        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            // Acquire the mutex to protect the shared data
            pthread_mutex_lock(&mutex);

            // Store the result in the array
            results[port] = 1;

            // Release the mutex
            pthread_mutex_unlock(&mutex);
        }
    }

    // Close the socket
    close(sockfd);

    // Signal that the thread has finished
    pthread_cond_signal(&cond);

    return NULL;
}

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        printf("Usage: %s <target IP> <number of threads>\n", argv[0]);
        exit(1);
    }

    // Get the target IP address
    char *target_ip = argv[1];

    // Get the number of threads
    int num_threads = atoi(argv[2]);

    // Check if the number of threads is valid
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Error: The number of threads must be between 1 and %d\n", MAX_THREADS);
        exit(1);
    }

    // Calculate the number of ports to scan per thread
    int ports_per_thread = (MAX_PORT - MIN_PORT) / num_threads;

    // Create an array to store the thread arguments
    thread_args *targs = malloc(sizeof(thread_args) * num_threads);

    // Create an array to store the thread IDs
    pthread_t *tids = malloc(sizeof(pthread_t) * num_threads);

    // Initialize the results array
    results = malloc(sizeof(int) * (MAX_PORT + 1));

    // Iterate over the number of threads and create each thread
    for (int i = 0; i < num_threads; i++) {
        targs[i].start_port = MIN_PORT + (i * ports_per_thread);
        targs[i].end_port = MIN_PORT + ((i + 1) * ports_per_thread) - 1;
        targs[i].target_ip = target_ip;

        if (pthread_create(&tids[i], NULL, scan_ports, &targs[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for all threads to finish
    pthread_cond_wait(&cond, &mutex);

    // Print the results
    for (int port = MIN_PORT; port <= MAX_PORT; port++) {
        if (results[port] == 1) {
            printf("Port %d: Open\n", port);
        }
    }

    // Free the allocated memory
    free(targs);
    free(tids);
    free(results);

    return 0;
}