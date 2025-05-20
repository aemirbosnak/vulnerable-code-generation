//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_handler(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *cli = (client_t *)arg;
    int rc;

    while ((rc = recv(cli->sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[rc] = '\0'; // Null-terminate the buffer
        printf("Client %d: %s\n", cli->sock, buffer);
        for (int i = 0; i < client_count; i++) {
            if (clients[i]->sock != cli->sock) { // Don't send to self
                send(clients[i]->sock, buffer, rc, 0);
            }
        }
    }

    if (rc == 0) {
        printf("Client %d disconnected\n", cli->sock);
    } else {
        perror("recv");
    }

    close(cli->sock);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->sock == cli->sock) {
            free(clients[i]);
            clients[i] = clients[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(cli);
    return NULL;
}

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started, waiting for connections...\n");

    while (1) {
        client_t *cli = malloc(sizeof(client_t));
        cli->sock = accept(server_sock, (struct sockaddr *)&cli->address, &addr_len);
        if (cli->sock < 0) {
            perror("Accept failed");
            free(cli);
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        clients[client_count++] = cli;
        pthread_mutex_unlock(&clients_mutex);

        printf("Client %d connected\n", cli->sock);

        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, (void *)cli) != 0) {
            perror("Thread creation failed");
            free(cli);
        }
    }

    close(server_sock);
    return 0;
}