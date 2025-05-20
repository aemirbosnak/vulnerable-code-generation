//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            return NULL;
        }
        printf("Client %d sent: %s\n", client_socket, buffer);
    }
}

void accept_connections() {
    while (1) {
        int client_socket;
        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum clients reached\n");
            continue;
        }
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        client_sockets[num_clients] = client_socket;
        printf("Client %d connected\n", client_socket);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
        num_clients++;
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    while (1) {
        int client_socket;
        if ((client_socket = accept(server_socket, NULL, NULL)) == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        close(client_socket);
        printf("Connection refused\n");
    }
    return 0;
}