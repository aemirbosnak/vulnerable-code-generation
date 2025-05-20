//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netinet/in.h>

// Define a structure to hold thread data
typedef struct {
    char *ip;
    int port;
} thread_data_t;

// Function to scan a specific port
void *port_scan(void *args) {
    thread_data_t *data = (thread_data_t *)args;
    int sock;
    struct sockaddr_in server;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        return NULL;
    }

    // Set timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = 1; // 1 second timeout
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Configure the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    
    // Convert IP address from text to binary
    if (inet_pton(AF_INET, data->ip, &server.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return NULL;
    }
    
    // Attempt connection
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Port %d closed\n", data->port);
    } else {
        printf("Port %d is open\n", data->port);
    }

    // Close the socket
    close(sock);
    return NULL;
}

// Function to create and join threads for scanning ports
void scan_ports(char *ip, int start_port, int end_port) {
    pthread_t threads[end_port - start_port + 1];
    thread_data_t thread_data[end_port - start_port + 1];

    for (int port = start_port; port <= end_port; port++) {
        thread_data[port - start_port].ip = ip;
        thread_data[port - start_port].port = port;
        
        // Create a thread for each port
        if (pthread_create(&threads[port - start_port], NULL, port_scan, &thread_data[port - start_port]) != 0) {
            perror("Failed to create thread");
        }
    }

    for (int port = start_port; port <= end_port; port++) {
        // Wait for all threads to finish
        pthread_join(threads[port - start_port], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 1 and 65535.\n");
        return EXIT_FAILURE;
    }

    printf("Scanning ports from %d to %d on IP: %s...\n", start_port, end_port, ip_address);
    scan_ports(ip_address, start_port, end_port);
    
    return EXIT_SUCCESS;
}