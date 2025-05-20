//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Constants
#define PORT 8080

// Function to handle client requests
void handle_client(int client_socket) {
    // Receive data from the client
    char buffer[1024];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("Error receiving data from client");
        return;
    }

    // Parse the client request
    char *request = strtok(buffer, " ");
    char *path = strtok(NULL, " ");

    // Handle the request
    if (strcmp(request, "GET") == 0) {
        // Send the requested file to the client
        FILE *file = fopen(path, "r");
        if (file == NULL) {
            perror("Error opening file");
            return;
        }

        char file_buffer[1024];
        while (fgets(file_buffer, sizeof(file_buffer), file) != NULL) {
            int bytes_sent = send(client_socket, file_buffer, strlen(file_buffer), 0);
            if (bytes_sent < 0) {
                perror("Error sending data to client");
                return;
            }
        }

        fclose(file);
    } else if (strcmp(request, "POST") == 0) {
        // Receive the data from the client and store it in a file
        FILE *file = fopen(path, "w");
        if (file == NULL) {
            perror("Error opening file");
            return;
        }

        char file_buffer[1024];
        while (bytes_received > 0) {
            bytes_received = recv(client_socket, file_buffer, sizeof(file_buffer), 0);
            if (bytes_received < 0) {
                perror("Error receiving data from client");
                return;
            }

            fwrite(file_buffer, 1, bytes_received, file);
        }

        fclose(file);
    } else {
        // Send a 404 error to the client
        char *error_message = "HTTP/1.1 404 Not Found\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
        int bytes_sent = send(client_socket, error_message, strlen(error_message), 0);
        if (bytes_sent < 0) {
            perror("Error sending data to client");
            return;
        }
    }

    // Close the client socket
    close(client_socket);
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket to port");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for incoming connections");
        return EXIT_FAILURE;
    }

    // Accept incoming connections and handle them in a loop
    while (1) {
        // Accept an incoming connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Handle the client request in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *(*)(void *)) handle_client, (void *) client_socket);
        pthread_detach(thread);
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}