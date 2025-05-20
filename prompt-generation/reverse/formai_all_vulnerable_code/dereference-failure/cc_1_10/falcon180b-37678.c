//Falcon-180B DATASET v1.0 Category: Firewall ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 5000
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;
char messages[MAX_CLIENTS][BUFFER_SIZE];

void *handle_client(void *sock) {
    int client_socket = *(int *) sock;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        strcpy(messages[client_socket], buffer);
        printf("Client %d sent message: %s\n", client_socket, messages[client_socket]);
    }

    close(client_socket);
    pthread_exit(NULL);
}

void accept_connections() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (num_clients < MAX_CLIENTS) {
        client_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_size);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        clients[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
    }
}

int main() {
    accept_connections();

    return 0;
}