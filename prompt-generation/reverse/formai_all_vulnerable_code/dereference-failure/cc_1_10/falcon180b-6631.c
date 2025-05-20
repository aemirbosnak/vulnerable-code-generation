//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_SERVICE 256
#define MAX_THREADS 10
#define MAX_DATA 2048
#define INTERVAL 5

int sock;
struct hostent *host;
struct sockaddr_in server;
char hostname[MAX_HOSTNAME];
char service[MAX_SERVICE];
int threads_running = 0;
int num_threads = 0;
char *data = NULL;
size_t data_size = 0;

void *send_data(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        send(sock, data, data_size, 0);
        usleep(100000);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int i, ret;
    pthread_t threads[MAX_THREADS];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s host service num_threads\n", argv[0]);
        return 1;
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);
    strncpy(service, argv[2], MAX_SERVICE);
    num_threads = atoi(argv[3]);

    ret = getaddrinfo(hostname, service, NULL, &host);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    sock = socket(host->h_addrtype, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    ret = connect(sock, host->h_addr, host->h_length);
    if (ret == -1) {
        perror("connect");
        return 1;
    }

    data = malloc(MAX_DATA);
    data_size = rand() % MAX_DATA + 1;
    memset(data, 'a', data_size);

    for (i = 0; i < num_threads; i++) {
        ret = pthread_create(&threads[i], NULL, send_data, NULL);
        if (ret!= 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(ret));
            return 1;
        }
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);
    return 0;
}