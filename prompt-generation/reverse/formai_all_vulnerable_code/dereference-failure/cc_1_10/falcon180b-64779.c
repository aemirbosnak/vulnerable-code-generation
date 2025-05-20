//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct thread_data {
    int sock;
    struct sockaddr_in server;
};

void *scan_port(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char buffer[BUFFER_SIZE];
    int ret;

    ret = connect(data->sock, (struct sockaddr *) &data->server, sizeof(data->server));
    if (ret == 0) {
        printf("Port %d is open\n", ntohs(data->server.sin_port));
        close(data->sock);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", ntohs(data->server.sin_port));
        close(data->sock);
    } else {
        printf("Error connecting to port %d: %s\n", ntohs(data->server.sin_port), strerror(errno));
        close(data->sock);
    }

    return NULL;
}

int main(int argc, char **argv) {
    int ret, i;
    pthread_t threads[MAX_THREADS];
    struct sockaddr_in server;
    int port_start, port_end;

    if (argc!= 4) {
        printf("Usage: %s <ip_address> <port_start> <port_end>\n", argv[0]);
        return 1;
    }

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);

    if (port_start > port_end) {
        printf("Invalid port range\n");
        return 1;
    }

    for (i = port_start; i <= port_end; i++) {
        server.sin_port = htons(i);
        ret = pthread_create(&threads[i - port_start], NULL, scan_port, (void *) &server);
        if (ret!= 0) {
            printf("Error creating thread for port %d: %s\n", i, strerror(ret));
            return 1;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}