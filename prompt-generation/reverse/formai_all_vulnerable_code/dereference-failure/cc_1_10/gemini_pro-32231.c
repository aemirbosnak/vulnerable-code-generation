//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <stdbool.h>

#define PORT 8080
#define MAX_CLIENTS 10

typedef struct client {
    int sockfd;
    char name[256];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast_message(char *message) {
    for (int i = 0; i < num_clients; i++) {
        send(clients[i].sockfd, message, strlen(message), 0);
    }
}

void *client_handler(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[256];
    while (true) {
        int n = recv(client->sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            // Client disconnected
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].sockfd == client->sockfd) {
                    // Remove client from list
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    break;
                }
            }
            free(client);
            pthread_exit(NULL);
        } else {
            // Broadcast message to all clients
            char message[256];
            snprintf(message, sizeof(message), "%s: %s", client->name, buffer);
            broadcast_message(message);
        }
    }
}

int main() {
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(serverfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    while (true) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int clientfd = accept(serverfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (clientfd == -1) {
            perror("accept");
            continue;
        }

        // Add client to list
        if (num_clients < MAX_CLIENTS) {
            client_t *client = malloc(sizeof(client_t));
            client->sockfd = clientfd;
            recv(clientfd, client->name, sizeof(client->name), 0);
            clients[num_clients] = *client;
            num_clients++;

            // Broadcast new client's name to all clients
            char message[256];
            snprintf(message, sizeof(message), "%s has joined the chat!", client->name);
            broadcast_message(message);

            // Create a new thread for the client
            pthread_t thread;
            if (pthread_create(&thread, NULL, client_handler, client) != 0) {
                perror("pthread_create");
                continue;
            }
        } else {
            // Too many clients, send error message
            char message[] = "Too many clients, please try again later.";
            send(clientfd, message, strlen(message), 0);
            close(clientfd);
        }
    }

    close(serverfd);
    return 0;
}