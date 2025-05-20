//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int scan_port(int sock, int port, char *ip);
void *scanner(void *arg);

int main(int argc, char *argv[]) {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];
    char *ip;
    int start_port, end_port;

    if (argc!= 5) {
        fprintf(stderr, "Usage: %s <IP> <Start Port> <End Port> <Num Threads>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);
    num_threads = atoi(argv[4]);

    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Error: Number of threads exceeds maximum limit of %d\n", MAX_THREADS);
        return 1;
    }

    for (i = 0; i < num_threads; i++) {
        int port = start_port + i * (end_port - start_port) / num_threads;
        pthread_create(&threads[i], NULL, scanner, (void *)port);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

int scan_port(int sock, int port, char *ip) {
    struct sockaddr_in server;
    int opt = 1;
    int result;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        return -1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        fprintf(stderr, "Error: Could not set socket option\n");
        close(sock);
        return -1;
    }

    result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d is open on %s\n", port, ip);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed on %s\n", port, ip);
    } else {
        fprintf(stderr, "Error: %s\n", strerror(errno));
    }

    close(sock);
    return 0;
}

void *scanner(void *arg) {
    int port = *(int *)arg;
    scan_port(socket(AF_INET, SOCK_STREAM, 0), port, "127.0.0.1");
    return NULL;
}