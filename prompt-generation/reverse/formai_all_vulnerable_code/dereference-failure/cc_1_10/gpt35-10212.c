//FormAI DATASET v1.0 Category: Networking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *client_handler(void *arg);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [port]\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create server socket!\n");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind server socket!\n");
        return 1;
    }

    if (listen(server_socket, 5) < 0) {
        printf("Failed to listen to server socket!\n");
        return 1;
    }

    printf("Server is running on port %d...\n", port);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            printf("Failed to accept client socket!\n");
            continue;
        }

        pthread_t thread;
        if (pthread_create(&thread, NULL, client_handler, (void *) (intptr_t) client_socket) < 0) {
            printf("Failed to create client thread!\n");
            continue;
        }
    }

    return 0;
}

void *client_handler(void *arg) {
    int client_socket = (intptr_t) arg;

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (recv(client_socket, buffer, sizeof(buffer), 0) > 0) {
        printf("Client sent the following message: %s\n", buffer);

        if (strcmp(buffer, "quit") == 0) {
            close(client_socket);
            break;
        }

        // Echo the message back to client
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            printf("Failed to send message back to client!\n");
            break;
        }

        memset(buffer, 0, sizeof(buffer));
    }

    printf("Client disconnected.\n");

    return NULL;
}