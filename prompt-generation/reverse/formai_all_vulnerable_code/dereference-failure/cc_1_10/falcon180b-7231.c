//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
struct sockaddr_in server_addr;
int client_sockets[MAX_CLIENTS];
int num_clients;

void *handle_client(void *client_socket) {
    int client = *(int *)client_socket;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %d sent: %s\n", client, buffer);

        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i]!= client) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(client);

    pthread_exit(0);
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is listening on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", 45, 0);
            close(client_socket);
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    return 0;
}