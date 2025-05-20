//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_ports(void *arg) {
    int thread_id = (int) arg;
    int start_port = thread_id * (MAX_PORTS / MAX_THREADS) + 1;
    int end_port = (thread_id == MAX_THREADS - 1)? MAX_PORTS : (thread_id + 1) * (MAX_PORTS / MAX_THREADS);

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

        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else {
                perror("connect");
            }
            close(sock);
        } else {
            printf("Port %d is open\n", port);
            close(sock);
        }
    }

    return NULL;
}

int main() {
    int num_threads = (MAX_PORTS + MAX_THREADS - 1) / MAX_THREADS;

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        int start_port = i * (MAX_PORTS / num_threads) + 1;
        int end_port = (i == num_threads - 1)? MAX_PORTS : (i + 1) * (MAX_PORTS / num_threads);
        num_ports += end_port - start_port;

        pthread_create(&threads[i], NULL, scan_ports, (void *) i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}