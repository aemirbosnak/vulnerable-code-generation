//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define MAX 10
#define PORT "80"
#define THREAD_COUNT 10

struct host_info {
    char *ip;
    char *domain;
    int port;
};

void *scan_thread(void *arg) {
    int sock = *(int *) arg;
    close(sock);
    return NULL;
}

int scan_port(char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    struct hostent *server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", ip);
        close(sock);
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr))!= 0) {
        if (errno == ECONNREFUSED) {
            printf("%s:%d - Closed\n", ip, port);
        } else if (errno == ECONNRESET) {
            printf("%s:%d - Reset\n", ip, port);
        } else {
            perror("connect");
        }
        close(sock);
        return -1;
    }

    close(sock);
    printf("%s:%d - Open\n", ip, port);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    struct hostent *server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", ip);
        return 1;
    }

    int i, max_threads = THREAD_COUNT;
    pthread_t threads[THREAD_COUNT];

    for (i = 1; i <= max_threads; i++) {
        pthread_create(&threads[i - 1], NULL, scan_thread, (void *) i);
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}