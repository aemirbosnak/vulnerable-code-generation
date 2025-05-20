//FormAI DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080

// This struct holds the data for each client.
struct client {
    int fd;
    struct sockaddr_in address;
    char *name;
};

// Global variables
int client_count = 0;
struct client *clients[MAX_CLIENTS];

// This function is run by a thread for each new client that connects to the server.
void *handle_client(void *arg) {
    struct client *c = (struct client *) arg;

    // Send a welcome message to the client
    char *welcome = "Welcome to the chat room!\n";
    send(c->fd, welcome, strlen(welcome), 0);

    // Loop continuously, receiving messages from the client and broadcasting them to all other clients.
    char buffer[1024];
    int read_size;
    while ((read_size = recv(c->fd, buffer, sizeof(buffer), 0)) > 0) {
        // Null-terminate the buffer
        buffer[read_size] = '\0';

        // Print the message on the server side
        printf("%s: %s", c->name, buffer);

        // Broadcast the message to all other clients
        for (int i = 0; i < client_count; i++) {
            if (clients[i] != NULL && clients[i] != c) {
                send(clients[i]->fd, buffer, strlen(buffer), 0);
            }
        }
    }

    // If we get here, the client has disconnected
    printf("%s has disconnected\n", c->name);

    // Close the connection and free the client struct
    close(c->fd);
    free(c->name);
    free(c);

    // We need to decrement the client_count and set the slot in the array to NULL
    client_count--;
    return NULL;
}

int main() {
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set up the server address struct
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and start listening for clients
    if (bind(listenfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    listen(listenfd, MAX_CLIENTS);

    printf("Server is listening on port %d\n", PORT);

    // Loop continuously to accept and handle new client connections
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);
    char name_buffer[1024];
    while (1) {
        int client_fd = accept(listenfd, (struct sockaddr *) &client_address, (socklen_t *) &addrlen);
        if (client_fd < 0) {
            perror("Failed to accept client");
            continue;
        }

        // Get the client's name
        printf("Enter name for client %d: ", client_count);
        fgets(name_buffer, sizeof(name_buffer), stdin);
        name_buffer[strlen(name_buffer) - 1] = '\0';

        // Create a new client struct and add it to the clients array
        struct client *c = malloc(sizeof(struct client));
        c->fd = client_fd;
        c->address = client_address;
        c->name = strdup(name_buffer);
        clients[client_count++] = c;

        // Start a new thread to handle the client
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *) c);
    }

    // Close the listening socket
    close(listenfd);

    return 0;
}