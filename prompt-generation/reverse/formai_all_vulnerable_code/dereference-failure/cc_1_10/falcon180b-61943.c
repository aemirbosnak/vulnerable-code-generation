//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define THREAD_COUNT 10

int scan_port(int port);
void *thread_func(void *arg);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int ipv4_addr = inet_addr(ip);

    if (ipv4_addr == INADDR_NONE) {
        printf("Invalid IP Address\n");
        return 1;
    }

    int i;
    pthread_t threads[THREAD_COUNT];

    for (i = 1; i <= MAX_PORTS; i++) {
        pthread_create(&threads[i % THREAD_COUNT], NULL, thread_func, (void *)i);
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

int scan_port(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("socket() failed: %s\n", strerror(errno));
        return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("connect() failed: %s\n", strerror(errno));
        }

        close(sockfd);
        return -1;
    }

    close(sockfd);
    printf("Port %d is open\n", port);

    return 0;
}

void *thread_func(void *arg) {
    int port = (int)arg;

    scan_port(port);

    return NULL;
}