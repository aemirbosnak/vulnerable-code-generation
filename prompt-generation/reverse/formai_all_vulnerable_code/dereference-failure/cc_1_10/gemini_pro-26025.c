//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>

#define BUF_SIZE 1024
#define MAX_THREADS 10

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char *buf;
    int len;
} client_t;

typedef struct {
    int num_threads;
    client_t *clients;
} monitor_t;

monitor_t monitor;

void sigint_handler(int sig) {
    for (int i = 0; i < monitor.num_threads; i++) {
        close(monitor.clients[i].sockfd);
    }
    free(monitor.clients);
    exit(0);
}

void *client_thread(void *arg) {
    client_t *client = (client_t *)arg;
    struct timeval start, end;
    int num_bytes;

    while (1) {
        gettimeofday(&start, NULL);

        num_bytes = sendto(client->sockfd, client->buf, client->len, 0, (struct sockaddr *)&client->addr, sizeof(client->addr));
        if (num_bytes < 0) {
            perror("sendto");
            close(client->sockfd);
            pthread_exit(NULL);
        }

        num_bytes = recvfrom(client->sockfd, client->buf, client->len, 0, (struct sockaddr *)&client->addr, NULL);
        if (num_bytes < 0) {
            perror("recvfrom");
            close(client->sockfd);
            pthread_exit(NULL);
        }

        gettimeofday(&end, NULL);
        double rtt = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
        printf("RTT: %.2f ms\n", rtt);
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <ip address> <port> <number of threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse arguments
    char *ip_addr = argv[1];
    int port = atoi(argv[2]);
    int num_threads = atoi(argv[3]);
    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Number of threads must be less than or equal to %d\n", MAX_THREADS);
        return EXIT_FAILURE;
    }

    // Create clients
    monitor.num_threads = num_threads;
    monitor.clients = (client_t *)malloc(num_threads * sizeof(client_t));
    struct hostent *host = gethostbyname(ip_addr);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_threads; i++) {
        monitor.clients[i].sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (monitor.clients[i].sockfd < 0) {
            perror("socket");
            return EXIT_FAILURE;
        }

        monitor.clients[i].addr.sin_family = AF_INET;
        monitor.clients[i].addr.sin_port = htons(port);
        monitor.clients[i].addr.sin_addr = *((struct in_addr *)host->h_addr);

        monitor.clients[i].buf = (char *)malloc(BUF_SIZE);
        monitor.clients[i].len = BUF_SIZE;

        memset(monitor.clients[i].buf, 0, BUF_SIZE);
    }

    // Register signal handler
    signal(SIGINT, sigint_handler);

    // Create threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, client_thread, &monitor.clients[i]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}