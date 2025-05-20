//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_CLIENTS 10

struct client_info {
    int client_fd;
    char client_name[255];
    struct client_info* next;
};

struct client_info* clients = NULL;

void handle_client(int client_fd) {
    char buffer[1024];
    int read_bytes = read(client_fd, buffer, 1024);
    if (read_bytes > 0) {
        printf("Client: %s, Message: %s", clients->client_name, buffer);
    } else {
        printf("Error reading from client: %s", clients->client_name);
    }
    close(client_fd);
    struct client_info* client_ptr = clients;
    while (client_ptr) {
        if (client_ptr->client_fd == client_fd) {
            clients = client_ptr->next;
            free(client_ptr);
            break;
        }
        client_ptr = client_ptr->next;
    }
}

int main() {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int sin_size = sizeof(client_addr);

    listen_fd = socket(AF_INET, SOCK_STREAM, htons(8080));
    bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    clients = malloc(sizeof(struct client_info));
    clients->client_fd = listen_fd;
    clients->next = NULL;

    while (1) {
        client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &sin_size);
        if (client_fd > 0) {
            struct client_info* new_client = malloc(sizeof(struct client_info));
            new_client->client_fd = client_fd;
            new_client->next = clients;
            clients = new_client;
            strcpy(new_client->client_name, "Client");
            handle_client(client_fd);
        } else {
            printf("Error accepting client connection");
        }
    }

    return 0;
}