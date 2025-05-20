//Falcon-180B DATASET v1.0 Category: Chat server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket = 0;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *thread_func(void *ptr) {
    int client_socket = *(int *)ptr;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(client_socket);
            pthread_exit(0);
        }

        send(client_socket, buffer, bytes_received, 0);
    }
}

void accept_connections() {
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            if (errno == EINTR)
                continue;
            else if (errno == EMFILE) {
                printf("Too many connections\n");
                exit(1);
            } else {
                printf("Error accepting connection\n");
                exit(1);
            }
        }

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Server is full\n");
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_func, (void *)&client_socket);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(12345);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Server started on port 12345\n");

    accept_connections();

    return 0;
}