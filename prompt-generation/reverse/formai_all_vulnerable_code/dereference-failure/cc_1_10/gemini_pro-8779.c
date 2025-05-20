//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

// Structure to hold client information
typedef struct client {
    int sockfd;
    struct sockaddr_in addr;
    char *name;
} client_t;

// List of connected clients
client_t *clients[100];
int num_clients = 0;

// Mutex to protect the client list
pthread_mutex_t client_list_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client connections
void *handle_client(void *arg) {
    // Get the client information
    client_t *client = (client_t *)arg;

    // Send a welcome message to the client
    char welcome_msg[] = "Welcome to the chat server!\n";
    write(client->sockfd, welcome_msg, strlen(welcome_msg));

    // Receive messages from the client
    char buffer[1024];
    while (1) {
        int bytes_received = read(client->sockfd, buffer, sizeof(buffer));
        if (bytes_received <= 0) {
            // Client has disconnected
            break;
        }

        // Process the message
        char *msg = strtok(buffer, "\n");
        if (strncmp(msg, "/name", 5) == 0) {
            // Client is setting their name
            client->name = strdup(strtok(NULL, "\n"));
        } else if (strncmp(msg, "/list", 5) == 0) {
            // Client is requesting a list of connected clients
            char list_msg[1024] = "Connected clients:\n";
            for (int i = 0; i < num_clients; i++) {
                strcat(list_msg, clients[i]->name);
                strcat(list_msg, "\n");
            }
            write(client->sockfd, list_msg, strlen(list_msg));
        } else {
            // Client is sending a message to all other clients
            pthread_mutex_lock(&client_list_mutex);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i] != client) {
                    char msg_to_send[1024];
                    sprintf(msg_to_send, "%s: %s\n", client->name, msg);
                    write(clients[i]->sockfd, msg_to_send, strlen(msg_to_send));
                }
            }
            pthread_mutex_unlock(&client_list_mutex);
        }
    }

    // Client has disconnected
    pthread_mutex_lock(&client_list_mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i] == client) {
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&client_list_mutex);

    close(client->sockfd);
    free(client->name);
    free(client);

    return NULL;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Start listening for connections
    if (listen(sockfd, 10) < 0) {
        perror("listen");
        return 1;
    }

    // Accept connections from clients
    while (1) {
        // Accept a connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("accept");
            continue;
        }

        // Create a new client thread
        pthread_t client_thread;
        client_t *client = malloc(sizeof(client_t));
        client->sockfd = client_sockfd;
        client->addr = client_addr;
        client->name = NULL;
        pthread_create(&client_thread, NULL, handle_client, client);

        // Add the client to the list of connected clients
        pthread_mutex_lock(&client_list_mutex);
        clients[num_clients] = client;
        num_clients++;
        pthread_mutex_unlock(&client_list_mutex);
    }

    // Close the socket
    close(sockfd);

    return 0;
}