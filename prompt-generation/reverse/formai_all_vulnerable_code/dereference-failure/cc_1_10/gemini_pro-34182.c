//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define NUM_THREADS 10
#define BUFFER_SIZE 1024

struct thread_data {
    int sockfd;
    int port;
};

void *scan_thread(void *arg) {
    struct thread_data *data = arg;
    int sockfd = data->sockfd;
    int port = data->port;

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (ret == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
    }

    close(sockfd);
    return NULL;
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int ret = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (ret == -1) {
        perror("bind");
        exit(1);
    }

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->sockfd = sockfd;
        data->port = 1000 + i;
        pthread_create(&threads[i], NULL, scan_thread, data);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);
    return 0;
}