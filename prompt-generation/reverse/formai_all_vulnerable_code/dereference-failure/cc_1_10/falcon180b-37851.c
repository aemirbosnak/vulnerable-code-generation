//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_LINE 1024
#define BACKLOG 10
#define TRUE 1
#define FALSE 0

typedef struct {
    int sock;
    struct sockaddr_in addr;
} client_t;

int listen_socket(int port) {
    int listen_sock;
    struct sockaddr_in listen_addr;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    return listen_sock;
}

void *handle_client(void *arg) {
    client_t *client = (client_t *) arg;
    char buffer[MAX_LINE];
    int bytes_received;

    while ((bytes_received = recv(client->sock, buffer, MAX_LINE, 0)) > 0) {
        send(client->sock, buffer, bytes_received, 0);
    }

    close(client->sock);
    free(client);
}

int main(int argc, char *argv[]) {
    int listen_sock, client_sock, port;

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    listen_sock = listen_socket(port);

    while (TRUE) {
        socklen_t addr_size;
        struct sockaddr_in client_addr;

        addr_size = sizeof(client_addr);
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_size);

        if (client_sock == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        client_t *client = (client_t *) malloc(sizeof(client_t));
        client->sock = client_sock;
        client->addr = client_addr;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) client);
    }

    return 0;
}