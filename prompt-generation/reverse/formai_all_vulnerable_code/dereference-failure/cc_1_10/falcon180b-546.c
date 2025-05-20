//Falcon-180B DATASET v1.0 Category: Chat server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

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
            break;
        }

        printf("Client %d said: %s\n", client_socket, buffer);

        for (int i = 0; i < num_clients; i++) {
            if (i!= client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(client_socket);
    return NULL;
}

void handle_signals(int signum) {
    for (int i = 0; i < num_clients; i++) {
        close(client_sockets[i]);
    }

    close(server_socket);
    exit(0);
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    signal(SIGINT, handle_signals);

    struct sockaddr_in server_addr, client_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_socket, MAX_CLIENTS);

    while (1) {
        printf("Waiting for clients...\n");

        struct sockaddr_in client_addr_in;
        socklen_t addr_size = sizeof(struct sockaddr_in);

        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr_in, &addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Client %d connected.\n", client_socket);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);

        client_sockets[num_clients++] = client_socket;
    }

    return 0;
}