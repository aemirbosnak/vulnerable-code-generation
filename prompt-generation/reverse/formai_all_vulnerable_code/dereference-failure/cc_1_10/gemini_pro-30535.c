//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_THREADS 100
#define MAX_HOSTS 1000

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} host_t;

typedef struct {
    int num_threads;
    int num_hosts;
    host_t hosts[MAX_HOSTS];
    pthread_t threads[MAX_THREADS];
} topology_mapper_t;

void *mapper_thread(void *arg) {
    topology_mapper_t *mapper = (topology_mapper_t *)arg;

    for (int i = 0; i < mapper->num_hosts; i++) {
        host_t *host = &mapper->hosts[i];

        int ret = connect(host->sockfd, (struct sockaddr *)&host->addr, sizeof(host->addr));
        if (ret == 0) {
            printf("Connected to %s:%d\n", inet_ntoa(host->addr.sin_addr), ntohs(host->addr.sin_port));
        } else {
            perror("connect");
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <num_threads> <num_hosts>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_threads = atoi(argv[1]);
    int num_hosts = atoi(argv[2]);

    if (num_threads <= 0 || num_threads > MAX_THREADS) {
        fprintf(stderr, "Invalid number of threads: %d\n", num_threads);
        return EXIT_FAILURE;
    }

    if (num_hosts <= 0 || num_hosts > MAX_HOSTS) {
        fprintf(stderr, "Invalid number of hosts: %d\n", num_hosts);
        return EXIT_FAILURE;
    }

    topology_mapper_t mapper = {
        .num_threads = num_threads,
        .num_hosts = num_hosts,
    };

    for (int i = 0; i < num_hosts; i++) {
        host_t *host = &mapper.hosts[i];

        host->sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (host->sockfd == -1) {
            perror("socket");
            return EXIT_FAILURE;
        }

        host->addr.sin_family = AF_INET;
        host->addr.sin_port = htons(80);
        host->addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    }

    for (int i = 0; i < num_threads; i++) {
        int ret = pthread_create(&mapper.threads[i], NULL, mapper_thread, &mapper);
        if (ret != 0) {
            fprintf(stderr, "pthread_create failed: %s\n", strerror(ret));
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(mapper.threads[i], NULL);
    }

    return EXIT_SUCCESS;
}