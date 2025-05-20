//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 100

// Structure to store the port scan results
typedef struct port_scan_result {
    int port;
    int status; // 0 = closed, 1 = open
} port_scan_result;

// Function to scan a single port
int scan_port(char *ip_address, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return -1;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        return 0; // Port is closed
    } else {
        return 1; // Port is open
    }

    // Close the socket
    close(sockfd);
}

// Function to scan a range of ports
void *scan_ports(void *args) {
    // Unpack the arguments
    char *ip_address = (char *)args;
    int start_port = *(int *)((char *)args + strlen(ip_address) + 1);
    int end_port = *(int *)((char *)args + strlen(ip_address) + 1 + sizeof(int));

    // Scan the ports
    for (int port = start_port; port <= end_port; port++) {
        int status = scan_port(ip_address, port);

        // Store the result
        port_scan_result result;
        result.port = port;
        result.status = status;

        // Print the result
        printf("Port %d: %s\n", port, status ? "open" : "closed");
    }

    return NULL;
}

// Main function
int main(int argc, char **argv) {
    // Check the arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    // Get the arguments
    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Create a thread pool
    pthread_t threads[MAX_THREADS];

    // Divide the ports among the threads
    int num_threads = (end_port - start_port) / MAX_PORTS + 1;
    int port_range = (end_port - start_port) / num_threads;

    for (int i = 0; i < num_threads; i++) {
        // Create the thread arguments
        char *args = malloc(strlen(ip_address) + 1 + sizeof(int) + sizeof(int));
        strcpy(args, ip_address);
        *(int *)((char *)args + strlen(ip_address) + 1) = start_port + i * port_range;
        *(int *)((char *)args + strlen(ip_address) + 1 + sizeof(int)) = start_port + (i + 1) * port_range - 1;

        // Create the thread
        pthread_create(&threads[i], NULL, scan_ports, args);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}