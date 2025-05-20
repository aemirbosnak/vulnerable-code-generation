//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORT 65535
#define MAX_THREADS 10

typedef struct {
    int port;
    int sockfd;
    struct sockaddr_in addr;
    int open;
} port_scan_result;

void *port_scan_thread(void *arg) {
    port_scan_result *result = (port_scan_result *)arg;

    result->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (result->sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    result->addr.sin_family = AF_INET;
    result->addr.sin_port = htons(result->port);
    result->addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(result->sockfd, (struct sockaddr *)&result->addr, sizeof(result->addr)) == 0) {
        result->open = 1;
    } else {
        result->open = 0;
    }

    close(result->sockfd);

    return NULL;
}

int main(int argc, char **argv) {
    int i, num_ports, num_threads;
    port_scan_result results[MAX_PORT];
    pthread_t threads[MAX_THREADS];

    if (argc < 3) {
        fprintf(stderr, "usage: %s <start port> <end port> <num threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    num_ports = atoi(argv[2]) - atoi(argv[1]) + 1;
    num_threads = atoi(argv[3]);

    if (num_ports > MAX_PORT) {
        fprintf(stderr, "error: too many ports specified\n");
        exit(EXIT_FAILURE);
    }

    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "error: too many threads specified\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < num_ports; i++) {
        results[i].port = atoi(argv[1]) + i;
        results[i].open = 0;
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, port_scan_thread, &results[i * (num_ports / num_threads)]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < num_ports; i++) {
        if (results[i].open) {
            printf("port %d is open\n", results[i].port);
        }
    }

    return 0;
}