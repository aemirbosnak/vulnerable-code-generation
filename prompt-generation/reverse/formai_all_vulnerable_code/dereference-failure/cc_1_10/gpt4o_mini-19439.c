//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 256
#define MAX_NAME_LEN 20

typedef struct {
    int sock;
    struct sockaddr_in address;
    char username[MAX_NAME_LEN];
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + MAX_NAME_LEN];
    int leave_flag = 0;
    client_t *cli = (client_t *)arg;

    // Welcome message
    sprintf(message, "Welcome to the Crater Chat, %s! Survive and connect!\n", cli->username);
    send(cli->sock, message, strlen(message), 0);

    // Communication loop
    while (1) {
        int recv_size = recv(cli->sock, buffer, sizeof(buffer), 0);
        if (recv_size <= 0) {
            leave_flag = 1;
            break;
        }
        buffer[recv_size] = '\0';

        // Constructing a message to broadcast
        sprintf(message, "%s: %s", cli->username, buffer);
        printf("[%s]: %s", cli->username, buffer);

        // Broadcasting message to other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->sock != cli->sock) {
                send(clients[i]->sock, message, strlen(message), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(cli->sock);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == cli) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(cli);
    printf("%s has left the chat\n", cli->username);
    return NULL;
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Server setup
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
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    listen(server_sock, 3);
    printf("** Crater Chat server is running in the wasteland! **\n");

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        // Allocate client
        client_t *client = (client_t *)malloc(sizeof(client_t));
        client->sock = client_sock;
        client->address = client_addr;

        // Ask for the username
        send(client->sock, "Enter your username: ", 21, 0);
        recv(client->sock, client->username, MAX_NAME_LEN, 0);
        client->username[strcspn(client->username, "\n")] = 0; // Remove newline character

        // Add client to the clients array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Start a thread for the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)client) != 0) {
            perror("Thread creation failed");
            free(client);
        }

        // Detach thread
        pthread_detach(tid);
    }

    return 0;
}