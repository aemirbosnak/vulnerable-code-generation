//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

#define THREAD_NUM 10
#define PORT_RANGE 1000

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} conn_info_t;

void interrupt(int sig) {
    exit(0);
}

void *scan_thread(void *arg) {
    conn_info_t *info = (conn_info_t *)arg;
    int port = ntohs(info->addr.sin_port);
    if (connect(info->sockfd, (struct sockaddr *)&info->addr, sizeof(info->addr)) == 0) {
        printf("Port %d is open.\n", port);
    }
    close(info->sockfd);
    free(info);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <target IP>\n", argv[0]);
        return 1;
    }

    signal(SIGINT, interrupt);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    pthread_t threads[THREAD_NUM];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < THREAD_NUM; i++) {
        conn_info_t *info = malloc(sizeof(conn_info_t));
        info->sockfd = sockfd;
        info->addr = addr;
        info->addr.sin_port = htons((rand() % PORT_RANGE) + 1);

        pthread_create(&threads[i], NULL, scan_thread, (void *)info);
    }

    for (int i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);
    return 0;
}