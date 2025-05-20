//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

typedef struct {
    int socket;
    char username[50];
} Client;

Client *clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(char *message, int sender_socket);
void send_message_to_client(int receiver_socket, char *message);
void list_connected_users(int client_socket);
void remove_client(int client_socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Setup address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Socket listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Socket accept failed");
            continue;
        }

        // Create a new thread for each client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)(intptr_t)new_socket) != 0) {
            perror("Failed to create thread");
        }
    }

    close(server_socket);
    return 0;
}

// Handle client connection
void *handle_client(void *arg) {
    int client_socket = (intptr_t)arg;
    char buffer[BUFFER_SIZE];
    char username[50];

    // Read username from client
    recv(client_socket, username, sizeof(username), 0);
    printf("%s has joined the chat.\n", username);

    // Add client to the list
    pthread_mutex_lock(&clients_mutex);
    clients[client_count] = malloc(sizeof(Client));
    clients[client_count]->socket = client_socket;
    strcpy(clients[client_count]->username, username);
    client_count++;
    pthread_mutex_unlock(&clients_mutex);

    while (1) {
        // Receive message from client
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        
        if (bytes_received <= 0 || strcmp(buffer, "/quit") == 0) {
            break;
        }
        
        // Handle commands
        if (strncmp(buffer, "/msg ", 5) == 0) {
            char *msg_target = strtok(buffer + 5, " ");
            char *msg_content = strtok(NULL, "\n");
            if (msg_target && msg_content) {
                char message[BUFFER_SIZE];
                snprintf(message, sizeof(message), "%s: %s", username, msg_content);
                int found = 0;
                pthread_mutex_lock(&clients_mutex);
                for (int i = 0; i < client_count; i++) {
                    if (strcmp(clients[i]->username, msg_target) == 0) {
                        send_message_to_client(clients[i]->socket, message);
                        found = 1;
                        break;
                    }
                }
                pthread_mutex_unlock(&clients_mutex);
                if (!found) {
                    send_message_to_client(client_socket, "User not found.");
                }
            }
        } else if (strcmp(buffer, "/who") == 0) {
            list_connected_users(client_socket);
        } else {
            char message[BUFFER_SIZE];
            snprintf(message, sizeof(message), "[%s]: %s", username, buffer);
            broadcast_message(message, client_socket);
        }
    }

    // Cleanup
    close(client_socket);
    printf("%s has left the chat.\n", username);
    remove_client(client_socket);
    return NULL;
}

// Broadcast message to all clients
void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Send message to a specific client
void send_message_to_client(int receiver_socket, char *message) {
    send(receiver_socket, message, strlen(message), 0);
}

// List connected users
void list_connected_users(int client_socket) {
    pthread_mutex_lock(&clients_mutex);
    char user_list[BUFFER_SIZE] = "Connected users:\n";
    for (int i = 0; i < client_count; i++) {
        strcat(user_list, clients[i]->username);
        strcat(user_list, "\n");
    }
    send(client_socket, user_list, strlen(user_list), 0);
    pthread_mutex_unlock(&clients_mutex);
}

// Remove client from the list
void remove_client(int client_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket == client_socket) {
            free(clients[i]);
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}