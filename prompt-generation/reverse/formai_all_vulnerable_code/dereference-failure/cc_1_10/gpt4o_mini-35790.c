//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: puzzling
#include <stdio.h>          
#include <stdlib.h>       
#include <string.h>       
#include <unistd.h>      
#include <arpa/inet.h>   
#include <pthread.h>      
#include <signal.h>       
#include <linux/limits.h> 

#define PORT 8080        
#define MAX_CLIENTS 10   
#define BUFFER_SIZE 1024  
#define NAME_SIZE 32      

char *colors[] = {
    "\033[1;31m",  // Red for admin
    "\033[1;32m",  // Green for users
    "\033[1;34m",  // Blue for guests
    "\033[0m"      // Reset
};

typedef struct {
    int sockfd;
    char name[NAME_SIZE];
} Client;

Client *clients[MAX_CLIENTS];
int client_count = 0;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void add_client(Client *client) {
    pthread_mutex_lock(&clients_mutex);
    clients[client_count++] = client;
    pthread_mutex_unlock(&clients_mutex);
}

void remove_client(Client *client) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == client) {
            for (int j = i; j < client_count - 1; j++) {
                clients[j] = clients[j + 1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void broadcast_message(char *message, Client *sender) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != sender) {
            send(clients[i]->sockfd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *arg) {
    Client *client = (Client *)arg;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + NAME_SIZE];

    while (1) {
        int received = recv(client->sockfd, buffer, sizeof(buffer) - 1, 0);
        if (received <= 0) {
            break; // Connection closed
        }
        buffer[received] = '\0'; // Null-terminate the string

        snprintf(message, sizeof(message), "%s: %s%s", client->name, buffer, colors[3]);
        printf("%s\n", message);

        broadcast_message(message, client);
    }

    close(client->sockfd);
    remove_client(client);
    free(client);
    return NULL;
}

void handle_sigint(int sig) {
    printf("\nShutting down server...\n");
    exit(0);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);

    signal(SIGINT, handle_sigint); // Capture Ctrl+C

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started. Waiting for clients to connect...\n");

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        Client *new_client = (Client *)malloc(sizeof(Client));
        new_client->sockfd = new_socket;

        recv(new_socket, new_client->name, NAME_SIZE, 0);
        new_client->name[strcspn(new_client->name, "\n")] = 0; // Remove newline

        printf("New client connected: %s\n", new_client->name);
        add_client(new_client);

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, new_client);
        pthread_detach(tid);
    }

    return 0;
}