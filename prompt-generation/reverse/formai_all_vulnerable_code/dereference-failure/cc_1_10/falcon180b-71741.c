//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_port;
char *target_ip;

int is_port_open(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

void *scan_thread(void *param) {
    int thread_id = *(int *)param;
    int port = target_port + thread_id * 10;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Thread %d: Failed to create socket\n", thread_id);
        pthread_exit(NULL);
    }

    if (is_port_open(sock, port)) {
        printf("Thread %d: Port %d is open\n", thread_id, port);
    } else {
        printf("Thread %d: Port %d is closed\n", thread_id, port);
    }

    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    target_ip = argv[1];
    target_port = atoi(argv[2]);

    int num_threads = 0;
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, scan_thread, (void *)&i)!= 0) {
            printf("Failed to create thread %d\n", i);
        } else {
            num_threads++;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}