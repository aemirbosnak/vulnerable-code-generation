//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 1024
#define MAX_HOSTS 4096
#define MAX_PORTS 65535

typedef struct {
    char *hostname;
    int port;
    int status;
} host_t;

typedef struct {
    int num_threads;
    int num_hosts;
    host_t *hosts;
    pthread_t *threads;
    sem_t semaphore;
} thread_pool_t;

void *thread_func(void *arg) {
    thread_pool_t *pool = (thread_pool_t *)arg;
    int i, sockfd;
    struct sockaddr_in addr;
    struct hostent *host;

    for (i = 0; i < pool->num_hosts; i++) {
        sem_wait(&pool->semaphore);

        if (pool->hosts[i].status != -1) {
            sem_post(&pool->semaphore);
            continue;
        }

        host = gethostbyname(pool->hosts[i].hostname);
        if (host == NULL) {
            pool->hosts[i].status = -1;
            sem_post(&pool->semaphore);
            continue;
        }

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            pool->hosts[i].status = -1;
            sem_post(&pool->semaphore);
            continue;
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(pool->hosts[i].port);
        memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            pool->hosts[i].status = -1;
            close(sockfd);
            sem_post(&pool->semaphore);
            continue;
        }

        pool->hosts[i].status = 1;
        close(sockfd);
        sem_post(&pool->semaphore);
    }

    return NULL;
}

int main(int argc, char **argv) {
    int i, j, num_threads, num_hosts;
    char *hostname;
    int port;
    thread_pool_t pool;

    if (argc < 3) {
        printf("Usage: %s <num_threads> <num_hosts>\n", argv[0]);
        return 1;
    }

    num_threads = atoi(argv[1]);
    num_hosts = atoi(argv[2]);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Number of threads must be between 1 and %d\n", MAX_THREADS);
        return 1;
    }

    if (num_hosts < 1 || num_hosts > MAX_HOSTS) {
        printf("Number of hosts must be between 1 and %d\n", MAX_HOSTS);
        return 1;
    }

    pool.num_threads = num_threads;
    pool.num_hosts = num_hosts;
    pool.hosts = malloc(sizeof(host_t) * num_hosts);
    pool.threads = malloc(sizeof(pthread_t) * num_threads);
    sem_init(&pool.semaphore, 0, num_threads);

    for (i = 0; i < num_hosts; i++) {
        hostname = argv[3 + i];
        port = atoi(argv[3 + num_hosts + i]);

        if (port < 0 || port > MAX_PORTS) {
            printf("Port %d is invalid\n", port);
            return 1;
        }

        pool.hosts[i].hostname = hostname;
        pool.hosts[i].port = port;
        pool.hosts[i].status = -1;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&pool.threads[i], NULL, thread_func, &pool);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(pool.threads[i], NULL);
    }

    for (i = 0; i < num_hosts; i++) {
        printf("%s:%d ", pool.hosts[i].hostname, pool.hosts[i].port);
        if (pool.hosts[i].status == 1) {
            printf("is open\n");
        } else {
            printf("is closed\n");
        }
    }

    sem_destroy(&pool.semaphore);
    free(pool.hosts);
    free(pool.threads);

    return 0;
}