//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 4096

int scan_socket;
int *ports;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *scan_thread(void *arg) {
    int *port = arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    struct sockaddr_in server_addr;
    int server_len = sizeof(server_addr);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(*port);

    if (connect(scan_socket, (struct sockaddr *) &server_addr, server_len) == 0) {
        puts("Port open!");
    } else {
        puts("Port closed!");
    }

    close(scan_socket);
    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_PORTS];
    ports = (int *) malloc(MAX_PORTS * sizeof(int));

    for (i = 1; i <= MAX_PORTS; i++) {
        ports[i - 1] = i;
    }

    scan_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (scan_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    for (i = 0; i < MAX_PORTS; i++) {
        pthread_create(&threads[i], NULL, scan_thread, &ports[i]);
    }

    for (i = 0; i < MAX_PORTS; i++) {
        pthread_join(threads[i], NULL);
    }

    close(scan_socket);
    return 0;
}