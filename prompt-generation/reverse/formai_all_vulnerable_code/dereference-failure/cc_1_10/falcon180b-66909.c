//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100
#define THREAD_STACK_SIZE (1024 * 1024)

typedef struct {
    int socket;
    struct sockaddr_in server;
    char *ip;
    int port;
} thread_data_t;

void *scan_port(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int result;
    char buffer[1024];

    result = connect(data->socket, (struct sockaddr *) &data->server, sizeof(data->server));
    if (result == 0) {
        sprintf(buffer, "Port %d is open on %s\n", data->port, data->ip);
        write(1, buffer, strlen(buffer));
    } else {
        sprintf(buffer, "Port %d is closed on %s\n", data->port, data->ip);
        write(2, buffer, strlen(buffer));
    }

    close(data->socket);
    free(data->ip);
    free(data);

    return NULL;
}

int main(int argc, char **argv) {
    int result, i;
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];
    char *ip;
    int port;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    ip = strdup(argv[1]);
    port = atoi(argv[2]);

    for (i = 0; i < MAX_THREADS; i++) {
        data[i].ip = malloc(strlen(ip) + 1);
        strcpy(data[i].ip, ip);
        data[i].port = port + i;
        result = pthread_create(&threads[i], NULL, scan_port, (void *) &data[i]);
        if (result!= 0) {
            fprintf(stderr, "Error creating thread: %s\n", strerror(result));
            return 1;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        result = pthread_join(threads[i], NULL);
        if (result!= 0) {
            fprintf(stderr, "Error joining thread: %s\n", strerror(result));
            return 1;
        }
    }

    return 0;
}