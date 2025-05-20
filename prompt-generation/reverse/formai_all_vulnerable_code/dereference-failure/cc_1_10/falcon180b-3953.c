//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_THREADS 64

struct target {
    char *ip;
    int port;
};

void *scan_port(void *arg) {
    struct target *target = arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(target->port);
    if (inet_pton(AF_INET, target->ip, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address: %s\n", target->ip);
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        fprintf(stdout, "Port %d is open on %s\n", target->port, target->ip);
        close(sock);
    } else if (errno == ECONNREFUSED) {
        fprintf(stdout, "Port %d is closed on %s\n", target->port, target->ip);
    } else {
        fprintf(stderr, "Error connecting to %s:%d: %s\n", target->ip, target->port, strerror(errno));
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    struct target targets[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS && num_threads < MAX_THREADS; i++) {
        targets[i].ip = ip;
        targets[i].port = port + i;
        pthread_create(&threads[num_threads], NULL, scan_port, &targets[i]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}