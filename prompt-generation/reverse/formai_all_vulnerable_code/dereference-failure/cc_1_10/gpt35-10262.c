//FormAI DATASET v1.0 Category: Chat server ; Style: decentralized
/*
    Decentralized Chat Server Example
    Author: Your Name
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MESSAGE_LEN 1024

int num_clients = 0;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *args) {
    int client_socket = *(int*)args;
    char buffer[MAX_MESSAGE_LEN];

    while (1) {
        memset(buffer, 0, MAX_MESSAGE_LEN);
        if (recv(client_socket, buffer, MAX_MESSAGE_LEN, 0) <= 0) {
            break;
        }

        pthread_mutex_lock(&mutex);
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    printf("Client %d disconnected\n", client_socket);
    close(client_socket);

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = -1;
        }
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [port]\n", argv[0]);
        return 1;
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen");
        return 1;
    }

    printf("Server listening on port %d\n", atoi(argv[1]));

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Failed to accept client");
            continue;
        }

        printf("Client %d connected\n", client_socket);

        pthread_mutex_lock(&mutex);
        if (num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached, closing connection\n");
            close(client_socket);
        } else {
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == -1) {
                    client_sockets[i] = client_socket;
                    num_clients++;
                    pthread_t thread;
                    pthread_create(&thread, NULL, handle_client, (void*)&client_socket);
                    break;
                }
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    close(server_socket);
    return 0;
}