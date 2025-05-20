//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in server;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(data->sock, buffer, BUFFER_SIZE, 0);

    if (bytes_received > 0) {
        printf("Thread ID %ld received %d bytes from %s:%d\n", pthread_self(), bytes_received, inet_ntoa(data->server.sin_addr), ntohs(data->server.sin_port));
    } else {
        printf("Thread ID %ld received %d bytes\n", pthread_self(), bytes_received);
    }

    close(data->sock);
    free(data);
    return NULL;
}

int main(int argc, char *argv[]) {
    int port;
    char *ip;
    int num_threads;
    pthread_t threads[MAX_THREADS];
    int i;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <IP> <port> <number of threads>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Error: Number of threads exceeds maximum limit\n");
        return 1;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) malloc(sizeof(thread_data_t)));
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}