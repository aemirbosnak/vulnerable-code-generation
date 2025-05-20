//FormAI DATASET v1.0 Category: Client Server Application ; Style: active
// A unique C Client-Server Application in an active style
// This program allows multiple clients to connect to a server and communicate with each other.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Default port number used for communication
#define PORT 8080

// Maximum number of clients that can be connected to the server
#define MAX_CLIENTS 5

// Structure to store client information
typedef struct {
    int sock;
    struct sockaddr_in address;
    int id;
} client_t;

// Global variables
client_t clients[MAX_CLIENTS];
int num_clients = 0;

// Function to handle communication between a client and the server
void *handle_client(void *arg) {
    int client_id = *(int *) arg;
    char buffer[1024];

    // Receive messages from the client and broadcast to all other clients
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (recv(clients[client_id].sock, buffer, sizeof(buffer), 0) <= 0) {
            // Client has disconnected
            printf("Client %d disconnected\n", clients[client_id].id);
            close(clients[client_id].sock);
            break;
        } else {
            printf("Received message from client %d: %s", clients[client_id].id, buffer);

            // Broadcast message to all other clients
            for (int i = 0; i < num_clients; i++) {
                if (i != client_id) {
                    send(clients[i].sock, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    // Remove client from list
    for (int i = client_id; i < num_clients - 1; i++) {
        clients[i] = clients[i + 1];
    }
    num_clients--;
}

// Main function for the server
int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024];
    pthread_t thread_id;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow reuse of address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set up address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connections and create a new thread for each client
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Add new client to list
        clients[num_clients].sock = new_socket;
        clients[num_clients].address = address;
        clients[num_clients].id = num_clients;
        num_clients++;

        // Create a new thread to handle communication with the client
        int *client_id = malloc(sizeof(int));
        *client_id = num_clients - 1;
        if (pthread_create(&thread_id, NULL, handle_client, client_id) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
        pthread_detach(thread_id);
    }
    return 0;
}