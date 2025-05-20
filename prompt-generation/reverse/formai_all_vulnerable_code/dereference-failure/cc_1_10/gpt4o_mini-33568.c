//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 12345
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr address;
    int addr_len;
} client_t;

void *handle_client(void *ptr) {
    char buffer[BUFFER_SIZE];
    client_t *cli = (client_t *)ptr;
    int n;

    printf("Accepted connection from %s\n", inet_ntoa(((struct sockaddr_in*)&cli->address)->sin_addr));

    while ((n = recv(cli->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = 0; // Null terminate
        printf("Received: %s\n", buffer);
        send(cli->socket, buffer, n, 0); // Echo back
    }

    close(cli->socket);
    free(cli);
    printf("Client disconnected\n");
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t tid;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        return 1;
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        client_t *cli = malloc(sizeof(client_t));
        cli->addr_len = sizeof(cli->address);
        cli->socket = accept(server_socket, &cli->address, &cli->addr_len);
        if (cli->socket < 0) {
            perror("Connection failed");
            free(cli);
            continue;
        }

        pthread_create(&tid, NULL, handle_client, cli);
        pthread_detach(tid); // Detach thread
    }

    close(server_socket);
    return 0;
}