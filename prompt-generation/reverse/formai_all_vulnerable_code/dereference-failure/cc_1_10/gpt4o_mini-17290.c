//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <unistd.h>
#include <netinet/tcp.h>

#define MAX_THREADS 100
#define NUM_PORTS 65535
#define TARGET_IP "192.168.1.1"  // Change to your target IP

typedef struct {
    char *ip_address;
    int port;
} port_scan_t;

void *scan_port(void *arg) {
    port_scan_t *port_scan = (port_scan_t *) arg;
    int sock;
    struct sockaddr_in target;
    struct protoent *protocol;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Socket creation failed.");
        return NULL;
    }

    // Prepare the target address
    target.sin_family = AF_INET;
    target.sin_port = htons(port_scan->port);
    inet_pton(AF_INET, port_scan->ip_address, &target.sin_addr);

    // Attempt to connect to the target port
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d is open\n", port_scan->port);
    }
    
    close(sock);
    return NULL;
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];

    for (int port = start_port; port <= end_port; port++) {
        port_scan_t *port_scan = malloc(sizeof(port_scan_t));
        port_scan->ip_address = ip_address;
        port_scan->port = port;

        // Create a new thread for scanning the port
        if (pthread_create(&threads[port - start_port], NULL, scan_port, port_scan) != 0) {
            perror("Failed to create thread.");
            free(port_scan);
            continue;
        }

        // Sleep briefly to limit the number of concurrent threads
        if (port % 10 == 0) {
            usleep(100000);  // Sleep for 100 milliseconds
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < (end_port - start_port + 1); i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > NUM_PORTS || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please use ports between 1 and %d.\n", NUM_PORTS);
        return EXIT_FAILURE;
    }

    // Scan the given range of ports
    scan_ports(ip_address, start_port, end_port);

    return EXIT_SUCCESS;
}