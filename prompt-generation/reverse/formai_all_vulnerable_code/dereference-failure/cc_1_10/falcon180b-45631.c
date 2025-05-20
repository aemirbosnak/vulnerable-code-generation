//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int num_threads;
int *ports;
pthread_t threads[MAX_THREADS];

void *port_scanner(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Port %d is closed\n", port);
    }
    else {
        printf("Port %d is open\n", port);
        close(sock);
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    num_threads = 0;
    ports = malloc(MAX_PORTS * sizeof(int));

    for (int i = 1; i <= MAX_PORTS; i++) {
        ports[num_threads++] = i;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, port_scanner, &ports[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(ports);
    return 0;
}