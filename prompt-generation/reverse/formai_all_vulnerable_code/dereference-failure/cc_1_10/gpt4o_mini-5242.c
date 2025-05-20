//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <pthread.h>
#include <errno.h>

// Number of threads to use for scanning
#define THREADS 100

// Structure to hold port scanner data
typedef struct {
    char *ip_address;
    int start_port;
    int end_port;
} ScannerData;

// Function to perform a port scan on a single port
void *scan_port(void *arg) {
    ScannerData *data = (ScannerData *)arg;
    int sock;
    struct sockaddr_in server;

    for (int port = data->start_port; port <= data->end_port; port++) {
        // Create socket
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Socket creation failed");
            return NULL;
        }

        // Set up server struct
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr(data->ip_address);

        // Attempt to connect to the port
        int connection_status = connect(sock, (struct sockaddr *)&server, sizeof(server));
        
        // If connected, print the port
        if (connection_status == 0) {
            printf("Port %d is open on %s\n", port, data->ip_address);
        }
        
        // Close the socket
        close(sock);
    }
    
    return NULL;
}

// Function to manage the scanning across multiple threads
void start_scanning(char *ip_address, int start_port, int end_port) {
    pthread_t threads[THREADS];
    ScannerData data[THREADS];
    
    int ports_per_thread = (end_port - start_port + 1) / THREADS;
    for (int i = 0; i < THREADS; i++) {
        data[i].ip_address = ip_address;
        data[i].start_port = start_port + i * ports_per_thread;
        data[i].end_port = (i == THREADS - 1) ? end_port : (start_port + (i + 1) * ports_per_thread - 1);

        pthread_create(&threads[i], NULL, scan_port, (void *)&data[i]);
    }

    // Wait for all threads to finish their execution
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate input ports
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please use the range between 1 and 65535.\n");
        exit(EXIT_FAILURE);
    }

    printf("Starting port scan on %s from port %d to port %d...\n", ip_address, start_port, end_port);
    
    // Start the scanning process
    start_scanning(ip_address, start_port, end_port);

    printf("Port scan completed!\n");
    return 0;
}