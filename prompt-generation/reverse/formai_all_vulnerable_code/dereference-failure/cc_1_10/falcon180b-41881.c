//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_THREADS 50
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;

void *scan_thread(void *arg) {
    int port = *(int *) arg;
    int sock;
    struct sockaddr_in sin;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) == 0) {
        close(sock);
        printf("Port %d is open\n", port);
    } else {
        close(sock);
    }

    pthread_exit(0);
}

int main(int argc, char **argv) {
    int i, j, max_threads, thread_id;
    pthread_t threads[MAX_THREADS];

    if (argc < 3) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        exit(1);
    }

    num_ports = atoi(argv[3]) - atoi(argv[2]) + 1;

    for (i = atoi(argv[2]); i <= atoi(argv[3]); i++) {
        ports[num_ports - 1] = i;
        num_ports--;
    }

    max_threads = num_ports;

    for (i = 0; i < max_threads; i++) {
        pthread_create(&threads[i], NULL, scan_thread, &ports[i]);
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}