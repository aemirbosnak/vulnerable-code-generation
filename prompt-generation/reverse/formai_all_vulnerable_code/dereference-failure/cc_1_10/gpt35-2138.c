//FormAI DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* handle_client(void*);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: ./chat_server <port>\n");
        exit(1);
    }

    int port = atoi(argv[1]);

    // Create Socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in server_address;
    bzero((char*) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind the socket to specified port
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Failed to listen");
        close(server_socket);
        exit(1);
    }

    printf("Server started on port %d...\n", port);

    while(1) {

        // Accept incoming connection
        int client_socket;
        struct sockaddr_in client_address;
        socklen_t client_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_length);

        if (client_socket < 0) {
            perror("Failed to accept client connection");
            close(server_socket);
            exit(1);
        }

        printf("New client connected. IP: %s, Port: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*) &client_socket) < 0) {
            perror("Thread creation failed");
            close(client_socket);
            close(server_socket);
            exit(1);
        }

        pthread_detach(thread_id);

    }

    close(server_socket);

    return 0;
}

void* handle_client(void* arg) {

    int client_socket = *(int*) arg;

    char client_name[50];

    // Get client name and greet
    if (recv(client_socket, client_name, 50, 0) > 0) {
        pthread_mutex_lock(&mutex);
        printf("Welcome to the chat, %s!\n", client_name);
        pthread_mutex_unlock(&mutex);
    } else {
        perror("Failed to receive client name");
        close(client_socket);
        pthread_exit(NULL);
    }

    char message[255];

    while(1) {

        // Receive message from client
        if (recv(client_socket, message, 255, 0) > 0) {

            // Check if client wants to quit
            if (strcmp(message, "quit\n") == 0) {
                pthread_mutex_lock(&mutex);
                printf("%s has left the chat.\n", client_name);
                pthread_mutex_unlock(&mutex);
                close(client_socket);
                pthread_exit(NULL);
            }

            // Broadcast message to other clients
            pthread_mutex_lock(&mutex);
            printf("[%s]: %s", client_name, message);
            pthread_mutex_unlock(&mutex);

            // Clear message buffer
            bzero(message, sizeof(message));

        } else {
            perror("Failed to receive message from client");
            close(client_socket);
            pthread_exit(NULL);
        }

    }

    return NULL;
}