//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE 8192
#define BACKLOG 10

typedef struct {
    int sock;
    char ip[16];
    int port;
} client_t;

void *thread_proxy(void *arg) {
    client_t *client = arg;
    char buffer[MAX_LINE];

    while (TRUE) {
        memset(buffer, 0, MAX_LINE);
        int n = recv(client->sock, buffer, MAX_LINE, 0);
        if (n <= 0) {
            break;
        }
        send(client->sock, buffer, n, 0);
    }

    close(client->sock);
    free(client);
    return NULL;
}

int main() {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(8080);
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        client_t *client = malloc(sizeof(client_t));
        int sock = accept(listen_sock, NULL, NULL);
        if (sock == -1) {
            perror("accept");
            exit(1);
        }

        inet_ntop(AF_INET, &(((struct sockaddr_in *)&listen_addr)->sin_addr), client->ip, 16);
        client->port = ntohs(((struct sockaddr_in *)&listen_addr)->sin_port);
        client->sock = sock;

        pthread_t thread_id;
        pthread_create(&thread_proxy, NULL, (void *)client, NULL);
        pthread_detach(thread_id);
    }

    close(listen_sock);
    return 0;
}