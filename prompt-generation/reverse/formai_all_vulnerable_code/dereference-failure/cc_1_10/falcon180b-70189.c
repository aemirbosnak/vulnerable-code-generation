//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define MAX_THREADS 256
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int sock;
struct sockaddr_in target;
int port_start, port_end;
char *ip;
pthread_t threads[MAX_THREADS];
int num_threads;
int thread_count;

void *scan_port(void *arg) {
    int thread_id = *(int *) arg;
    int port = port_start + thread_id;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    if (connect(sock, (struct sockaddr *) &target, sizeof(target)) == 0) {
        fprintf(stdout, "Port %d is open on %s\n", port, ip);
        close(sock);
    } else {
        fprintf(stdout, "Port %d is closed on %s\n", port, ip);
        close(sock);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Start> <Port End>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ip = argv[1];
    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);

    if (port_start > port_end) {
        fprintf(stderr, "Invalid port range\n");
        exit(EXIT_FAILURE);
    }

    num_threads = port_end - port_start + 1;
    thread_count = 0;

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &i);
        thread_count++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}