//FormAI DATASET v1.0 Category: Networking ; Style: systematic
/* This is a simple TCP server program that listens to incoming connections 
   and echoes back the messages it receives. The server can handle multiple 
   clients concurrently using threads. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// This struct holds information about a client connection.
struct client_info {
    int socket_fd;
    struct sockaddr_in address;
};

// This function is executed in a separate thread for each client connection.
void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    printf("New client connected: %s:%d\n", inet_ntoa(client->address.sin_addr), 
            ntohs(client->address.sin_port));

    // Receive messages from the client and echo them back.
    while ((bytes_read = recv(client->socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client->socket_fd, buffer, bytes_read, 0);
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Close the socket when the client disconnects.
    close(client->socket_fd);
    free(client);
    printf("Client disconnected: %s:%d\n", inet_ntoa(client->address.sin_addr), 
            ntohs(client->address.sin_port));
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    pthread_t client_threads[MAX_CLIENTS];
    int num_clients = 0;

    // Create a TCP socket.
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a local address and port.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(9000);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections.
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Server listening on port 9000...\n");

    // Accept incoming connections and spawn a thread for each one.
    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_socket < 0) {
            perror("Error accepting connection");
        }
        else {
            // Create a struct to hold information about the client and pass it to the thread.
            struct client_info *client = (struct client_info *)malloc(sizeof(struct client_info));
            client->socket_fd = client_socket;
            client->address = client_addr;

            if (pthread_create(&client_threads[num_clients++], NULL, handle_client, client) != 0) {
                perror("Error creating thread");
            }
        }

        // Wait for threads to finish and clean up their resources.
        for (int i = 0; i < num_clients; i++) {
            if (pthread_join(client_threads[i], NULL) != 0) {
                perror("Error joining thread");
            }
        }

        num_clients = 0;
    }

    // Close the server socket.
    close(server_socket);
    return 0;
}