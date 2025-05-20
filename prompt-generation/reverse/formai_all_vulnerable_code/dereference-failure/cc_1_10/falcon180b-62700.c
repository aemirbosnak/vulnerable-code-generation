//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_port;
int num_threads;
char *target_ip;
int *ports;
pthread_t threads[MAX_THREADS];

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
        char buffer[BUFFER_SIZE];
        sprintf(buffer, "Port %d is open.\n", port);
        write(sock, buffer, strlen(buffer));
        close(sock);
    } else {
        char buffer[BUFFER_SIZE];
        sprintf(buffer, "Port %d is closed.\n", port);
        write(sock, buffer, strlen(buffer));
        close(sock);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <target_ip> <start_port> <end_port>\n");
        exit(1);
    }

    target_ip = argv[1];
    target_port = atoi(argv[2]);
    num_threads = atoi(argv[3]) - target_port + 1;

    ports = (int *) malloc(num_threads * sizeof(int));
    for (int i = 0; i < num_threads; i++) {
        ports[i] = target_port + i;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &ports[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(ports);
    return 0;
}