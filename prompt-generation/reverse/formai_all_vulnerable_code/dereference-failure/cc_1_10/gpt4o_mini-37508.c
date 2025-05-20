//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 256
#define VILLAGE_NAME "C Village"

typedef struct {
    int sockfd;
    char name[20];
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_sockfd);
void add_client(client_t *new_client);
void remove_client(int sockfd);

int main() {
    int listen_sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    
    // Create a socket
    listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(listen_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Couldn't bind to the port");
        close(listen_sockfd);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    listen(listen_sockfd, 3);
    printf("🏰 Welcome to %s! Waiting for brave villagers...\n", VILLAGE_NAME);
    
    while (1) {
        client_len = sizeof(client_addr);
        new_sockfd = accept(listen_sockfd, (struct sockaddr*)&client_addr, &client_len);
        if (new_sockfd < 0) {
            perror("Error on accept");
            continue;
        }

        client_t *new_client = malloc(sizeof(client_t));
        new_client->sockfd = new_sockfd;

        // Ask for the client's name
        send(new_sockfd, "Greetings, brave soul! What is your name?\n", 42, 0);
        recv(new_sockfd, new_client->name, sizeof(new_client->name), 0);
        new_client->name[strcspn(new_client->name, "\n")] = 0; // Remove newline

        printf("🧚‍♂️ A new villager has joined: %s\n", new_client->name);
        add_client(new_client);

        // Create a new thread for handling the client
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, (void*)new_client);
    }

    // Clean up
    close(listen_sockfd);
    return 0;
}

void *handle_client(void *arg) {
    client_t *client = (client_t*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        bytes_read = recv(client->sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_read <= 0) {
            printf("🧙‍♂️ Villager %s has left the village.\n", client->name);
            break;
        }

        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        char message[BUFFER_SIZE];
        snprintf(message, sizeof(message), "%s: %s\n", client->name, buffer);
        broadcast_message(message, client->sockfd);
    }

    // Cleanup for this client
    remove_client(client->sockfd);
    free(client);
    return NULL;
}

void broadcast_message(const char *message, int sender_sockfd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->sockfd != sender_sockfd) {
            send(clients[i]->sockfd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void add_client(client_t *new_client) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = new_client;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void remove_client(int sockfd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->sockfd == sockfd) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}