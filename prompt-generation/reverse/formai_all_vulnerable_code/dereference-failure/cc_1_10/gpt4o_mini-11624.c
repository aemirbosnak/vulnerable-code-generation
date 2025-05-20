//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 12345
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Structure to hold client information
typedef struct {
    int socket;
    char name[20];
} Client;

Client *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function for handling each client
void *handle_client(void *arg) {
    Client *client = (Client *)arg;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + 50];

    while (1) {
        // Receive message from client
        int bytes_received = recv(client->socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break; // Client disconnected
        }
        buffer[bytes_received] = '\0';

        // Create the magical response
        snprintf(message, sizeof(message), "[%s] whispers: %s", client->name, buffer);
        printf("%s\n", message);

        // Broadcast the message to other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->socket != client->socket) {
                send(clients[i]->socket, message, strlen(message), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Cleanup on disconnection
    close(client->socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(client);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char name[20];

    // Initialize clients array
    memset(clients, 0, sizeof(clients));

    // Create a TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not bind socket");
        close(server_socket);
        return 1;
    }

    // Start listening for connections
    listen(server_socket, 3);
    printf("🧙‍♂️ Magic Chat Server is running on port %d... ✨\n", PORT);

    // Accept clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Could not accept client");
            close(server_socket);
            return 1;
        }

        printf("🌟 A new magical client has appeared! 🌟\n");

        // Get the client's magical name
        recv(client_socket, name, sizeof(name), 0);
        name[strcspn(name, "\n")] = 0; // Remove newline character
        
        // Create a new client structure
        Client *new_client = malloc(sizeof(Client));
        new_client->socket = client_socket;
        strncpy(new_client->name, name, sizeof(new_client->name));

        // Save the client in the array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = new_client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a new thread to handle the client
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, new_client);
    }

    // Close the server socket (never reaches here in this example)
    close(server_socket);
    return 0;
}