//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

// Function to scan a single port
void* scan_port(void* arg) {
    int port = *(int*)arg;
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set timeout for connect
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Attempt to connect to the port
    int connect_result = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (connect_result == 0) {
        printf("Port %d is open\n", port);
    } else {
        // Port likely closed
    }

    close(sockfd);
    return NULL;
}

void scan_ports(int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int port_count = 0;
    int ports[MAX_THREADS];

    for (int port = start_port; port <= end_port; port++) {
        // Manage the thread limit
        if (port_count >= MAX_THREADS) {
            for (int i = 0; i < port_count; i++) {
                pthread_join(threads[i], NULL);
            }
            port_count = 0;
        }

        ports[port_count] = port;
        pthread_create(&threads[port_count], NULL, scan_port, &ports[port_count]);
        port_count++;
    }

    // Join remaining threads
    for (int i = 0; i < port_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Please enter valid port range (1-65535) with start less than or equal to end.\n");
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports from %d to %d...\n", start_port, end_port);
    scan_ports(start_port, end_port);
    
    printf("Port scan completed.\n");
    return 0;
}