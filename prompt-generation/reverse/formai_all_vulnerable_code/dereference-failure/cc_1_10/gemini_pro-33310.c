//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 9000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in addr;
    pthread_t thread;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Received from client: %s\n", buffer);
        if (strcmp(buffer, "quit") == 0) {
            printf("Client %d disconnected\n", client->socket);
            close(client->socket);
            pthread_exit(NULL);
        } else {
            send(client->socket, buffer, n, 0);
        }
    }

    if (n == 0) {
        printf("Client %d disconnected\n", client->socket);
    } else {
        printf("Error receiving from client: %s\n", strerror(errno));
    }

    close(client->socket);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating server socket: %s\n", strerror(errno));
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding server socket: %s\n", strerror(errno));
        return -1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on server socket: %s\n", strerror(errno));
        return -1;
    }

    while (1) {
        client_addr_len = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_socket == -1) {
            printf("Error accepting client connection: %s\n", strerror(errno));
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(new_socket);
            continue;
        }

        printf("Client %d connected\n", new_socket);

        clients[num_clients].socket = new_socket;
        clients[num_clients].addr = client_addr;
        pthread_create(&clients[num_clients].thread, NULL, handle_client, &clients[num_clients]);

        num_clients++;
    }

    close(server_socket);
    return 0;
}