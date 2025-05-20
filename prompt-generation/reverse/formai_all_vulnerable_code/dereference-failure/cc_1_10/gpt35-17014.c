//FormAI DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PORTS 65535
#define NUM_THREADS 64

int open_ports[MAX_PORTS];
pthread_mutex_t mutex;

typedef struct {
    struct in_addr ip_addr;
    int start_port;
    int end_port;
} scan_args;

void *scan_ports(void *args) {
    scan_args *sargs = (scan_args *) args;
    struct sockaddr_in server;
    int sockfd, port, result;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr = sargs->ip_addr;

    for (port = sargs->start_port; port <= sargs->end_port; port++) {
        server.sin_port = htons(port);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        result = connect(sockfd, (struct sockaddr *) &server, sizeof(server));
        if (result == 0) {
            pthread_mutex_lock(&mutex);
            open_ports[port] = 1;
            pthread_mutex_unlock(&mutex);
        }

        close(sockfd);
    }

    free(args);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int i, num_threads, start_port, end_port;
    struct in_addr ip_addr;
    pthread_t threads[NUM_THREADS];

    if (argc != 4) {
        printf("Usage: %s <ip address> <start port> <end port>\n", argv[0]);
        return -1;
    }

    if (inet_aton(argv[1], &ip_addr) == 0) {
        printf("Invalid IP address\n");
        return -1;
    }

    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);
    if (start_port > end_port || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        return -1;
    }

    num_threads = (end_port - start_port + 1) / NUM_THREADS + 1;
    for (i = 0; i < num_threads; i++) {
        scan_args *sargs = malloc(sizeof(scan_args));
        sargs->ip_addr = ip_addr;
        sargs->start_port = start_port + i * NUM_THREADS;
        sargs->end_port = sargs->start_port + NUM_THREADS - 1;
        if (sargs->end_port > end_port) {
            sargs->end_port = end_port;
        }

        pthread_create(&threads[i], NULL, scan_ports, (void *) sargs);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Open ports:\n");
    for (i = start_port; i <= end_port; i++) {
        if (open_ports[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}