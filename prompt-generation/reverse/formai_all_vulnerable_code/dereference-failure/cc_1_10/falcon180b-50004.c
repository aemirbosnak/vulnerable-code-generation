//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 50
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

int port_range[2] = {PORT_RANGE_MIN, PORT_RANGE_MAX};

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Thread %d: Error creating socket\n", thread_id);
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_range[thread_id % 2] + thread_id);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Thread %d: Port %d is open\n", thread_id, ntohs(server_addr.sin_port));
        close(sock);
    } else if (errno == ECONNREFUSED) {
        printf("Thread %d: Port %d is closed\n", thread_id, ntohs(server_addr.sin_port));
    } else {
        printf("Thread %d: Error connecting to port %d\n", thread_id, ntohs(server_addr.sin_port));
    }

    return NULL;
}

int main() {
    int num_threads = MAX_THREADS;
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        int thread_id = i + 1;
        pthread_create(&threads[i], NULL, thread_func, (void *)&thread_id);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}