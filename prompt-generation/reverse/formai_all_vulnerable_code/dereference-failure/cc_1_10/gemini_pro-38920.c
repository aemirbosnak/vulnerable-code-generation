//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Define the thread function
void *thread_func(void *arg) {
    // Get the thread's argument
    int *port = (int *)arg;

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set the socket's timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Connect to the port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(*port);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", *port);
    }

    // Close the socket
    close(sock);

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified a port range
    if (argc < 3) {
        printf("Usage: %s <start port> <end port>\n", argv[0]);
        exit(1);
    }

    // Get the start and end ports
    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    // Create a thread pool
    pthread_t threads[end_port - start_port + 1];
    int i;
    for (i = start_port; i <= end_port; i++) {
        // Create a thread to scan the port
        pthread_create(&threads[i - start_port], NULL, thread_func, &i);
    }

    // Wait for the threads to finish
    for (i = start_port; i <= end_port; i++) {
        pthread_join(threads[i - start_port], NULL);
    }

    // Exit the program
    return 0;
}