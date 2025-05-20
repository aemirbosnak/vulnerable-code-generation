//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to create and bind socket
int setup_server_socket() {
    int server_fd;
    struct sockaddr_in address;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    return server_fd;
}

// Function to generate a random number
int generate_random_number() {
    return rand() % 100 + 1; // Random number between 1 and 100
}

// Function to handle client connections
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    int number = generate_random_number();

    send(client_socket, &number, sizeof(number), 0);
    printf("Sent random number: %d\n", number);
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Client says: %s\n", buffer);
    close(client_socket);
}

// Server function
void run_server() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = setup_server_socket();
    listen(server_fd, 3);  // Listening for incoming connections
    printf("Server is running on port %d...\n", PORT);

    while (1) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        handle_client(client_socket);
    }
}

// Client function
void run_client() {
    int client_socket;
    struct sockaddr_in server_address;
    int number;

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        return;
    }

    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return;
    }

    recv(client_socket, &number, sizeof(number), 0);
    printf("Received number from server: %d\n", number);
    
    char message[] = "Thank you, server!";
    send(client_socket, message, strlen(message), 0);
    close(client_socket);
}

// Main function to start the server or client
int main(int argc, char const *argv[]) {
    if (argc > 1 && strcmp(argv[1], "client") == 0) {
        run_client();
    } else {
        run_server();
    }
    return 0;
}