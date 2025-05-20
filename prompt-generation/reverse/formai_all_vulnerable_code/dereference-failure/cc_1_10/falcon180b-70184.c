//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

struct host_info {
    char *ip_address;
    int port;
    int status;
};

void *scan_port(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(host->port);
    inet_pton(AF_INET, host->ip_address, &server_addr.sin_addr);

    int connect_result = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (connect_result == 0) {
        host->status = 1; // open
    } else if (errno == ECONNREFUSED) {
        host->status = 2; // closed
    } else {
        host->status = 3; // error
    }

    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    int num_threads = 1;
    pthread_t threads[MAX_THREADS];

    struct host_info hosts[MAX_THREADS];
    for (int i = 0; i < num_threads; i++) {
        hosts[i].ip_address = strdup(ip_address);
        hosts[i].port = port;
        hosts[i].status = 0;
        pthread_create(&threads[i], NULL, scan_port, &hosts[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}