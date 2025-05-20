//FormAI DATASET v1.0 Category: Client Server Application ; Style: high level of detail
// Server code:
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_socket, client_socket, read_size;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    time_t current_time;
    char* time_string;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket options failed!");
        exit(EXIT_FAILURE);
    }

    // Set address of server
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed!");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed!");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    socklen_t address_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*) &client_address, &address_len);
    if (client_socket < 0) {
        perror("Accept failed!");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to client
    char* welcome_message = "Welcome to the server!\n";
    send(client_socket, welcome_message, strlen(welcome_message), 0);

    // Loop to handle client requests
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        // Get current time
        time(&current_time);
        time_string = ctime(&current_time);

        // Send current time to client
        send(client_socket, time_string, strlen(time_string), 0);

        // Clear buffer for next request
        memset(buffer, 0, BUFFER_SIZE);
    }

    return 0;
}