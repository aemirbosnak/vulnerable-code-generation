//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535
#define THREAD_COUNT 10

void *scan_ports(void *arg) {
    int port = *(int *) arg;
    char ip[16];
    struct sockaddr_in server;
    int sockfd;

    memset(&server, 0, sizeof(server));

    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return NULL;
    }

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Connection failed on port %d\n", port);
        close(sockfd);
        return NULL;
    }

    close(sockfd);
    printf("Port %d is open\n", port);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int ports[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        ports[i] = PORT_RANGE_MIN + i;
        pthread_create(&threads[i], NULL, scan_ports, &ports[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}