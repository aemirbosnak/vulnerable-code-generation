//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFF_SIZE 1024

// Structure to store client information
typedef struct {
    int sockfd;
    char username[BUFF_SIZE];
} client_info;

// List of connected clients
client_info clients[MAX_CLIENTS];

// Mutex to protect the client list
pthread_mutex_t client_list_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client connections
void *handle_client(void *arg) {
    int sockfd = *(int *)arg;
    free(arg);

    // Receive the client's username
    char username[BUFF_SIZE];
    recv(sockfd, username, BUFF_SIZE, 0);

    // Add the client to the list of connected clients
    pthread_mutex_lock(&client_list_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sockfd == 0) {
            clients[i].sockfd = sockfd;
            strcpy(clients[i].username, username);
            break;
        }
    }
    pthread_mutex_unlock(&client_list_mutex);

    // Send a welcome message to the client
    char welcome_msg[] = "Welcome to the decentralized chat server!\n";
    send(sockfd, welcome_msg, strlen(welcome_msg), 0);

    // Keep reading and broadcasting messages from the client
    while (1) {
        char msg[BUFF_SIZE];
        int recv_len = recv(sockfd, msg, BUFF_SIZE, 0);

        // If the client has disconnected, remove them from the list of connected clients
        if (recv_len == 0) {
            pthread_mutex_lock(&client_list_mutex);
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].sockfd == sockfd) {
                    clients[i].sockfd = 0;
                    strcpy(clients[i].username, "");
                    break;
                }
            }
            pthread_mutex_unlock(&client_list_mutex);
            break;
        }

        // Broadcast the message to all other connected clients
        pthread_mutex_lock(&client_list_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sockfd != sockfd && clients[i].sockfd != 0) {
                send(clients[i].sockfd, msg, recv_len, 0);
            }
        }
        pthread_mutex_unlock(&client_list_mutex);
    }

    // Close the client's socket
    close(sockfd);
    return NULL;
}

int main() {
    // Create a socket for the server
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("Error creating server socket");
        return EXIT_FAILURE;
    }

    // Set the socket options for the server
    int opt = 1;
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        return EXIT_FAILURE;
    }

    // Bind the socket to the server's address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket to address");
        return EXIT_FAILURE;
    }

    // Listen for client connections
    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        perror("Error listening for client connections");
        return EXIT_FAILURE;
    }

    printf("Server is listening on port 8080...\n");

    // Accept client connections and handle them in separate threads
    pthread_t client_threads[MAX_CLIENTS];
    while (1) {
        int *client_sockfd = malloc(sizeof(int));
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        *client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (*client_sockfd == -1) {
            perror("Error accepting client connection");
            free(client_sockfd);
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_create(&client_threads[MAX_CLIENTS], NULL, handle_client, client_sockfd);
    }

    // Close the server socket
    close(server_sockfd);

    return EXIT_SUCCESS;
}