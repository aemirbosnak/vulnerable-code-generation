//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10

struct client {
    int socket;
    char name[256];
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    struct client *client = (struct client *)arg;
    char buffer[256];
    int bytes_received;

    while ((bytes_received = recv(client->socket, buffer, 256, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("[%s]: %s\n", client->name, buffer);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket != client->socket) {
                send(clients[i].socket, buffer, bytes_received, 0);
            }
        }
    }

    close(client->socket);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket == client->socket) {
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    pthread_t thread;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create server socket");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Could not bind server socket");
        return -1;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Could not listen on server socket");
        return -1;
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Could not accept client connection");
        } else {
            if (num_clients >= MAX_CLIENTS) {
                send(client_socket, "Server is full", 14, 0);
                close(client_socket);
            } else {
                printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                send(client_socket, "Welcome to the chat server!", 27, 0);

                struct client new_client;
                new_client.socket = client_socket;
                strcpy(new_client.name, inet_ntoa(client_address.sin_addr));

                clients[num_clients] = new_client;
                num_clients++;

                pthread_create(&thread, NULL, handle_client, (void *)&new_client);
            }
        }
    }

    close(server_socket);
    return 0;
}