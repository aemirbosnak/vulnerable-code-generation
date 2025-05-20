//Falcon-180B DATASET v1.0 Category: Chat server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        send(client_socket, buffer, bytes_received, 0);
    }
    close(*((int *) client_socket));
    num_clients--;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server started on port %d\n", PORT);

    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);
        client_sockets[num_clients] = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
        num_clients++;
    }

    while (1) {
        sleep(1);
    }

    return 0;
}