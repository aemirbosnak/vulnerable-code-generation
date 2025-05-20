//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256
#define PORT 8080

// Structure to handle client information
typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int addr_len;
    char name[50];
} Client;

// Function declarations
void *client_handler(void *arg);
void broadcast_message(char *message, int sender_sock);
void configure_server(int *server_sockfd, struct sockaddr_in *server_addr);
void get_client_name(Client *client);

// Global variables
Client *clients[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_sockfd;
    struct sockaddr_in server_addr;

    // Configure server settings
    configure_server(&server_sockfd, &server_addr);

    // Listen for incoming client connections
    listen(server_sockfd, 5);
    printf("Chat server started on port %d. Waiting for connections...\n", PORT);

    while (1) {
        Client *new_client = (Client *)malloc(sizeof(Client));
        new_client->addr_len = sizeof(new_client->addr);
        new_client->sockfd = accept(server_sockfd, (struct sockaddr*)&new_client->addr, (socklen_t*)&new_client->addr_len);
        
        if (new_client->sockfd < 0) {
            perror("Error accepting client connection");
            free(new_client);
            continue;
        }

        get_client_name(new_client);
        clients[client_count++] = new_client;

        printf("%s connected.\n", new_client->name);

        // Create a thread for the new client
        pthread_t tid;
        pthread_create(&tid, NULL, client_handler, (void *)new_client);
    }

    close(server_sockfd);
    return 0;
}

void configure_server(int *server_sockfd, struct sockaddr_in *server_addr) {
    *server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*server_sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = INADDR_ANY;
    server_addr->sin_port = htons(PORT);

    if (bind(*server_sockfd, (struct sockaddr*)server_addr, sizeof(*server_addr)) < 0) {
        perror("Error binding socket");
        close(*server_sockfd);
        exit(EXIT_FAILURE);
    }
}

void get_client_name(Client *client) {
    char welcome_msg[] = "Welcome to the chat server! Please enter your name: ";
    send(client->sockfd, welcome_msg, strlen(welcome_msg), 0);
    
    recv(client->sockfd, client->name, sizeof(client->name), 0);
    client->name[strcspn(client->name, "\n")] = 0; // Remove newline character
}

void *client_handler(void *arg) {
    Client *client = (Client *)arg;
    char buffer[BUFFER_SIZE];
    int recv_size;

    while ((recv_size = recv(client->sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[recv_size] = '\0'; // Null-terminate the received message
        printf("%s: %s\n", client->name, buffer);
        broadcast_message(buffer, client->sockfd);
    }

    // Cleanup after client disconnects
    printf("%s disconnected.\n", client->name);
    close(client->sockfd);
    free(client);
    return NULL;
}

void broadcast_message(char *message, int sender_sock) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->sockfd != sender_sock) {
            send(clients[i]->sockfd, message, strlen(message), 0);
        }
    }
}