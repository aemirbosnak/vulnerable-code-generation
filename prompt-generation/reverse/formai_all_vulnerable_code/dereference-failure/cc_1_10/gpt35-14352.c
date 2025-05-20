//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 20

int num_clients = 0; // Number of connected clients
int client_sockets[MAX_CLIENTS]; // Array to store client sockets

// Thread function to handle each client
void *handle_client(void *socket_desc) {
    // Get socket descriptor
    int socket = *(int*) socket_desc;
    int read_size;
    char client_message[2000];

    // Receive client message
    if ((read_size = recv(socket, client_message, 2000, 0)) > 0) {
        printf("Client message:%s\n", client_message);
    }

    return NULL;
}

int main() {
    int server_socket, client_socket, c, *new_socket;
    struct sockaddr_in server, client;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind failed. Error");
        return 1;
    }

    printf("Bind done\n");

    // Listen
    listen(server_socket, 3);
    printf("Waiting for incoming connections...\n");

    c = sizeof(struct sockaddr_in);

    // Accept incoming connections and handle each client in a new thread
    while ((client_socket = accept(server_socket, (struct sockaddr *) &client, (socklen_t *) &c))) {
        printf("New client connected\n");

        // Limit the number of clients
        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        // Add client socket to array
        client_sockets[num_clients] = client_socket;
        num_clients++;

        // Handle client in a new thread
        pthread_t client_thread;
        new_socket = malloc(sizeof(int));
        *new_socket = client_socket;
        if (pthread_create(&client_thread, NULL, handle_client, (void*) new_socket) < 0) {
            perror("Could not create thread");
            return 1;
        }
    }

    if (client_socket < 0) {
        perror("Accept failed");
        return 1;
    }

    return 0;
}