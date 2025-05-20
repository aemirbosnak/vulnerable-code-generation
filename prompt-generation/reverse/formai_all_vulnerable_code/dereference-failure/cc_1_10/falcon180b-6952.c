//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
char *message;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(*((int*)client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Client %d sent: %s\n", *(int*)client_socket, buffer);
        send(server_socket, buffer, bytes_received, 0);
    }
    close(*((int*)client_socket));
    num_clients--;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    while (num_clients < MAX_CLIENTS) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        client_sockets[num_clients] = client_socket;
        printf("Client %d connected\n", num_clients);
        num_clients++;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void*)&client_socket);
    }
    while (1) {
        char buffer[BUFFER_SIZE];
        int bytes_received;
        while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            printf("Received: %s\n", buffer);
            for (int i = 0; i < num_clients; i++) {
                send(client_sockets[i], buffer, bytes_received, 0);
            }
        }
    }
    return 0;
}