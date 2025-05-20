//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define THREADS 10
#define TIMEOUT 2

void *scan_port(void *arg);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./portScanner <ipaddr> <port-range>\n");
        exit(1);
    }

    int port_start = atoi(strtok(argv[2], "-"));
    int port_end = atoi(strtok(NULL, "-"));

    if (port_start <= 0 || port_end <= 0 || port_end < port_start) {
        printf("Invalid port range.\n");
        exit(1);
    }

    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    pthread_t threads[THREADS];

    int ports_per_thread = (port_end - port_start) / THREADS;
    int remaining_ports = (port_end - port_start) % THREADS;

    for (int i = 0; i < THREADS; i++) {
        int start_port = port_start + (i * ports_per_thread);
        int end_port = start_port + ports_per_thread - 1;
        if (i == THREADS - 1) {
            end_port += remaining_ports;
        }

        int *args = malloc(2 * sizeof(*args));
        args[0] = start_port;
        args[1] = end_port;

        if (pthread_create(&threads[i], NULL, scan_port, args) != 0) {
            perror("Failed to create thread.\n");
            exit(1);
        }
    }

    for (int i = 0; i < THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread.\n");
            exit(1);
        }
    }

    printf("Port scanning complete.\n");

    return 0;
}

void *scan_port(void *arg) {
    int *args = (int *)arg;
    int start = args[0];
    int end = args[1];

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket.\n");
        exit(1);
    }

    for (int port = start; port <= end; port++) {
        addr.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open.\n", port);
        }
    }

    close(sock);
    free(args);
    pthread_exit(NULL);
}