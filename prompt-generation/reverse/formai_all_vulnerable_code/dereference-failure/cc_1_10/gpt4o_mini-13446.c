//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle errors
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Server function
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handle_error("Socket creation failed");
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        handle_error("setsockopt");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handle_error("Bind failed");
    }
    
    // Start listening
    if (listen(server_fd, 3) < 0) {
        handle_error("Listen failed");
    }
    
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            handle_error("Accept failed");
        }
        
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("Received: %s\n", buffer);
        
        // Echo the message back
        send(new_socket, buffer, valread, 0);
        printf("Echoed back: %s\n", buffer);
        close(new_socket);
    }
}

// Client function
void start_client(const char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Connection failed");
    } 

    send(sock, message, strlen(message), 0);
    printf("Sent: %s\n", message);
    
    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("Received echo: %s\n", buffer);
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        // If message is provided as an argument, act as a client
        start_client(argv[1]);
    } else {
        // Otherwise, act as a server
        start_server();
    }

    return 0;
}