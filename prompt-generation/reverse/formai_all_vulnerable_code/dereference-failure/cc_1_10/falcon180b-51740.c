//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_CLIENTS 1000
#define BUF_SIZE 1024

struct client {
    int sock;
    struct sockaddr_in addr;
};

void *monitor_thread(void *arg) {
    int sock = *(int *) arg;
    char buf[BUF_SIZE];
    int len;

    while (1) {
        len = recv(sock, buf, BUF_SIZE, 0);
        if (len <= 0) {
            break;
        }
        printf("Received %d bytes from client: %s\n", len, buf);
    }

    close(sock);
    return NULL;
}

int main() {
    int listen_sock, new_sock, client_sock;
    int opt = 1;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port 8080\n");

    while (1) {
        addrlen = sizeof(client_addr);
        new_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addrlen);

        if (new_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (num_threads >= MAX_THREADS) {
            printf("Maximum number of threads reached\n");
            close(new_sock);
            continue;
        }

        struct client *client = malloc(sizeof(struct client));
        client->sock = new_sock;
        memcpy(&client->addr, &client_addr, sizeof(client_addr));

        pthread_create(&threads[num_threads], NULL, monitor_thread, (void *)&client->sock);
        num_threads++;
    }

    return 0;
}