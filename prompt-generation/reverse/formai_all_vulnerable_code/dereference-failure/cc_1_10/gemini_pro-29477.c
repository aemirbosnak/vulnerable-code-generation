//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Maximum number of clients
#define MAX_CLIENTS 100

// Maximum size of a message
#define MAX_MESSAGE_SIZE 1024

// Client structure
typedef struct client {
    int socket;
    char username[32];
    char email[64];
    bool subscribed;
    struct client *next;
} client_t;

// Client list head
client_t *clients = NULL;

// Mutex to protect the client list
pthread_mutex_t client_list_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a client to the list
void add_client(client_t *client) {
    pthread_mutex_lock(&client_list_mutex);
    client->next = clients;
    clients = client;
    pthread_mutex_unlock(&client_list_mutex);
}

// Function to remove a client from the list
void remove_client(client_t *client) {
    pthread_mutex_lock(&client_list_mutex);
    if (clients == client) {
        clients = client->next;
    } else {
        client_t *prev = clients;
        while (prev->next != client) {
            prev = prev->next;
        }
        prev->next = client->next;
    }
    pthread_mutex_unlock(&client_list_mutex);
    free(client);
}

// Function to send a message to all subscribed clients
void send_message(const char *message) {
    pthread_mutex_lock(&client_list_mutex);
    client_t *client = clients;
    while (client != NULL) {
        if (client->subscribed) {
            send(client->socket, message, strlen(message), 0);
        }
        client = client->next;
    }
    pthread_mutex_unlock(&client_list_mutex);
}

// Function to handle a client connection
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;

    // Receive the client's username and email
    char buffer[MAX_MESSAGE_SIZE];
    recv(client->socket, buffer, sizeof(buffer), 0);
    sscanf(buffer, "%s %s", client->username, client->email);

    // Add the client to the list
    add_client(client);

    // Send a welcome message to the client
    send(client->socket, "Welcome to the mailing list!\n", strlen("Welcome to the mailing list!\n"), 0);

    // Main loop
    while (true) {
        // Receive a message from the client
        recv(client->socket, buffer, sizeof(buffer), 0);

        // Parse the message
        char command[32];
        sscanf(buffer, "%s", command);

        // Handle the command
        if (strcmp(command, "SUBSCRIBE") == 0) {
            client->subscribed = true;
            send(client->socket, "You have been subscribed to the mailing list.\n", strlen("You have been subscribed to the mailing list.\n"), 0);
        } else if (strcmp(command, "UNSUBSCRIBE") == 0) {
            client->subscribed = false;
            send(client->socket, "You have been unsubscribed from the mailing list.\n", strlen("You have been unsubscribed from the mailing list.\n"), 0);
        } else if (strcmp(command, "SEND") == 0) {
            // Send the message to all subscribed clients
            send_message(buffer + strlen(command) + 1);
        } else if (strcmp(command, "QUIT") == 0) {
            // Remove the client from the list and close the connection
            remove_client(client);
            close(client->socket);
            break;
        } else {
            // Send an error message to the client
            send(client->socket, "Invalid command.\n", strlen("Invalid command.\n"), 0);
        }
    }

    return NULL;
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    // Bind the socket to an address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(1234);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return 1;
    }

    // Main loop
    while (true) {
        // Accept a connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a new client thread
        pthread_t client_thread;
        client_t *client = malloc(sizeof(client_t));
        client->socket = client_socket;
        pthread_create(&client_thread, NULL, handle_client, client);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}