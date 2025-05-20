//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_ip;
int target_port;
int thread_count;

void *scan_port(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Port %d is closed\n", target_port);
    } else {
        printf("Port %d is open\n", target_port);
    }

    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <target_ip> <target_port> <thread_count>\n");
        exit(1);
    }

    target_ip = inet_addr(argv[1]);
    target_port = atoi(argv[2]);
    thread_count = atoi(argv[3]);

    if (thread_count > MAX_THREADS) {
        printf("Maximum thread count is %d\n", MAX_THREADS);
        exit(1);
    }

    pthread_t threads[thread_count];
    int rc;

    for (int i = 0; i < thread_count; i++) {
        rc = pthread_create(&threads[i], NULL, scan_port, NULL);

        if (rc) {
            printf("Error creating thread: %s\n", strerror(rc));
            exit(1);
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}