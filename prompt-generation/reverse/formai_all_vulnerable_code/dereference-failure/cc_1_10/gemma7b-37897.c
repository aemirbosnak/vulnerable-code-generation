//Gemma-7B DATASET v1.0 Category: Networking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

// Define the client structure
typedef struct Client {
    int socket_fd;
    char name[256];
    struct Client* next;
} Client;

Client* insertClient(Client* head, char* name) {
    Client* newClient = malloc(sizeof(Client));
    newClient->socket_fd = -1;
    strcpy(newClient->name, name);
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        Client* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newClient;
    }

    return head;
}

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    bind(server_fd, NULL, 0);

    Client* head = NULL;

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        char client_name[256];
        recv(client_fd, client_name, 256, 0);

        insertClient(head, client_name);

        printf("Client connected: %s\n", client_name);

        close(client_fd);
    }

    return 0;
}