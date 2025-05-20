//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

struct client_data {
    int socket;
    char *name;
    int is_authenticated;
    pthread_t thread;
};

struct client_data clients[MAX_CLIENTS];
int num_clients = 0;

void *client_thread(void *arg) {
    struct client_data *client = (struct client_data *)arg;
    char buffer[MAX_BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int recv_size = recv(client->socket, buffer, sizeof(buffer), 0);
        if (recv_size <= 0) {
            printf("Client %s disconnected.\n", client->name);
            close(client->socket);
            free(client->name);
            free(client);
            num_clients--;
            break;
        }

        // Check if the client is authenticated
        if (!client->is_authenticated) {
            if (strcmp(buffer, "authenticate") == 0) {
                // Send the client a challenge
                char challenge[MAX_BUFFER_SIZE];
                sprintf(challenge, "%d", rand());
                send(client->socket, challenge, strlen(challenge), 0);
            } else {
                // Close the client's connection
                send(client->socket, "Invalid authentication.", strlen("Invalid authentication."), 0);
                close(client->socket);
                free(client->name);
                free(client);
                num_clients--;
                break;
            }
        } else {
            // Process the client's request
            printf("Received message from client %s: %s\n", client->name, buffer);
            send(client->socket, "Received your message.", strlen("Received your message."), 0);
        }
    }

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Set the server socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting server socket options");
        exit(1);
    }

    // Bind the server socket to the port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server is listening on port %d.\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Create a new client struct
        struct client_data *new_client = (struct client_data *)malloc(sizeof(struct client_data));
        new_client->socket = client_socket;
        new_client->name = strdup(inet_ntoa(client_addr.sin_addr));
        new_client->is_authenticated = 0;

        // Add the new client to the list of clients
        clients[num_clients] = *new_client;
        num_clients++;

        // Create a new thread for the client
        pthread_create(&new_client->thread, NULL, client_thread, (void *)new_client);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}