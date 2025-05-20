//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define NUM_THREADS 10

int port_list[] = { 21, 22, 23, 80, 443 }; // list of ports to scan
char target[] = "127.0.0.1"; // target IP address

void *scan_port(void *port) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() error");
        return NULL;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(target);
    addr.sin_port = htons(*((int *)port));

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", *((int *)port));
    }

    close(sockfd);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, j, k;

    for (i = 0; i < NUM_THREADS; i++) {
        int *ports = malloc(sizeof(port_list) / sizeof(int));
        k = 0;

        for (j = i; j < sizeof(port_list) / sizeof(int); j += NUM_THREADS) {
            ports[k++] = port_list[j];
        }

        pthread_create(&threads[i], NULL, scan_port, (void *)ports);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}