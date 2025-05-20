//GEMINI-pro DATASET v1.0 Category: Networking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

// Client thread function
void *client_thread(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];

    // Receive data from client
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        perror("Error receiving data");
        close(client_socket);
        pthread_exit(NULL);
    }

    // Process the data
    printf("Received data: %s\n", buffer);

    // Send data back to client
    int bytes_sent = send(client_socket, "Hello from server!", 18, 0);
    if (bytes_sent <= 0) {
        perror("Error sending data");
        close(client_socket);
        pthread_exit(NULL);
    }

    // Close the client socket
    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set the server socket to be reusable
    int reuseaddr_opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_opt, sizeof(reuseaddr_opt)) == -1) {
        perror("Error setting server socket to be reusable");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Bind the server socket to an address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket to address");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("Error listening for incoming connections");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %s\n", argv[1]);

    // Accept incoming connections and create a new thread for each client
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t client_thread_id;
        if (pthread_create(&client_thread_id, NULL, client_thread, &client_socket) != 0) {
            perror("Error creating client thread");
            close(client_socket);
            continue;
        }
    }

    // Close the server socket
    close(server_socket);
    return 0;
}