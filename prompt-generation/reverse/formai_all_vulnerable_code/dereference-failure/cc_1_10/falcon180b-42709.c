//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_HOSTS 1000
#define BUFFER_SIZE 1024

int host_count = 0;
char *hosts[MAX_HOSTS];
int ports[MAX_HOSTS];

void *scan_thread(void *arg) {
    char *host = arg;
    int port = ports[host_count];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d on %s is closed\n", port, host);
        } else if (errno == ECONNRESET) {
            printf("Port %d on %s is open\n", port, host);
        } else {
            perror("connect");
        }

        close(sock);
        return NULL;
    }

    close(sock);
    printf("Port %d on %s is open\n", port, host);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    if (host_count >= MAX_HOSTS) {
        printf("Maximum number of hosts reached\n");
        exit(1);
    }

    hosts[host_count] = strdup(host);
    ports[host_count] = port;
    host_count++;

    pthread_t threads[MAX_THREADS];
    int i;

    for (i = 0; i < host_count; i++) {
        pthread_create(&threads[i], NULL, scan_thread, hosts[i]);
    }

    for (i = 0; i < host_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}