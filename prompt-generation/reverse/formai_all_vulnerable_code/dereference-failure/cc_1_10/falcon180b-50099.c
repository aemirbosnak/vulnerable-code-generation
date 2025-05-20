//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>
#include <signal.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in server;
} thread_data_t;

void *thread_connect(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (connect(data->sock, (struct sockaddr *) &data->server, sizeof(data->server)) == -1) {
        perror("connect");
        close(data->sock);
        return NULL;
    }

    while ((bytes_received = recv(data->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Thread %d received %d bytes: %s\n", pthread_self(), bytes_received, buffer);
    }

    close(data->sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    int port, max_threads, i;
    char host[256];
    struct hostent *host_info;
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    strcpy(host, argv[1]);
    port = atoi(argv[2]);

    max_threads = sysconf(_SC_NPROCESSORS_ONLN);

    if (max_threads > MAX_THREADS) {
        max_threads = MAX_THREADS;
    }

    for (i = 0; i < max_threads; i++) {
        data[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (data[i].sock == -1) {
            perror("socket");
            return 1;
        }

        memset(&data[i].server, 0, sizeof(data[i].server));
        data[i].server.sin_family = AF_INET;
        data[i].server.sin_port = htons(port);
        data[i].server.sin_addr.s_addr = INADDR_ANY;

        if (pthread_create(&threads[i], NULL, thread_connect, &data[i])!= 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}