//Gemma-7B DATASET v1.0 Category: Chat server ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

struct client_list {
    char name[256];
    int socket_fd;
    struct client_list* next;
};

struct client_list* add_client(struct client_list* head, char* name, int socket_fd) {
    struct client_list* new_client = (struct client_list*)malloc(sizeof(struct client_list));
    strcpy(new_client->name, name);
    new_client->socket_fd = socket_fd;
    new_client->next = head;
    return new_client;
}

void remove_client(struct client_list* head, int socket_fd) {
    struct client_list* current = head;
    struct client_list* previous = NULL;

    while (current) {
        if (current->socket_fd == socket_fd) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    int listen_fd, client_fd, new_client_fd;
    struct client_list* clients = NULL;

    listen_fd = socket(AF_INET, SOCK_STREAM, htons(8080));
    bind(listen_fd, NULL, 0);

    while (1) {
        client_fd = accept(listen_fd, NULL, NULL);
        new_client_fd = fork();

        if (new_client_fd == 0) {
            clients = add_client(clients, "Client", client_fd);
            printf("Client connected: %s\n", clients->name);

            // Handle client communication here
            char buffer[BUFFER_SIZE];
            recv(client_fd, buffer, BUFFER_SIZE, 0);
            printf("Client message: %s\n", buffer);

            send(client_fd, buffer, BUFFER_SIZE, 0);
            remove_client(clients, client_fd);
            printf("Client disconnected: %s\n", clients->name);
            exit(0);
        } else {
            close(client_fd);
        }
    }

    return 0;
}