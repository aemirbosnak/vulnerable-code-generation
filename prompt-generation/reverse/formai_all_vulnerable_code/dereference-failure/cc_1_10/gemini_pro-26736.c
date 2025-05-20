//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define BUFSIZE 4096
#define MAX_THREADS 10

struct thread_data {
    int sockfd;
    struct sockaddr_in addr;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    int sockfd = data->sockfd;
    struct sockaddr_in addr = data->addr;
    char buf[BUFSIZE];
    int n;

    while (1) {
        n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&addr, sizeof(addr));
        if (n <= 0) {
            break;
        }
        printf("Received %d bytes from %s:%d\n", n, inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        sendto(sockfd, buf, n, 0, (struct sockaddr *)&addr, sizeof(addr));
    }

    close(sockfd);
    free(data);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int nthreads = 0;

    while (1) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->sockfd = sockfd;
        data->addr = addr;

        if (pthread_create(&threads[nthreads], NULL, thread_func, data) != 0) {
            perror("pthread_create");
            break;
        }

        nthreads++;
        if (nthreads >= MAX_THREADS) {
            break;
        }
    }

    for (int i = 0; i < nthreads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);
    return 0;
}