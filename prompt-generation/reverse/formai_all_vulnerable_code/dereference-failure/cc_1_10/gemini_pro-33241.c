//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define MAX_THREADS 10
#define MAX_HOSTS 100
#define MAX_PORTS 100
#define MAX_RESULT_SIZE 10000

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} socket_t;

typedef struct {
    char *hostname;
    int port;
    int result_size;
    char *result;
} host_t;

typedef struct {
    host_t hosts[MAX_HOSTS];
    int num_hosts;
    int num_ports;
    int timeout;
} args_t;

pthread_t threads[MAX_THREADS];
args_t args;
char result[MAX_RESULT_SIZE];
int result_size;

void sigint_handler(int sig) {
    printf("Caught SIGINT, exiting...\n");
    exit(0);
}

void *thread_main(void *arg) {
    int i, j, k;
    int sockfd;
    struct sockaddr_in addr;
    char buf[1024];
    int n;
    int result_size;
    char *result;

    args_t *args = (args_t *)arg;

    for (i = 0; i < args->num_hosts; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(args->hosts[i].port);
        addr.sin_addr.s_addr = inet_addr(args->hosts[i].hostname);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        n = snprintf(buf, sizeof(buf), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", args->hosts[i].hostname);
        if (send(sockfd, buf, n, 0) == -1) {
            perror("send");
            close(sockfd);
            continue;
        }

        result_size = 0;
        result = malloc(MAX_RESULT_SIZE);
        if (result == NULL) {
            perror("malloc");
            close(sockfd);
            continue;
        }

        while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
            memcpy(result + result_size, buf, n);
            result_size += n;
        }

        if (n == -1) {
            perror("recv");
            close(sockfd);
            free(result);
            continue;
        }

        close(sockfd);

        pthread_mutex_lock(&args->hosts[i].result_size);
        args->hosts[i].result_size = result_size;
        pthread_mutex_unlock(&args->hosts[i].result_size);

        pthread_mutex_lock(&result_size);
        result_size += result_size;
        pthread_mutex_unlock(&result_size);

        pthread_mutex_lock(&result);
        memcpy(result + result_size, result, result_size);
        pthread_mutex_unlock(&result);

        free(result);
    }

    return NULL;
}

int start_threads(args_t *args) {
    int i, j, k;

    for (i = 0; i < args->num_hosts; i++) {
        if (pthread_create(&threads[i], NULL, thread_main, (args_t *)args) != 0) {
            perror("pthread_create");
            return -1;
        }
    }

    for (i = 0; i < args->num_hosts; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return -1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int i, j, k;
    char *hostname;
    int port;
    int timeout;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <timeout>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    timeout = atoi(argv[3]);

    args.num_hosts = 1;
    args.hosts[0].hostname = hostname;
    args.hosts[0].port = port;
    args.hosts[0].result_size = 0;
    args.hosts[0].result = NULL;
    args.num_ports = 1;
    args.timeout = timeout;

    signal(SIGINT, sigint_handler);

    start_threads(&args);

    for (i = 0; i < args.num_hosts; i++) {
        printf("Host: %s\n", args.hosts[i].hostname);
        printf("Port: %d\n", args.hosts[i].port);
        printf("Result size: %d\n", args.hosts[i].result_size);
        printf("Result:\n%s\n", args.hosts[i].result);
    }

    free(args.hosts[0].result);

    return 0;
}