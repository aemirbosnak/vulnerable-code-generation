//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Client structure
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
}

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    int receive;
    client_t *client = (client_t *)arg;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        receive = recv(client->socket, buffer, sizeof(buffer), 0);
        if (receive > 0) {
            printf("Client [%d]: %s", client->socket, buffer);
            broadcast_message(buffer, client->socket);
        } else if (receive == 0) {
            printf("Client [%d] disconnected.\n", client->socket);
            break;
        } else {
            perror("recv failed");
            break;
        }
    }

    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t tid;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        return 1;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (new_socket < 0) {
            perror("Accepting failed");
            continue;
        }

        // Create a new client structure
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->socket = new_socket;
        new_client->address = client_addr;

        // Store the client in the array
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = new_client;
                pthread_create(&tid, NULL, handle_client, new_client);
                break;
            }
        }
    }

    // Cleanup
    close(server_socket);
    return 0;
}