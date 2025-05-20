//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024
#define TIMEOUT 10

// Function to check if a port is open
int is_port_open(int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        close(sockfd);
        return 1;
    } else {
        close(sockfd);
        return 0;
    }
}

// Function to scan a port range
void *scan_ports(void *param) {
    int *port_range = (int *) param;
    int start_port = *port_range;
    int end_port = *port_range + MAX_PORTS / MAX_THREADS;
    for (int i = start_port; i < end_port; i++) {
        if (is_port_open(i)) {
            printf("Port %d is open.\n", i);
        }
    }
    return NULL;
}

// Main function to start the scan
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);
    int num_threads = end_port - start_port + 1;
    if (num_threads > MAX_THREADS) {
        printf("Too many ports to scan.\n");
        exit(EXIT_FAILURE);
    }
    pthread_t threads[num_threads];
    int port_range[num_threads];
    for (int i = 0; i < num_threads; i++) {
        port_range[i] = start_port + i * MAX_PORTS / num_threads;
        pthread_create(&threads[i], NULL, scan_ports, &port_range[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}