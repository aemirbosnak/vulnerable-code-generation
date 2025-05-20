//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function for error handling
void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Echo Server
void startServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        handleError("Socket failed");

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
        handleError("setsockopt");

    // Defining the socket address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        handleError("Bind failed");

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0)
        handleError("Listen failed");

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
            handleError("Accept failed");

        // Reset buffer
        memset(buffer, 0, BUFFER_SIZE);
        
        int bytesRead = read(new_socket, buffer, BUFFER_SIZE);
        if (bytesRead < 0) {
            handleError("Read failed");
        }
        
        printf("Received: %s\n", buffer);
        send(new_socket, buffer, bytesRead, 0);
        printf("Echoed: %s\n", buffer);
        
        close(new_socket);
    }
    
    close(server_fd);
}

// Echo Client
void startClient() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client!";
    char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        handleError("Socket creation error");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        handleError("Invalid address");

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        handleError("Connection failed");

    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    int bytesRead = read(sock, buffer, BUFFER_SIZE);
    if (bytesRead < 0)
        handleError("Read failed");

    printf("Message received from server: %s\n", buffer);
    
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [server/client]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        startServer();
    } else if (strcmp(argv[1], "client") == 0) {
        startClient();
    } else {
        fprintf(stderr, "Invalid argument: %s. Use 'server' or 'client'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}