//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_PASSWORD_LENGTH 32

struct client_info {
    int client_socket;
    char username[32];
    char password[32];
};

struct client_info clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_count_lock;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg);

    char username[32];
    char password[32];

    // Receive username
    recv(client_socket, username, sizeof(username), 0);

    // Receive password
    recv(client_socket, password, sizeof(password), 0);

    // Check if username and password are valid
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        // Generate random password
        char new_password[MAX_PASSWORD_LENGTH];
        srand(time(NULL));
        for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
            new_password[i] = rand() % 94 + 33;
        }

        // Send new password to client
        send(client_socket, new_password, sizeof(new_password), 0);
    } else {
        // Send error message to client
        char error_message[] = "Invalid username or password";
        send(client_socket, error_message, sizeof(error_message), 0);
    }

    // Close client socket
    close(client_socket);

    // Decrement client count
    pthread_mutex_lock(&client_count_lock);
    client_count--;
    pthread_mutex_unlock(&client_count_lock);

    return NULL;
}

int main() {
    // Initialize client count lock
    pthread_mutex_init(&client_count_lock, NULL);

    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server socket to reuse address
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind server socket to port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Main loop
    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Check if client count has reached maximum
        pthread_mutex_lock(&client_count_lock);
        if (client_count >= MAX_CLIENTS) {
            // Send error message to client
            char error_message[] = "Server is busy. Please try again later.";
            send(client_socket, error_message, sizeof(error_message), 0);

            // Close client socket
            close(client_socket);

            pthread_mutex_unlock(&client_count_lock);
            continue;
        }

        // Increment client count
        client_count++;
        pthread_mutex_unlock(&client_count_lock);

        // Create new thread to handle client
        pthread_t client_thread;
        int *client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = client_socket;
        if (pthread_create(&client_thread, NULL, handle_client, (void *)client_socket_ptr) != 0) {
            perror("pthread_create");
            close(client_socket);
            continue;
        }
    }

    // Close server socket
    close(server_socket);

    // Destroy client count lock
    pthread_mutex_destroy(&client_count_lock);

    return EXIT_SUCCESS;
}