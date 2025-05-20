//FormAI DATASET v1.0 Category: Chat server ; Style: automated
// This is a C Chat Server program that allows multiple client connections
// Code written by [Your Name], a chatbot

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LEN 200

// User struct
typedef struct User {
    char username[20];
    int socket;
} User;

// Global vars
User clients[MAX_CLIENTS];
pthread_mutex_t mutex;

// Function Prototypes
void *handle_client(void *arg);
void broadcast_message(char *message, int sender_socket);

int main(int argc, char *argv[]) {

    int server_socket, client_socket, opt=1;
    struct sockaddr_in server, client;
    pthread_t thread_ids[MAX_CLIENTS];
    
    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating server socket\n");
        exit(1);
    }
    
    // Set socket options
    if( setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 ) {
        printf("Error setting socket options\n");
        exit(1);
    }
    
    // Configure server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( atoi(argv[1]) );
    
    // Bind server socket to IP and Port
    if( bind(server_socket, (struct sockaddr *)&server, sizeof(server) ) < 0 ) {
        printf("Error binding server socket\n");
        exit(1);
    }
    
    // Listen for incoming connections
    if( listen(server_socket, MAX_CLIENTS) < 0 ) {
        printf("Error listening for connections\n");
        exit(1);
    }
    
    printf("Server started and listening for connections...\n");
    int i=0;
    while( (client_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t*)&client)) ) {
        
        // Create user struct and add to clients array
        User *user = (User *)malloc( sizeof(User) );
        strcpy(user->username, "unknown");
        user->socket = client_socket;
        clients[i++] = *user;
        
        // Create thread to handle this client
        pthread_create(&thread_ids[i-1], NULL, handle_client, (void *)user);
        
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    }
    
    if(client_socket < 0) {
        printf("Error accepting connection\n");
        exit(1);
    }
    
    return 0;
}

void *handle_client(void *arg) {
    
    User *user = (User *)arg;
    char message[MAX_MESSAGE_LEN], incoming_message[MAX_MESSAGE_LEN];
    
    // Send welcome message
    sprintf(message, "Welcome to the chat server %s!\n", user->username);
    write(user->socket, message, strlen(message));
    
    pthread_mutex_lock(&mutex);
    broadcast_message("New user connected to the server\n", user->socket);
    pthread_mutex_unlock(&mutex);
    
    // Read incoming messages
    while( read(user->socket, incoming_message, MAX_MESSAGE_LEN) > 0 ) {
        
        incoming_message[strlen(incoming_message) - 1] = '\0'; // Remove newline char
        sprintf(message, "%s: %s\n", user->username, incoming_message);
        pthread_mutex_lock(&mutex);
        broadcast_message(message, user->socket);
        pthread_mutex_unlock(&mutex);
    }
    
    // Remove user from clients array
    for(int i=0; i<MAX_CLIENTS; i++) {
        if(clients[i].socket == user->socket) {
            memset(&clients[i], 0, sizeof(User));
            break;
        }
    }
    
    // Send goodbye message
    sprintf(message, "%s has left the chat\n", user->username);
    pthread_mutex_lock(&mutex);
    broadcast_message(message, user->socket);
    pthread_mutex_unlock(&mutex);
    
    // Close socket and free memory
    close(user->socket);
    free(user);
    pthread_exit(NULL);
}

void broadcast_message(char *message, int sender_socket) {
    
    for(int i=0; i<MAX_CLIENTS; i++) {
        int socket = clients[i].socket;
        
        if(socket != 0 && socket != sender_socket) {
            write(socket, message, strlen(message));
        }
    }
}