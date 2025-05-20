//Falcon-180B DATASET v1.0 Category: Networking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
struct sockaddr_in server_addr;
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
            client_sockets[num_clients] = 0;
            num_clients--;
            break;
        }

        printf("Client %d sent: %s\n", client_socket, buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }

    return NULL;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                num_clients++;
                break;
            }
        }

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Server is full. Cannot accept more clients.\n");
        } else {
            printf("Client %d connected.\n", client_socket);
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    return 0;
}