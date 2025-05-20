//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

volatile sig_atomic_t keepRunning = 1;

void handle_signal(int signal) {
    keepRunning = 0;
}

void *client_handler(void *client_sockfd) {
    int sock = *(int*)client_sockfd;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        printf("Client: %s\n", buffer);
        
        // Sending response back to client
        char *response = "Message received\n";
        send(sock, response, strlen(response), 0);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(sock);
    free(client_sockfd);
    return NULL;
}

int main() {
    signal(SIGINT, handle_signal);

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Binding to the specified port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (keepRunning) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        if (new_socket < 0) {
            if (keepRunning) {
                perror("Accept failed");
            }
            continue; // Ignore if we are shutting down
        }

        printf("New connection established\n");
        
        int *new_sock = malloc(1);
        *new_sock = new_socket;

        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, (void*)new_sock) != 0) {
            perror("Thread creation failed");
            free(new_sock);
        }
    }

    close(server_fd);
    printf("Server is shutting down...\n");

    return 0;
}