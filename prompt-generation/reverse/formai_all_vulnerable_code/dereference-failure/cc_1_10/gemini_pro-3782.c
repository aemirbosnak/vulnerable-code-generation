//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

// Port scanning parameters
#define DEFAULT_PORT_RANGE 100
#define DEFAULT_TIMEOUT 1
#define MAX_THREADS 10

// Thread data structure
typedef struct thread_data {
    int start_port;
    int end_port;
    char *target_ip;
    int *open_ports;
} thread_data;

// Thread function to scan a range of ports
void *scan_ports(void *arg) {
    thread_data *data = (thread_data *)arg;
    int sock;
    struct sockaddr_in addr;
    int timeout = DEFAULT_TIMEOUT;
    int port;
    
    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        pthread_exit(NULL);
    }
    
    // Set socket timeout
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    
    // Initialize the sockaddr_in structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(data->target_ip);
    
    // Scan the range of ports
    for (port = data->start_port; port <= data->end_port; port++) {
        // Set the port number
        addr.sin_port = htons(port);
        
        // Connect to the port
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            // Port is open
            data->open_ports[port - data->start_port] = 1;
            printf("Port %d is open\n", port);
        }
    }
    
    // Close the socket
    close(sock);
    
    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main(int argc, char **argv) {
    int start_port = 0;
    int end_port = DEFAULT_PORT_RANGE;
    char *target_ip;
    int num_threads = MAX_THREADS;
    int i, j;
    int *open_ports;
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];
    
    // Parse command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <target IP> [<start port>] [<end port>] [<num threads>]\n", argv[0]);
        exit(1);
    }
    target_ip = argv[1];
    if (argc >= 3) {
        start_port = atoi(argv[2]);
    }
    if (argc >= 4) {
        end_port = atoi(argv[3]);
    }
    if (argc >= 5) {
        num_threads = atoi(argv[4]);
    }
    
    // Allocate memory for the array of open ports
    open_ports = (int *)malloc(sizeof(int) * (end_port - start_port + 1));
    if (open_ports == NULL) {
        perror("malloc");
        exit(1);
    }
    
    // Initialize the array of open ports
    for (i = 0; i < end_port - start_port + 1; i++) {
        open_ports[i] = 0;
    }
    
    // Create threads to scan the range of ports
    for (i = 0; i < num_threads; i++) {
        // Calculate the start and end ports for this thread
        data[i].start_port = start_port + (i * (end_port - start_port + 1)) / num_threads;
        data[i].end_port = start_port + ((i + 1) * (end_port - start_port + 1)) / num_threads - 1;
        data[i].target_ip = target_ip;
        data[i].open_ports = open_ports;
        
        // Create the thread
        if (pthread_create(&threads[i], NULL, scan_ports, &data[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }
    
    // Wait for all threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print the list of open ports
    printf("Open ports:\n");
    for (i = 0, j = start_port; i < end_port - start_port + 1; i++, j++) {
        if (open_ports[i]) {
            printf("%d\n", j);
        }
    }
    
    // Free the memory allocated for the array of open ports
    free(open_ports);
    
    return 0;
}