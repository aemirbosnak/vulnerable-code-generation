//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

int port;
char *ip;
int num_threads;
int *thread_ids;
pthread_t *threads;

void *scan_port(void *arg) {
    int sock;
    int result;
    int thread_id = *((int *) arg);
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Thread %d: Error creating socket\n", thread_id);
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    result = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (result == -1) {
        printf("Thread %d: Port %d is closed\n", thread_id, port);
    } else {
        printf("Thread %d: Port %d is open\n", thread_id, port);
        close(sock);
    }

    return NULL;
}

int main() {
    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Maximum number of threads is %d\n", MAX_THREADS);
        return 1;
    }

    thread_ids = malloc(num_threads * sizeof(int));
    threads = malloc(num_threads * sizeof(pthread_t));

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, scan_port, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(thread_ids);
    free(threads);

    return 0;
}