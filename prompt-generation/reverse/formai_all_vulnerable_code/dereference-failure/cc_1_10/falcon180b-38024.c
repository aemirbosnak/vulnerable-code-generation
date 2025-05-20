//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int server_socket;
int client_socket;

char *clients[10];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d says: %s\n", client_socket, buffer);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i]!= NULL && clients[i]!= client_socket) {
                send(clients[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(client_socket);
    free(clients[num_clients]);
    clients[num_clients] = NULL;
    num_clients--;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (num_clients >= 10) {
            printf("Server is full.\n");
            close(client_socket);
            continue;
        }

        clients[num_clients] = malloc(sizeof(int));
        *(int *) clients[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
    }

    return 0;
}