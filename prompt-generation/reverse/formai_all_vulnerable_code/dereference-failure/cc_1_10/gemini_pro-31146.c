//GEMINI-pro DATASET v1.0 Category: Networking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_info {
    int socket;
    struct sockaddr_in address;
    int id;
};

void *client_handler(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        if (strcmp(buffer, "exit") == 0) {
            printf("Client %d disconnected\n", client->id);
            close(client->socket);
            free(client);
            pthread_exit(NULL);
        }

        printf("Client %d: %s", client->id, buffer);
        memset(buffer, 0, BUFFER_SIZE);

        if (send(client->socket, buffer, n, 0) < 0) {
            perror("Error sending data to client");
            close(client->socket);
            free(client);
            pthread_exit(NULL);
        }
    }
    if (n == 0) {
        printf("Client %d disconnected\n", client->id);
        close(client->socket);
        free(client);
        pthread_exit(NULL);
    } else {
        perror("Error receiving data from client");
        close(client->socket);
        free(client);
        pthread_exit(NULL);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    pthread_t client_threads[MAX_CLIENTS];
    int client_count = 0;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening on server socket");
        return 1;
    }

    while (1) {
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }

        if (client_count >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        struct client_info *client = malloc(sizeof(struct client_info));
        client->socket = client_socket;
        client->address = client_address;
        client->id = client_count++;

        pthread_create(&client_threads[client_count - 1], NULL, client_handler, (void *)client);
    }

    return 0;
}