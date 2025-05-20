//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 256
#define AUTH_TOKEN "secure_token"

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void log_message(const char *msg) {
    FILE *file = fopen("chat_log.txt", "a");
    if (file) {
        time_t now = time(NULL);
        fprintf(file, "[%s] %s\n", ctime(&now), msg);
        fclose(file);
    }
}

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *cli = (client_t *)arg;
    int read_size;
    
    // Authentication
    read(cli->socket, buffer, sizeof(buffer));
    if (strcmp(buffer, AUTH_TOKEN) != 0) {
        char *msg = "Authentication failed. Disconnecting.\n";
        send(cli->socket, msg, strlen(msg), 0);
        close(cli->socket);
        free(cli);
        pthread_exit(NULL);
    } else {
        char *msg = "Authentication successful.\n";
        send(cli->socket, msg, strlen(msg), 0);
    }

    while ((read_size = recv(cli->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';
        log_message(buffer); // Log the message
        printf("Received: %s", buffer); // Display message on server console
        // Relay message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->socket != cli->socket) {
                send(clients[i]->socket, buffer, read_size, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Client has disconnected
    close(cli->socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == cli) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(cli);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Server is running on port %d...\n", PORT);

    while (1) {
        client_t *cli = malloc(sizeof(client_t));
        cli->socket = accept(server_socket, (struct sockaddr *)&cli->address, &client_len);
        if (cli->socket < 0) {
            perror("Connection failed");
            free(cli);
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = cli;
                pthread_t tid;
                pthread_create(&tid, NULL, handle_client, (void *)cli);
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    close(server_socket);
    return 0;
}