//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define NUM_THREADS 10

struct thread_args {
    int sockfd;
    struct sockaddr_in addr;
};

void *thread_main(void *args) {
    struct thread_args *thread_args = (struct thread_args *)args;
    int sockfd = thread_args->sockfd;
    struct sockaddr_in addr = thread_args->addr;

    char buf[1024];
    int n;

    while ((n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, (socklen_t *)sizeof(addr))) > 0) {
        printf("Received %d bytes from %s\n", n, inet_ntoa(addr.sin_addr));
        sendto(sockfd, buf, n, 0, (struct sockaddr *)&addr, (socklen_t *)sizeof(addr));
    }

    close(sockfd);
    free(thread_args);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        struct thread_args *thread_args = (struct thread_args *)malloc(sizeof(struct thread_args));
        thread_args->sockfd = sockfd;
        thread_args->addr = addr;

        if (pthread_create(&threads[i], NULL, thread_main, (void *)thread_args) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }

    close(sockfd);
    return 0;
}