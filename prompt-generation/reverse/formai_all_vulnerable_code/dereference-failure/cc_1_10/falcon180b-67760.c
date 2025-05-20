//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int port;
char hostname[1024];
int num_threads;

void *thread_func(void *arg) {
    int thread_num = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address\n");
        exit(1);
    }
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        close(sock);
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed on %s\n", port, hostname);
        } else {
            perror("connect");
        }
        exit(0);
    } else {
        close(sock);
        printf("Port %d is open on %s\n", port, hostname);
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);
    printf("Scanning %s:%d\n", hostname, port);
    pthread_t threads[MAX_THREADS];
    int i;
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}