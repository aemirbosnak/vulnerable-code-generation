//FormAI DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Define the struct that will hold client information
typedef struct {
    int sock_fd;
    char nickname[20];
    struct sockaddr_in* address;
    socklen_t addr_len;
} client_t;

// Declare functions
void* handle_client(void* client_info);
void send_to_all(char* message, int curr_sock_fd);
void send_private_message(char* message, int curr_sock_fd, char* target_user);
void nickname_exists(char* nickname);

// Global variables
client_t* clients[MAX_CLIENTS];
pthread_mutex_t lock;

int main(int argc, char const *argv[]) {
    // Validate command line arguments
    if(argc != 2) {
        fprintf(stderr, "Usage: ./server <port>\n");
        exit(1);
    }

    // Create server socket
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // Configure server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind server socket to address
    if(bind(server_sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket to address");
        exit(1);
    }

    // Start listening for connections
    if(listen(server_sock_fd, MAX_CLIENTS) == -1) {
        perror("Failed to start listening");
        exit(1);
    }

    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);

    // Main loop to accept client connections
    while(1) {
        // Accept client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock_fd = accept(server_sock_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if(client_sock_fd == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        // Allocate memory for the client struct and add to clients array
        client_t* client_info = malloc(sizeof(client_t));
        memset(client_info, 0, sizeof(client_t));
        client_info->sock_fd = client_sock_fd;
        client_info->address = &client_addr;
        client_info->addr_len = client_addr_len;
        pthread_mutex_lock(&lock);
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(clients[i] == NULL) {
                clients[i] = client_info;
                break;
            }
        }
        pthread_mutex_unlock(&lock);

        // Create a thread to handle client messages
        pthread_t client_thread;
        if(pthread_create(&client_thread, NULL, handle_client, (void*)client_info) != 0) {
            perror("Failed to create client thread");
            continue;
        }
    }

    return 0;
}

void* handle_client(void* client_info) {
    client_t* client = (client_t*)client_info;

    // Send welcome message to client
    char welcome_msg[BUFFER_SIZE];
    sprintf(welcome_msg, "Welcome to the chatroom, %s!\n", client->nickname);
    send(client->sock_fd, welcome_msg, strlen(welcome_msg), 0);

    // Receive messages from client
    char buffer[BUFFER_SIZE];
    while(recv(client->sock_fd, buffer, BUFFER_SIZE, 0) > 0) {
        // Parse message to determine action
        if(strncmp(buffer, "/nick ", 6) == 0) {
            // Set nickname for client
            char* nickname = strtok(buffer + 6, "\n");
            nickname_exists(nickname);
            strcpy(client->nickname, nickname);
            char msg[BUFFER_SIZE];
            sprintf(msg, "%s changed name to %s\n", inet_ntoa(client->address->sin_addr), client->nickname);
            send_to_all(msg, client->sock_fd);
        } else if (strncmp(buffer, "/msg ", 5) == 0) {
            // Send private message to target user
            int first_space = strcspn(buffer + 5, " ");
            char target_user[20];
            strncpy(target_user, buffer + 5, first_space);
            target_user[first_space] = '\0';
            char* message = strtok(buffer + 5 + first_space + 1, "\n");
            send_private_message(message, client->sock_fd, target_user);
        } else {
            // Send message to all clients
            char msg[BUFFER_SIZE];
            sprintf(msg, "%s: %s", client->nickname, buffer);
            send_to_all(msg, client->sock_fd);
        }

        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);
    }

    // If client disconnects, remove client from clients array and free memory
    pthread_mutex_lock(&lock);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i] == client) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&lock);

    char disconnect_msg[BUFFER_SIZE];
    sprintf(disconnect_msg, "%s has disconnected\n", client->nickname);
    send_to_all(disconnect_msg, client->sock_fd);

    close(client->sock_fd);
    free(client_info);
    pthread_exit(NULL);
}

void send_to_all(char* message, int curr_sock_fd) {
    pthread_mutex_lock(&lock);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i] != NULL && clients[i]->sock_fd != curr_sock_fd) {
            send(clients[i]->sock_fd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}

void send_private_message(char* message, int curr_sock_fd, char* target_user) {
    pthread_mutex_lock(&lock);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i] != NULL && strcmp(clients[i]->nickname, target_user) == 0 && clients[i]->sock_fd != curr_sock_fd) {
            char msg[BUFFER_SIZE];
            sprintf(msg, "(Private) %s: %s", target_user, message);
            send(clients[i]->sock_fd, msg, strlen(msg), 0);
            return;
        }
    }
    pthread_mutex_unlock(&lock);
}

void nickname_exists(char* nickname) {
    pthread_mutex_lock(&lock);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i] != NULL && strcmp(clients[i]->nickname, nickname) == 0) {
            char msg[BUFFER_SIZE];
            sprintf(msg, "Nickname %s is already taken. Please choose another nickname.\n", nickname);
            send(clients[i]->sock_fd, msg, strlen(msg), 0);
            exit(1);
        }
    }
    pthread_mutex_unlock(&lock);
}