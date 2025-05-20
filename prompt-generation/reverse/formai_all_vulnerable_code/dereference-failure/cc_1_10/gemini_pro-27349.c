//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 5000
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 256

// Client struct
typedef struct client {
    int socket_fd;
    char name[MAX_BUFFER_SIZE];
    bool is_connected;
} client_t;

// Global variables
client_t clients[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function declarations
void *client_thread(void *arg);
void send_message_to_all_clients(char *message);
void send_message_to_client(client_t *client, char *message);
void remove_client(client_t *client);
void handle_client_connection(int socket_fd);

int main() {
    // Create a socket
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept connections and create threads for each client
    while (1) {
        int client_socket_fd = accept(server_socket_fd, NULL, NULL);
        if (client_socket_fd == -1) {
            perror("accept");
            continue;
        }

        // Create a new client struct
        client_t *client = malloc(sizeof(client_t));
        memset(client, 0, sizeof(client_t));
        client->socket_fd = client_socket_fd;
        client->is_connected = true;

        // Add the client to the list of clients
        pthread_mutex_lock(&clients_mutex);
        clients[num_clients++] = *client;
        pthread_mutex_unlock(&clients_mutex);

        // Create a new thread for the client
        pthread_t client_thread_id;
        if (pthread_create(&client_thread_id, NULL, client_thread, (void *)client) != 0) {
            perror("pthread_create");
            remove_client(client);
            continue;
        }
    }

    // Close the server socket
    close(server_socket_fd);

    return 0;
}

void *client_thread(void *arg) {
    client_t *client = (client_t *)arg;

    // Receive the client's name
    char buffer[MAX_BUFFER_SIZE];
    if (recv(client->socket_fd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        remove_client(client);
        return NULL;
    }

    // Set the client's name
    strcpy(client->name, buffer);

    // Send a welcome message to the client
    char welcome_message[MAX_BUFFER_SIZE];
    sprintf(welcome_message, "Welcome to the smart home light control system, %s!", client->name);
    send_message_to_client(client, welcome_message);

    // Receive messages from the client
    while (1) {
        if (recv(client->socket_fd, buffer, sizeof(buffer), 0) == -1) {
            perror("recv");
            remove_client(client);
            return NULL;
        }

        // Parse the message
        char *command = strtok(buffer, " ");
        char *argument = strtok(NULL, " ");

        // Handle the command
        if (strcmp(command, "on") == 0) {
            // Turn on the light
            send_message_to_all_clients("The light has been turned on.");
        } else if (strcmp(command, "off") == 0) {
            // Turn off the light
            send_message_to_all_clients("The light has been turned off.");
        } else if (strcmp(command, "quit") == 0) {
            // Quit the program
            remove_client(client);
            return NULL;
        } else {
            // Send an error message
            char error_message[MAX_BUFFER_SIZE];
            sprintf(error_message, "Error: Unknown command '%s'.", command);
            send_message_to_client(client, error_message);
        }
    }

    return NULL;
}

void send_message_to_all_clients(char *message) {
    pthread_mutex_lock(&clients_mutex);

    for (int i = 0; i < num_clients; i++) {
        if (clients[i].is_connected) {
            send_message_to_client(&clients[i], message);
        }
    }

    pthread_mutex_unlock(&clients_mutex);
}

void send_message_to_client(client_t *client, char *message) {
    if (send(client->socket_fd, message, strlen(message), 0) == -1) {
        perror("send");
        remove_client(client);
    }
}

void remove_client(client_t *client) {
    pthread_mutex_lock(&clients_mutex);

    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket_fd == client->socket_fd) {
            clients[i].is_connected = false;
            close(clients[i].socket_fd);
            free(clients[i].name);
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }

    pthread_mutex_unlock(&clients_mutex);
}