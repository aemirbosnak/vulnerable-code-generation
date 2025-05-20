//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if(bytes_received <= 0) {
            close(client_socket);
            pthread_exit(NULL);
        }

        printf("Client %d sent: %s\n", client_socket, buffer);

        for(int i = 0; i < num_clients; i++) {
            if(client_sockets[i]!= client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }
}

void accept_connections() {
    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if(client_socket == -1) {
            if(errno == ECONNABORTED) {
                printf("Client disconnected\n");
            } else {
                printf("Error accepting connection: %s\n", strerror(errno));
            }
        } else {
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
            client_sockets[num_clients++] = client_socket;
        }
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if(client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
        } else {
            printf("Client connected\n");
        }
    }

    return 0;
}