//FormAI DATASET v1.0 Category: Chat server ; Style: decentralized
// Decentralized Chat Server Example Program in C Language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>

void error(const char *message) { // Function to handle errors
    perror(message);
    exit(1);
}

typedef struct client { // Struct to store client information
    int sock;
    struct sockaddr_in addr;
    char name[256];
} client_t;

client_t *clients[100];
pthread_mutex_t mutex;

void *handler(void *arg) { // Thread function for handling incoming messages
    client_t *cli = (client_t *)arg;
    char message[256];
    int n;

    while ((n = recv(cli->sock, message, sizeof(message), 0)) > 0) {
        message[n] = '\0';

        if (strstr(message, "/name") == message) { // Special command to set name
            strcpy(cli->name, message + 6);
            continue;
        }

        pthread_mutex_lock(&mutex);

        for (int i = 0; clients[i] != NULL; i++) {
            if (clients[i] != cli) {
                send(clients[i]->sock, cli->name, strlen(cli->name), 0);
                send(clients[i]->sock, ": ", 2, 0);
                send(clients[i]->sock, message, strlen(message), 0);
            }
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);

    for (int i = 0; clients[i] != NULL; i++) { // Remove client from array
        if (clients[i] == cli) {
            clients[i] = NULL;
        }
    }

    pthread_mutex_unlock(&mutex);

    close(cli->sock);
    free(cli);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error("Usage: ./server <port>");
    }

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Error opening socket");
    }

    int option = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)); // Reuse address option

    struct sockaddr_in server_addr, client_addr;
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Binding failed");
    }

    listen(server_sock, 5);

    socklen_t client_len = sizeof(client_addr);
    pthread_t thread;

    while (1) {
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);

        if (client_sock < 0) {
            error("Error on accept");
        }

        client_t *cli = malloc(sizeof(client_t));
        cli->sock = client_sock;
        cli->addr = client_addr;
        sprintf(cli->name, "Client %d", client_sock);

        pthread_mutex_lock(&mutex);

        for (int i = 0; i < 100; i++) { // Add client to array
            if (clients[i] == NULL) {
                clients[i] = cli;
                break;
            }
        }

        pthread_mutex_unlock(&mutex);

        pthread_create(&thread, NULL, handler, (void *)cli);
    }

    close(server_sock);
    return 0;
}