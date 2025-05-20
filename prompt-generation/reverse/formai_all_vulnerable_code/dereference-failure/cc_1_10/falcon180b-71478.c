//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_RECEIVE_SIZE 1024

int clients[MAX_CLIENTS][2];
int num_clients = 0;

void broadcast(int sender_socket, char* message) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i][0]!= sender_socket) {
            send(clients[i][0], message, strlen(message), 0);
        }
    }
}

int main(int argc, char* argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_socket, 3);

    printf("Server listening on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        printf("Client connected: %d\n", client_socket);

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Try again later.\n", 38, 0);
            close(client_socket);
            continue;
        }

        int index = num_clients;
        clients[index][0] = client_socket;
        clients[index][1] = 0;
        num_clients++;

        char* welcome_message = malloc(64);
        sprintf(welcome_message, "Client %d connected\n", index + 1);
        broadcast(client_socket, welcome_message);
        free(welcome_message);
    }

    return 0;
}