//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024
#define THREAD_COUNT 50

int scan_port(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
        return 1;
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
        close(sock);
        return 0;
    } else {
        printf("Connection failed: %s\n", strerror(errno));
        close(sock);
        return -1;
    }
}

void *thread_func(void *arg) {
    int port = *(int *)arg;
    scan_port(port);
    return NULL;
}

int main() {
    srand(time(NULL));

    int *ports = malloc(MAX_PORTS * sizeof(int));
    for (int i = 1; i <= MAX_PORTS; i++) {
        ports[i - 1] = i;
    }

    for (int i = 0; i < MAX_PORTS; i++) {
        int j = rand() % MAX_PORTS;
        int temp = ports[i];
        ports[i] = ports[j];
        ports[j] = temp;
    }

    pthread_t threads[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; i++) {
        int port = ports[i];
        pthread_create(&threads[i], NULL, thread_func, &port);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    free(ports);
    return 0;
}