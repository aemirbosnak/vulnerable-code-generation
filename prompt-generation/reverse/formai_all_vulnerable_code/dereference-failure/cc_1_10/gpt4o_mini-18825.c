//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client data
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast messages to all connected clients
void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle each client connection
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    client_t *cli = (client_t *)arg;
    int leave_flag = 0;

    // Loop to receive messages from this client
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int receive = recv(cli->socket, buffer, sizeof(buffer), 0);
        if (receive > 0) {
            if (strlen(buffer) > 0) {
                printf("Client %d says: %s", cli->socket, buffer);
                snprintf(message, sizeof(message), "Client %d: %s", cli->socket, buffer);
                broadcast_message(message, cli->socket);
            }
        } else {
            leave_flag = 1;
        }
        // If client disconnected
        if (leave_flag) {
            break;
        }
    }

    // Clean up and close connection when a client disconnects
    close(cli->socket);
    free(cli);
    pthread_exit(NULL);
}

// Main function to set up the server
int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int option = 1;
    
    // Setting up server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    // Initialize server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Chat server started on port %d\n", PORT);

    while (1) {
        socklen_t addr_len = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        
        // Check if maximum clients are reached
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = malloc(sizeof(client_t));
                clients[i]->socket = new_socket;
                clients[i]->address = client_addr;
                clients[i]->addr_len = addr_len;

                // Create a new thread for the client
                pthread_t tid;
                if (pthread_create(&tid, NULL, handle_client, (void *)clients[i]) != 0) {
                    perror("Thread creation failed");
                }
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Clean up before exiting
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL) {
            free(clients[i]);
        }
    }
    close(server_socket);
    return 0;
}