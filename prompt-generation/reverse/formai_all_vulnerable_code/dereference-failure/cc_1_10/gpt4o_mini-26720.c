//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256
#define PORT 8080

// Structure to represent a client
typedef struct {
    int sockfd;
    struct sockaddr_in address;
    int addr_len;
    char name[50];
} client_t;

client_t *clients[MAX_CLIENTS];

// Mutex for client management
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to send messages to all clients
void send_message(char *message, int sender) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i]) {
            // Skip sending the message to the sender
            if (clients[i]->sockfd != sender) {
                send(clients[i]->sockfd, message, strlen(message), 0);
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle individual client connections
void *client_handler(void *arg) {
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + 50];
    int leave_flag = 0;

    client_t *cli = (client_t *)arg;

    // Get the name of the new client
    if (recv(cli->sockfd, cli->name, sizeof(cli->name), 0) <= 0) {
        leave_flag = 1;
    } else {
        snprintf(message, sizeof(message), "%s joined the chat!\n", cli->name);
        send_message(message, cli->sockfd);
    }

    while (1) {
        if (leave_flag) break;

        int receive = recv(cli->sockfd, buffer, sizeof(buffer), 0);
        if (receive > 0) {
            // Prepare the message for sending
            buffer[receive] = '\0';
            snprintf(message, sizeof(message), "%s: %s", cli->name, buffer);
            send_message(message, cli->sockfd);
        } else {
            leave_flag = 1;
        }
    }
    
    // Cleanup on leave
    close(cli->sockfd);
    snprintf(message, sizeof(message), "%s left the chat.\n", cli->name);
    send_message(message, cli->sockfd);
    free(cli);
    pthread_exit(NULL);
}

// Main function to set up the server
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Creating socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Address family, port, and IP
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("💬 Chat server is running on port %d.. ready to twist the minds! 💬\n", PORT);

    while (1) {
        // Accept new connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new client object
        client_t *cli = (client_t *)malloc(sizeof(client_t));
        cli->sockfd = new_socket;
        cli->address = address;
        cli->addr_len = addrlen;

        // Add the client to the list
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = cli;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a new thread for the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, (void*)cli) != 0) {
            perror("Thread creation failed");
        }
    }

    return 0;
}