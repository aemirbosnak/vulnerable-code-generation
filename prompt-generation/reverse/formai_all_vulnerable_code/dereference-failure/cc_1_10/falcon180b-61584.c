//Falcon-180B DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024
#define MAX_REQUEST_SIZE 4096
#define THREAD_POOL_SIZE 5

int listen_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
int thread_pool[THREAD_POOL_SIZE];
int next_thread = 0;

struct client_data {
    int socket;
    char request[MAX_REQUEST_SIZE];
};

void *handle_request(void *arg) {
    struct client_data *client_data = (struct client_data*) arg;
    char response[BUFFER_SIZE];
    sprintf(response, "HTTP/1.0 200 OK\r\nContent-Length: 18\r\n\r\nHello, world!");

    send(client_data->socket, response, strlen(response), 0);
    close(client_data->socket);
    free(client_data);
}

void accept_connections() {
    while(1) {
        int new_socket = accept(listen_socket, NULL, NULL);
        if(new_socket == -1) {
            if(errno == ECONNABORTED) {
                continue;
            }
            perror("accept");
            exit(1);
        }

        if(num_clients >= MAX_CLIENTS) {
            close(new_socket);
            continue;
        }

        client_sockets[num_clients++] = new_socket;
        if(num_clients == THREAD_POOL_SIZE) {
            next_thread = 0;
        }
    }
}

int main() {
    int opt = 1;
    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    for(int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_create(&thread_pool[i], NULL, handle_request, NULL);
    }

    accept_connections();

    for(int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_join(thread_pool[i], NULL);
    }

    return 0;
}