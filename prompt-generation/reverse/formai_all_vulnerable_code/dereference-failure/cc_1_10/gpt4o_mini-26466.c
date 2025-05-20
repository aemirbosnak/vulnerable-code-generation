//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024
#define NAME_SIZE 50

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    char name[NAME_SIZE];
} Client;

// Function prototypes
void *handle_client(void *arg);
void send_message_to_all(Client clients[], char *message, int sender_socket);
void setup_server();

Client clients[MAX_CLIENTS];
int client_count = 0;

int main() {
    setup_server();
    return 0;
}

void setup_server() {
    int server_fd, new_socket;
    struct sockaddr_in server_address;
    pthread_t tid;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure address settings
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("🚀 Server is up and running on port %d...\n", PORT);

    while (1) {
        // Accept new connections
        socklen_t addrlen = sizeof(struct sockaddr_in);
        Client *new_client = (Client *)malloc(sizeof(Client));
        new_client->socket = accept(server_fd, (struct sockaddr *)&new_client->address, &addrlen);
        
        if (new_client->socket < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        // Get client name
        recv(new_client->socket, new_client->name, NAME_SIZE, 0);
        printf("💻 %s has joined the chat!\n", new_client->name);

        // Add new client to the clients array
        clients[client_count++] = *new_client;

        // Create a new thread to handle each client
        pthread_create(&tid, NULL, handle_client, (void *)new_client);
    }
}

void *handle_client(void *arg) {
    Client client = *(Client *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Client communication loop
    while ((bytes_received = recv(client.socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        char message[BUFFER_SIZE + NAME_SIZE];
        snprintf(message, sizeof(message), "[%s]: %s", client.name, buffer);
        printf("%s", message);
        send_message_to_all(clients, message, client.socket);
    }

    // Handle client disconnection
    printf("🚪 %s has disconnected.\n", client.name);
    close(client.socket);
    free(arg);
    return NULL;
}

void send_message_to_all(Client clients[], char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket != sender_socket) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
}