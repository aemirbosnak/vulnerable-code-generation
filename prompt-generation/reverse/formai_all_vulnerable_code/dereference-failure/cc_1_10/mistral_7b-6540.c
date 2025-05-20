//MISTRAL-7B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int client_fd;
    struct sockaddr_in address;
} client_data;

client_data *clients[MAX_CLIENTS];
int client_count = 0;

void broadcast(char *message, int sender_fd) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->client_fd != sender_fd) {
            send(clients[i]->client_fd, message, strlen(message), 0);
        }
    }
}

void handle_client(int new_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;

    client_data *new_client = (client_data *) malloc(sizeof(client_data));
    new_client->client_fd = new_socket;

    memset(&(new_client->address), 0, sizeof(new_client->address));
    new_client->address.sin_family = AF_INET;
    new_client->address.sin_port = htons(0);
    new_client->address.sin_addr.s_addr = INADDR_ANY;

    getsockname(new_socket, (struct sockaddr *)&(new_client->address), NULL);

    printf("New client connected: %s:%d\n", inet_ntoa(new_client->address.sin_addr), ntohs(new_client->address.sin_port));

    clients[client_count] = new_client;
    client_count++;

    while (true) {
        read_size = recv(new_socket, buffer, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            printf("Client disconnected\n");
            free(new_client);
            clients[client_count - 1] = NULL;
            close(new_socket);
            client_count--;
            break;
        }

        printf("Client: %s", buffer);
        broadcast(buffer, new_socket);
    }
}

int main(int argc, char const *argv[]) {
    int socket_desc, client_socket, c, *new_sock;
    struct sockaddr_in server, client;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(socket_desc, 3);

    printf("Server started on port %d\n", PORT);

    while ((client_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*) sizeof(client)))) {
        printf("Accepted new connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        handle_client(client_socket);
    }

    return 0;
}