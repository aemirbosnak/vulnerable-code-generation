//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define BUFF_SIZE 1024
#define MAX_THREADS 10

typedef struct {
    char *host;
    int port;
    int *status;
} target_t;

void *thread_func(void *arg) {
    target_t *target = (target_t *)arg;
    int sockfd;
    struct sockaddr_in serv_addr;
    char buff[BUFF_SIZE];
    int n;
    time_t start, end;
    double latency;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(target->port);
    serv_addr.sin_addr.s_addr = inet_addr(target->host);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    time(&start);
    n = send(sockfd, "GET / HTTP/1.1\r\nHost: ", 22, 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }
    n = send(sockfd, target->host, strlen(target->host), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }
    n = send(sockfd, "\r\nConnection: close\r\n\r\n", 24, 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    time(&end);
    latency = difftime(end, start);

    n = recv(sockfd, buff, BUFF_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    if (strncmp(buff, "HTTP/1.1 200 OK", 15) == 0) {
        *target->status = 1;
    } else {
        *target->status = 0;
    }

    close(sockfd);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port> [<host> <port> ...]\n", argv[0]);
        exit(1);
    }

    int num_targets = (argc - 1) / 2;
    target_t targets[num_targets];
    pthread_t threads[num_targets];
    int statuses[num_targets];
    int i;

    for (i = 0; i < num_targets; i++) {
        targets[i].host = argv[2 * i + 1];
        targets[i].port = atoi(argv[2 * i + 2]);
        targets[i].status = &statuses[i];
    }

    for (i = 0; i < num_targets; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, (void *)&targets[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (i = 0; i < num_targets; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    for (i = 0; i < num_targets; i++) {
        if (statuses[i] == 1) {
            printf("%s:%d is up\n", targets[i].host, targets[i].port);
        } else {
            printf("%s:%d is down\n", targets[i].host, targets[i].port);
        }
    }

    return 0;
}