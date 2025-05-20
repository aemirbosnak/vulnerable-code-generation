//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <math.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = thread_id * (MAX_PORTS / MAX_THREADS) + 1;
    int end_port = (thread_id == MAX_THREADS - 1)? MAX_PORTS : start_port + (MAX_PORTS / MAX_THREADS) - 1;

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;

        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
            close(sock);
            ports[num_ports++] = port;
        } else if (errno!= ECONNREFUSED) {
            perror("connect");
        }

        close(sock);
    }

    return NULL;
}

int main() {
    int num_threads = 4;
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Open ports:\n");
    for (int i = 0; i < num_ports; i++) {
        printf("%d\n", ports[i]);
    }

    return 0;
}