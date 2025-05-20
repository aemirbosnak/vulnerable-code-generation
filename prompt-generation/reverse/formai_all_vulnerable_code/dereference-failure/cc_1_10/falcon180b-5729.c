//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024
#define SERVER_PORT 8080

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket_desc);

int main(int argc, char **argv) {
    int opt = 1;
    int client_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (client_socket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", strlen("Server is full. Please try again later.\n"), 0);
            close(client_socket);
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
    }

    return 0;
}

void *handle_client(void *socket_desc) {
    int client_socket = *((int *) socket_desc);
    char buffer[MAX_REQUEST_SIZE];

    while (1) {
        memset(buffer, 0, MAX_REQUEST_SIZE);
        int bytes_received = recv(client_socket, buffer, MAX_REQUEST_SIZE, 0);

        if (bytes_received <= 0) {
            if (errno!= EAGAIN && errno!= EWOULDBLOCK) {
                perror("recv");
            }
            break;
        }

        printf("Client %d sent request: %s\n", client_socket, buffer);
    }

    close(client_socket);
    return NULL;
}