//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MESSAGE_SIZE 1024
#define SERVER_PORT 8080
#define WELCOME_MESSAGE "Welcome to the most exciting chat server ever! Get ready to mingle and make new friends!"
#define GOODBYE_MESSAGE "Adios, amigo! Come back soon for more chattastical adventures!"

// Client data structure
typedef struct {
    int socket_fd;
    char username[32];
} client;

// Array of clients
client clients[MAX_CLIENTS];

// Mutex to protect the array of clients
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to send a message to all clients
void broadcast_message(char *message) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket_fd != 0) {
            send(clients[i].socket_fd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle a client
void *handle_client(void *arg) {
    int socket_fd = *(int *)arg;
    free(arg);
    
    // Receive the username
    char username[32];
    recv(socket_fd, username, 32, 0);

    // Send the welcome message
    send(socket_fd, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE), 0);

    // Add the client to the array of clients
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket_fd == 0) {
            clients[i].socket_fd = socket_fd;
            strcpy(clients[i].username, username);
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    // Broadcast the new client's username
    char message[MAX_MESSAGE_SIZE];
    sprintf(message, "%s has joined the chat!", username);
    broadcast_message(message);

    // Continuously receive messages from the client
    while (1) {
        char message[MAX_MESSAGE_SIZE];
        int len = recv(socket_fd, message, MAX_MESSAGE_SIZE, 0);
        if (len <= 0) {
            break;
        }

        // Broadcast the message
        sprintf(message, "%s: %s", username, message);
        broadcast_message(message);
    }

    // Remove the client from the array of clients
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket_fd == socket_fd) {
            clients[i].socket_fd = 0;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    // Broadcast the goodbye message
    sprintf(message, "%s has left the chat!", username);
    broadcast_message(message);

    // Close the socket
    close(socket_fd);

    return NULL;
}

int main() {
    
    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    
    // Set the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
    
    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }
    
    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }
    
    printf("The chat server is up and running! Get ready for some serious chitchat!\n");
    
    while (1) {
        
        // Accept an incoming connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_socket;
        if (pthread_create(&thread, NULL, handle_client, arg) != 0) {
            perror("pthread_create");
            close(client_socket);
            continue;
        }
    }
    
    // Close the server socket
    close(server_socket);
    
    return EXIT_SUCCESS;
}