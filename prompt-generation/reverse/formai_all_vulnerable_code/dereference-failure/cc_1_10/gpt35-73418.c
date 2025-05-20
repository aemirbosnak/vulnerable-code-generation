//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 1000

void *scan_port(void *arg);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <ip address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // validate start and end ports
    if (start_port <= 0 || end_port <= 0 || start_port > end_port || end_port > 65535) {
        printf("Invalid port range\n");
        return 1;
    }

    // initialize thread pool
    pthread_t threads[MAX_THREADS];

    // scan each port in the range using a separate thread for each port
    int thread_count = 0;
    for (int port = start_port; port <= end_port; port++) {
        // create thread
        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *) (intptr_t) port) != 0) {
            printf("Failed to create thread for port %d\n", port);
            continue;
        }

        // increment thread count
        thread_count++;

        // limit number of threads
        if (thread_count == MAX_THREADS) {
            // join existing threads
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }

            // reset thread count
            thread_count = 0;
        }
    }

    // join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *scan_port(void *arg) {
    int port = (intptr_t) arg;

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        printf("Failed to create socket for port %d\n", port);
        pthread_exit(NULL);
    }

    // set timeout for socket
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout)) < 0) {
        printf("Failed to set socket timeout for port %d\n", port);
        pthread_exit(NULL);
    }

    // set address information for socket
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(port);

    // connect to socket
    if (connect(sock, (struct sockaddr *) &address, sizeof(address)) == 0) {
        printf("Port %d is open\n", port);
    }

    // close socket
    close(sock);

    pthread_exit(NULL);
}