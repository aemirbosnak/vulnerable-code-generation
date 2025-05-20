//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    int port;
} PORT;

void *port_scanner(void *arg) {
    int port = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    PORT *p = (PORT *) malloc(sizeof(PORT));
    p->sock = socket(AF_INET, SOCK_STREAM, 0);
    p->port = port;

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (connect(p->sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        printf("Port %d is open\n", port);
        close(p->sock);
        free(p);
        return NULL;
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
        close(p->sock);
        free(p);
        return NULL;
    } else {
        printf("Error connecting to port %d: %s\n", port, strerror(errno));
        close(p->sock);
        free(p);
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    int start_port, end_port, num_threads;

    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port> <num_threads>\n", argv[0]);
        return 1;
    }

    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int i;

    for (i = 0; i < num_threads; i++) {
        int port = start_port + i * (end_port - start_port) / num_threads;
        pthread_create(&threads[i], NULL, port_scanner, (void *) &port);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}