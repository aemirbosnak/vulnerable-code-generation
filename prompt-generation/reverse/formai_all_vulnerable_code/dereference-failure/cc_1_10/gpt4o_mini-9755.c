//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdbool.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

volatile bool running = true;

void *handle_client(void *client_socket);
void log_message(const char *message);
void shutdown_server(int socket);
void cleanup_resources();

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    log_message("Server socket created.");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    log_message("Socket bound to port.");

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    log_message("Server is now listening for connections...");

    while (running) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            if (running) {
                perror("Client connection failed!");
                break; // Critical failure but don't shut down server
            }
            continue; // Shutdown requested, ignore accept errors
        }
        log_message("New client connected!");

        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
            log_message("Could not create thread for client handling!");
            shutdown_server(client_socket);
        }
        pthread_detach(thread_id);
    }
    
    cleanup_resources();
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while (running) {
        memset(buffer, 0, sizeof(buffer));
        bytes_read = read(sock, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0) {
            log_message("Client disconnected or error occurred.");
            break;
        }

        // Mimic paranoid behavior
        if (strstr(buffer, "SHUTDOWN") != NULL) {
            log_message("Shutdown command received! Terminating server...");
            running = false;
            break;
        }

        log_message("Message received from client:");
        printf("Client: %s\n", buffer);

        // Echo back the message
        if (write(sock, buffer, bytes_read) < 0) {
            perror("Failed to send message to client!");
            break;
        }
    }
    shutdown_server(sock);
    return NULL;
}

void log_message(const char *message) {
    FILE *log_file = fopen("server.log", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    } else {
        perror("Log file open failed!");
    }
}

void shutdown_server(int socket) {
    if (socket) {
        close(socket);
    }
    log_message("Client socket closed.");
}

void cleanup_resources() {
    log_message("Cleaning up server resources...");
}