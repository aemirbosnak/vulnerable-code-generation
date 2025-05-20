//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct host_info {
    char *ip;
    int port;
};

void *scan_port(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return NULL;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(host->port);
    inet_pton(AF_INET, host->ip, &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        printf("%s:%d is closed\n", host->ip, host->port);
        close(sock);
        return NULL;
    } else {
        printf("%s:%d is open\n", host->ip, host->port);
        close(sock);
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:./port_scanner <ip> <port_range>\n");
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + 100;

    pthread_t threads[MAX_THREADS];
    struct host_info hosts[MAX_THREADS];

    for (int i = start_port; i <= end_port; i++) {
        struct host_info *host = &hosts[i - start_port];
        host->ip = ip;
        host->port = i;
        pthread_create(&threads[i - start_port], NULL, scan_port, host);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}