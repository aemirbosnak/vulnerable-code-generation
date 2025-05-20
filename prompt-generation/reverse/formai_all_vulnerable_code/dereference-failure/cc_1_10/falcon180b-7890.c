//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

struct thread_data {
    int thread_id;
    int port_range_min;
    int port_range_max;
};

void *port_scanner(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;
    int port_range_min = data->port_range_min;
    int port_range_max = data->port_range_max;

    for (int port = port_range_min; port <= port_range_max; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

        int result = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

        if (result == 0) {
            close(sock);
            printf("[Thread %d] Port %d is open\n", thread_id, port);
        } else {
            close(sock);
        }
    }

    return NULL;
}

int main() {
    int num_threads = 4;
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->thread_id = i + 1;
        data->port_range_min = PORT_RANGE_MIN + (PORT_RANGE_MAX - PORT_RANGE_MIN) / num_threads * i;
        data->port_range_max = data->port_range_min + (PORT_RANGE_MAX - PORT_RANGE_MIN) / num_threads;

        int result = pthread_create(&threads[i], NULL, port_scanner, (void *) data);

        if (result!= 0) {
            printf("Error creating thread %d\n", i + 1);
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}