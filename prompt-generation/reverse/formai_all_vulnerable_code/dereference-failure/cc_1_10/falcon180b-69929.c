//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_REQUEST_SIZE 8192
#define MAX_RESPONSE_SIZE 16384
#define THREAD_COUNT 10

typedef struct {
    int fd;
    char request[MAX_REQUEST_SIZE];
    char response[MAX_RESPONSE_SIZE];
    size_t response_len;
    pthread_t thread_id;
} ClientData;

void *handle_request(void *arg) {
    ClientData *client_data = (ClientData *) arg;
    int response_len = 0;

    response_len = send(client_data->fd, client_data->response, client_data->response_len, 0);
    if (response_len < 0) {
        perror("send");
    }

    close(client_data->fd);
    free(client_data);

    return NULL;
}

void accept_connections(int server_socket) {
    while (1) {
        ClientData *client_data = (ClientData *) malloc(sizeof(ClientData));
        memset(client_data, 0, sizeof(ClientData));

        client_data->fd = accept(server_socket, NULL, NULL);
        if (client_data->fd < 0) {
            perror("accept");
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_request, client_data);
    }
}

void *proxy_thread(void *arg) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return NULL;
    }

    accept_connections(server_socket);

    close(server_socket);

    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, proxy_thread, NULL);

    pthread_join(thread_id, NULL);

    return 0;
}