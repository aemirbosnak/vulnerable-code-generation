//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define MAX_THREADS 100

int num_threads;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t threads[MAX_THREADS];

struct host_info {
    char hostname[256];
    char ipaddr[16];
};

void *scan(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    struct sockaddr_in addr;
    int sockfd, status;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket() error");
        pthread_exit(NULL);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host->ipaddr);
    addr.sin_port = htons(80);

    status = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (status < 0) {
        pthread_mutex_lock(&mutex);
        printf("%s (%s) is not responding\n", host->hostname, host->ipaddr);
        pthread_mutex_unlock(&mutex);
    } else {
        pthread_mutex_lock(&mutex);
        printf("%s (%s) is online\n", host->hostname, host->ipaddr);
        pthread_mutex_unlock(&mutex);
    }

    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[256];
    struct host_info *hosts[MAX_THREADS];
    int i = 0, rc;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen() error");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, ",");
        hosts[i] = (struct host_info *) malloc(sizeof(struct host_info));
        strcpy(hosts[i]->hostname, token);
        token = strtok(NULL, "\n");
        strcpy(hosts[i]->ipaddr, token);
        i++;
        if (i >= MAX_THREADS) {
            printf("Maximum number of hosts exceeded\n");
            break;
        }
    }

    num_threads = i;

    for (i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, scan, (void *) hosts[i]);
        if (rc) {
            printf("Error creating thread %d: %s\n", i, strerror(rc));
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    return 0;
}