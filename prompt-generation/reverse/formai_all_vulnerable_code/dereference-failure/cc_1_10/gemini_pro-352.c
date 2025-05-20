//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// Initialize the mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// Set the default port range
int port_start = 1;
int port_end = 65535;

// Create a socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Connect to a host and port
int connect_to_host(char *host, int port) {
    struct sockaddr_in addr;
    int sockfd = create_socket();

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    int conn = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (conn == -1) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Scan a single port
void *scan_port(void *arg) {
    int port = *(int *)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Connect to the port
    int sockfd = connect_to_host("127.0.0.1", port);
    // If the connection was successful, print the port number
    if (sockfd != -1) {
        printf("Port %d is open\n", port);
        close(sockfd);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Scan a range of ports
void scan_ports(int start, int end) {
    // Create a thread pool
    pthread_t threads[end - start + 1];

    // Create a thread for each port
    for (int i = start; i <= end; i++) {
        pthread_create(&threads[i - start], NULL, scan_port, &i);
    }

    // Join all the threads
    for (int i = start; i <= end; i++) {
        pthread_join(threads[i - start], NULL);
    }
}

int main(int argc, char *argv[]) {
    // Parse the command line arguments
    if (argc >= 3) {
        port_start = atoi(argv[1]);
        port_end = atoi(argv[2]);
    }

    // Scan the ports
    scan_ports(port_start, port_end);

    return 0;
}