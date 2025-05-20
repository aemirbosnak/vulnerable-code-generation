//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: imaginative
// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_QUOTES 10
#define BUFFER_SIZE 256

const char* quotes[MAX_QUOTES] = {
    "The only limit to our realization of tomorrow is our doubts of today.",
    "In the middle of difficulty lies opportunity.",
    "Life is 10% what happens to us and 90% how we react to it.",
    "The future belongs to those who believe in the beauty of their dreams.",
    "Success is not final, failure is not fatal: It is the courage to continue that counts.",
    "Believe you can and you're halfway there.",
    "Act as if what you do makes a difference. It does.",
    "Success usually comes to those who are too busy to be looking for it.",
    "You are never too old to set another goal or to dream a new dream.",
    "What lies behind us and what lies before us are tiny matters compared to what lies within us."
};

// Function to send a quote to the client
void* handle_client(void* arg) {
    int new_socket = *((int*)arg);
    free(arg); // Prevent memory leak
    char buffer[BUFFER_SIZE] = {0};

    // Send a quote randomly
    int random_index = rand() % MAX_QUOTES;
    send(new_socket, quotes[random_index], strlen(quotes[random_index]), 0);
    
    // Acknowledge message
    recv(new_socket, buffer, BUFFER_SIZE, 0);
    printf("Acknowledgment from client: %s\n", buffer);
    
    close(new_socket);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the specified port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Magical Quote Server is running on port %d...\n", PORT);
    
    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accepting client failed");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        int* new_sock_ptr = malloc(1);
        *new_sock_ptr = new_socket;

        if (pthread_create(&thread_id, NULL, handle_client, new_sock_ptr) != 0) {
            perror("Failed to create thread");
            free(new_sock_ptr);
        }
    }

    close(server_fd);
    return 0;
}