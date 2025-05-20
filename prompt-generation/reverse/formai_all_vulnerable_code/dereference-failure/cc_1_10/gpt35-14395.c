//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of threads
#define MAX_THREADS 100

// Define the maximum number of ports
#define MAX_PORTS 65535

// Define the default timeout for port scanning
#define DEFAULT_TIMEOUT 5

// Define a struct for passing arguments to the thread function
struct ThreadArgs {
    char *ip_address;
    int start_port;
    int end_port;
    int timeout;
};

// Define a struct for storing the result of a port scan
struct PortResult {
    int port;
    int status;
};

// Function for scanning a single port
void *scan_port(void *arg) {
    struct PortResult *result = malloc(sizeof(struct PortResult));
    result->port = -1;
    result->status = -1;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        pthread_exit(result);
    }

    struct ThreadArgs *args = (struct ThreadArgs *) arg;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(args->ip_address);
    int timeout = args->timeout;
    
    for (int port = args->start_port; port <= args->end_port; port++) {
        addr.sin_port = htons(port);
        int ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
        if (ret == 0) {
            result->port = port;
            result->status = ret;
            break;
        }
        else if (errno != ECONNREFUSED) {
            fprintf(stderr, "Error connecting to port %d: %s\n", port, strerror(errno));
            break;
        }
        else {
            usleep(timeout * 1000);
        }
    }

    close(sockfd);
    pthread_exit(result);
}

// Function for printing the results of a port scan
void print_results(struct PortResult **results, int num_ports) {
    printf("PORT\tSTATE\n");
    for (int i = 0; i < num_ports; i++) {
        printf("%d\t", results[i]->port);
        if (results[i]->status == 0) {
            printf("open\n");
        }
        else {
            printf("closed\n");
        }
        free(results[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s IP_ADDRESS START_PORT [END_PORT] [NUM_THREADS] [TIMEOUT]\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = (argc >= 4) ? atoi(argv[3]) : MAX_PORTS;
    int num_threads = (argc >= 5) ? atoi(argv[4]) : MAX_THREADS;
    int timeout = (argc >= 6) ? atoi(argv[5]) : DEFAULT_TIMEOUT;

    // Validate command line arguments
    if (start_port < 1 || start_port > MAX_PORTS || end_port < start_port || end_port > MAX_PORTS) {
        fprintf(stderr, "Invalid port range\n");
        return 1;
    }
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        fprintf(stderr, "Invalid number of threads\n");
        return 1;
    }
    if (timeout < 1) {
        fprintf(stderr, "Invalid timeout\n");
        return 1;
    }

    // Allocate memory for thread IDs and argument structs
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    struct ThreadArgs *args = malloc(num_threads * sizeof(struct ThreadArgs));

    // Create threads to scan ports in parallel
    int num_ports = end_port - start_port + 1;
    int ports_per_thread = num_ports / num_threads;
    int remaining_ports = num_ports % num_threads;
    struct PortResult **results = malloc(num_ports * sizeof(struct PortResult *));
    int current_port = start_port;
    for (int i = 0; i < num_threads; i++) {
        args[i].ip_address = ip_address;
        args[i].start_port = current_port;
        args[i].timeout = timeout;
        if (i < remaining_ports) {
            args[i].end_port = current_port + ports_per_thread;
            current_port += (ports_per_thread + 1);
        }
        else {
            args[i].end_port = current_port + ports_per_thread - 1;
            current_port += ports_per_thread;
        }
        pthread_create(&threads[i], NULL, scan_port, &args[i]);
    }

    // Wait for threads to finish and collect results
    for (int i = 0; i < num_threads; i++) {
        struct PortResult *result;
        pthread_join(threads[i], (void **) &result);
        if (result->port != -1 && result->status != -1) {
            results[result->port - start_port] = result;
        }
        else {
            free(result);
        }
    }

    // Print the results of the port scan
    print_results(results, num_ports);

    // Free memory
    free(threads);
    free(args);
    free(results);

    return 0;
}