//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 256
#define BUFFER_SIZE 1024

struct sockaddr_in target;
int port_start, port_end, timeout;

void *scan_port(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    target.sin_family = AF_INET;
    target.sin_port = htons((unsigned short) (*(int *) arg));
    target.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &target, sizeof(target)) == 0) {
        close(sock);
        printf("Port %d is open.\n", *(int *) arg);
    } else {
        close(sock);
        printf("Port %d is closed.\n", *(int *) arg);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port> <timeout>\n", argv[0]);
        exit(1);
    }

    port_start = atoi(argv[1]);
    port_end = atoi(argv[2]);
    timeout = atoi(argv[3]);

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int i = port_start; i <= port_end; i++) {
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }

        int *port = malloc(sizeof(int));
        *port = i;
        pthread_create(&threads[thread_count], NULL, scan_port, port);
        thread_count++;

        usleep(timeout * 1000);
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}