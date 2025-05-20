//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

// Function for thread to execute
void *scan_ports(void *arg) {
    int sock = *(int *) arg;
    struct sockaddr_in server;
    char buffer[1024];
    int port = *(int *) (arg + sizeof(int));

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        printf("Port %d is open.\n", port);
        close(sock);
    } else {
        printf("Port %d is closed.\n", port);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int threads[MAX_THREADS];
    pthread_t thread_id[MAX_THREADS];
    int i, j;

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        exit(1);
    }

    int ip[4] = {0};
    if (inet_pton(AF_INET, argv[1], &ip) <= 0) {
        printf("Invalid IP address.\n");
        exit(1);
    }

    int port_range_min = atoi(argv[2]);
    int port_range_max = atoi(argv[3]);

    if (port_range_min > port_range_max || port_range_min < PORT_RANGE_MIN || port_range_max > PORT_RANGE_MAX) {
        printf("Invalid port range.\n");
        exit(1);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&thread_id[i], NULL, scan_ports, (void *) &threads[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}