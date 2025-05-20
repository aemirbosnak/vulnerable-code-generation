//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

void *handle_client(void *sock);

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    return 0;
}

void *handle_client(void *sock) {
    int client_socket = *((int *)sock);
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received message: %s\n", buffer);
    }

    close(client_socket);
    return NULL;
}