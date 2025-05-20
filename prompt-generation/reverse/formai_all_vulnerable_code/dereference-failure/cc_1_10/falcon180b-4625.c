//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535
#define BUFFER_SIZE 1024

// Function to check if a port is open
void *check_port(void *arg) {
    int sock = 0;
    struct sockaddr_in server;
    int port = *(int *) arg;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
    } else {
        printf("Port %d is closed\n", port);
        close(sock);
    }

    return NULL;
}

// Function to scan a range of ports
void scan_ports(int start_port, int end_port) {
    pthread_t threads[MAX_THREADS];
    int i, rc;
    for (i = start_port; i <= end_port; i++) {
        rc = pthread_create(&threads[i % MAX_THREADS], NULL, check_port, (void *) &i);
        if (rc) {
            printf("Error creating thread: %d\n", rc);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./port_scanner <start_port> <end_port>\n");
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(start_port, end_port);

    return 0;
}