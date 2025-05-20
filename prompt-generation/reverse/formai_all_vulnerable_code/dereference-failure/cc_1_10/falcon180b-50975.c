//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define THREAD_COUNT 10

struct thread_data {
    int thread_id;
    int start_port;
    int end_port;
};

void *port_scanner(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;
    int start_port = data->start_port;
    int end_port = data->end_port;

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Thread %d: Error creating socket: %s\n", thread_id, strerror(errno));
        } else {
            struct sockaddr_in server_addr;
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(port);
            server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

            int result = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
            if (result == 0) {
                printf("Thread %d: Port %d is open\n", thread_id, port);
            } else if (errno == ECONNREFUSED) {
                printf("Thread %d: Port %d is closed\n", thread_id, port);
            } else {
                printf("Thread %d: Error connecting to port %d: %s\n", thread_id, port, strerror(errno));
            }

            close(sock);
        }
    }

    return NULL;
}

int main() {
    int num_threads = THREAD_COUNT;
    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < num_threads; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->thread_id = i + 1;
        data->start_port = i * (MAX_PORTS / num_threads) + 1;
        data->end_port = (i == num_threads - 1)? MAX_PORTS : (i + 1) * (MAX_PORTS / num_threads);

        int rc = pthread_create(&threads[i], NULL, port_scanner, data);
        if (rc) {
            printf("Error creating thread: %s\n", strerror(rc));
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}