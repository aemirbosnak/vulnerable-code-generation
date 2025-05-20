//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

// Structure to store client information
typedef struct client_info {
    int socket;
    struct sockaddr_in address;
    pthread_t thread;
} client_info;

// List of connected clients
client_info clients[100];
int num_clients = 0;

// Mutex to protect the list of connected clients
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client connections
void *handle_client(void *arg) {
    // Get the client information
    client_info *client = (client_info *)arg;

    // Receive the client's message
    char buffer[BUFFER_SIZE];
    int n = recv(client->socket, buffer, BUFFER_SIZE, 0);

    if (n < 0) {
        perror("Error receiving message from client");
        close(client->socket);
        return NULL;
    }

    // Parse the client's message
    char *command = strtok(buffer, " ");

    if (strcmp(command, "backup") == 0) {
        // Handle the backup request
        char *filename = strtok(NULL, " ");
        char *data = strtok(NULL, "\0");

        // Save the file to the server
        FILE *fp = fopen(filename, "w");
        fwrite(data, strlen(data), 1, fp);
        fclose(fp);

        // Send a confirmation message to the client
        char *response = "Backup successful";
        n = send(client->socket, response, strlen(response), 0);

        if (n < 0) {
            perror("Error sending message to client");
            close(client->socket);
            return NULL;
        }
    } else if (strcmp(command, "restore") == 0) {
        // Handle the restore request
        char *filename = strtok(NULL, " ");

        // Read the file from the server
        FILE *fp = fopen(filename, "r");
        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        rewind(fp);

        char *data = malloc(size + 1);
        fread(data, size, 1, fp);
        fclose(fp);

        // Send the file to the client
        n = send(client->socket, data, size, 0);

        if (n < 0) {
            perror("Error sending message to client");
            close(client->socket);
            return NULL;
        }
    } else {
        // Handle the unknown command
        char *response = "Unknown command";
        n = send(client->socket, response, strlen(response), 0);

        if (n < 0) {
            perror("Error sending message to client");
            close(client->socket);
            return NULL;
        }
    }

    // Close the client's socket
    close(client->socket);

    // Remove the client from the list of connected clients
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket == client->socket) {
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    return NULL;
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the socket options
    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the socket to an address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket to address");
        close(server_socket);
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Error listening for connections");
        close(server_socket);
        return -1;
    }

    // Accept incoming connections
    while (1) {
        // Accept a connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);

        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Add the client to the list of connected clients
        pthread_mutex_lock(&clients_mutex);
        clients[num_clients].socket = client_socket;
        clients[num_clients].address = client_address;
        num_clients++;
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread to handle the client
        pthread_create(&clients[num_clients - 1].thread, NULL, handle_client, &clients[num_clients - 1]);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}