//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_ip;
int target_port;
int num_threads;

void *scan_port(void *param) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return NULL;
    }

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(target_port);
    target.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == -1) {
        printf("Port %d is closed\n", target_port);
        close(sock);
        return NULL;
    }

    printf("Port %d is open\n", target_port);
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <target_ip> <target_port> <num_threads>\n", argv[0]);
        return 1;
    }

    target_ip = inet_addr(argv[1]);
    target_port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    if (target_ip == INADDR_NONE) {
        printf("Invalid target IP\n");
        return 1;
    }

    if (target_port <= 0 || target_port > 65535) {
        printf("Invalid target port\n");
        return 1;
    }

    if (num_threads <= 0 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        return 1;
    }

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}