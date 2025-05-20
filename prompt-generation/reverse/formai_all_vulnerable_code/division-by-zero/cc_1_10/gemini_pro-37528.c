//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

typedef struct {
    int start_port;
    int end_port;
    char *ip_address;
} thread_args;

void *scan_ports(void *args) {
    thread_args *targs = (thread_args *)args;
    int sockfd, port;
    struct sockaddr_in addr;

    for (port = targs->start_port; port <= targs->end_port; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket() failed");
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(targs->ip_address);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        }

        close(sockfd);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <num_threads>\n", argv[0]);
        exit(1);
    }

    int num_threads = atoi(argv[2]);
    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Number of threads must be less than or equal to %d\n", MAX_THREADS);
        exit(1);
    }

    int ports_per_thread = MAX_PORTS / num_threads;
    pthread_t threads[num_threads];
    thread_args targs[num_threads];

    for (int i = 0; i < num_threads; i++) {
        targs[i].start_port = i * ports_per_thread + 1;
        targs[i].end_port = (i + 1) * ports_per_thread;
        targs[i].ip_address = argv[1];

        if (pthread_create(&threads[i], NULL, scan_ports, &targs[i]) != 0) {
            perror("pthread_create() failed");
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join() failed");
            exit(1);
        }
    }

    return 0;
}