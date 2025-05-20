//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: shape shifting
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
    int sockfd;
    struct sockaddr_in addr;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *cli = (client_t *)arg;
    int read_size;

    while ((read_size = recv(cli->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate string
        printf("Client %d: %s", cli->sockfd, buffer);
        // Broadcast message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->sockfd != cli->sockfd) {
                send(clients[i]->sockfd, buffer, read_size, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    if (read_size == 0) {
        printf("Client %d disconnected\n", cli->sockfd);
    } else {
        perror("recv failed");
    }

    // Remove client from clients list
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == cli) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    
    close(cli->sockfd);
    free(cli);
    return NULL;
}

int main() {
    int server_sockfd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // Create socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to a port
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_sockfd);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_sockfd);
        return EXIT_FAILURE;
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept new client connection
        new_sock = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (new_sock < 0) {
            perror("Connection failed");
            continue;
        }

        printf("Client %d connected\n", new_sock);

        // Allocate client structure
        client_t *cli = malloc(sizeof(client_t));
        cli->sockfd = new_sock;
        cli->addr = client_addr;

        // Add client to clients array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = cli;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Handle client in a separate thread
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)cli) != 0) {
            perror("Thread creation failed");
            close(new_sock);
            free(cli);
        }
    }

    // Close server socket
    close(server_sockfd);
    return EXIT_SUCCESS;
}