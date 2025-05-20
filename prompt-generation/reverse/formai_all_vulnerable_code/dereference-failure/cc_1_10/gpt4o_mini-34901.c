//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle server operations
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("✅ Server is listening on port %d\n", PORT);
    
    while (1) {
        // Accepting incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Receiving message from client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("📬 Received: %s\n", buffer);
        
        // Echoing the message back to client
        send(new_socket, buffer, strlen(buffer), 0);
        printf("📤 Echoed: %s\n", buffer);
        
        // Close the socket
        close(new_socket);
    }

    close(server_fd);
}

// Function to handle client operations
void start_client(const char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("🚫 Socket creation error\n");
        return;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Converting IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("🚫 Invalid address/ Address not supported\n");
        return;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("🚫 Connection Failed\n");
        return;
    }
    
    // Sending message to server
    send(sock, message, strlen(message), 0);
    printf("📤 Sent: %s\n", message);
    
    // Receiving echoed message from server
    char buffer[BUFFER_SIZE] = {0};
    read(sock, buffer, BUFFER_SIZE);
    printf("📬 Echoed back: %s\n", buffer);
    
    // Close the socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc == 1) {
        // Start the server
        start_server();
    } else if (argc == 2) {
        // Start the client with provided message
        start_client(argv[1]);
    } else {
        printf("Usage: %s [message]\n", argv[0]);
        printf("If no message is provided, the server will start.\n");
    }
    
    return 0;
}