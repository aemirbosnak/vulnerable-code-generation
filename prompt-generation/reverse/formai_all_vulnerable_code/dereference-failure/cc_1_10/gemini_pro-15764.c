//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_HOSTS 256
#define MAX_THREADS 64

typedef struct {
    char *hostname;
    int port;
    int status;
} host_t;

typedef struct {
    int num_hosts;
    host_t hosts[MAX_HOSTS];
    int num_threads;
    pthread_t threads[MAX_THREADS];
} network_t;

void *scan_host(void *arg) {
    host_t *host = (host_t *)arg;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(host->port);
    addr.sin_addr.s_addr = inet_addr(host->hostname);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        host->status = -1;
    } else {
        host->status = 1;
    }

    close(sockfd);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    network_t network;
    network.num_hosts = 0;
    network.num_threads = 0;

    for (int i = 1; i < argc; i++) {
        char *hostname = argv[i];
        int port = atoi(argv[i + 1]);

        host_t host;
        host.hostname = hostname;
        host.port = port;
        host.status = 0;

        network.hosts[network.num_hosts++] = host;
    }

    for (int i = 0; i < network.num_hosts; i++) {
        pthread_t thread;
        network.threads[network.num_threads++] = thread;

        if (pthread_create(&thread, NULL, scan_host, &network.hosts[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (int i = 0; i < network.num_threads; i++) {
        if (pthread_join(network.threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    for (int i = 0; i < network.num_hosts; i++) {
        printf("%s:%d %s\n", network.hosts[i].hostname, network.hosts[i].port, network.hosts[i].status == 1 ? "open" : "closed");
    }

    return 0;
}