//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MESSAGE_LENGTH 1024

typedef struct client {
    int socket;
    char name[32];
    char ip[16];
    int port;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(void *arg) {
    char message[MAX_MESSAGE_LENGTH];
    int socket = *(int *)arg;
    free(arg);

    while (1) {
        int length = recv(socket, message, MAX_MESSAGE_LENGTH, 0);
        if (length == 0) {
            printf("Client disconnected.\n");
            break;
        }

        message[length] = '\0';
        printf("Message from %s: %s\n", clients[socket].name, message);

        for (int i = 0; i < num_clients; i++) {
            if (i == socket) {
                continue;
            }

            send(clients[i].socket, message, length, 0);
        }
    }

    close(socket);
    clients[socket].socket = -1;
    num_clients--;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(struct sockaddr_in);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_address, addrlen) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return 1;
    }

    printf("Server listening on port 8080.\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached.\n");
            close(client_socket);
            continue;
        }

        char *ip = inet_ntoa(client_address.sin_addr);
        int port = ntohs(client_address.sin_port);

        printf("Client %s connected from %s:%d.\n", ip, client_socket, port);

        clients[num_clients].socket = client_socket;
        strcpy(clients[num_clients].name, ip);
        strcpy(clients[num_clients].ip, ip);
        clients[num_clients].port = port;
        num_clients++;

        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_socket;
        pthread_create(&thread, NULL, (void *)handle_client, arg);
    }

    close(server_socket);
    return 0;
}