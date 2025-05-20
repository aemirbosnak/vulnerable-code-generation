//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle errors
void handleError(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Server code
void startServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        handleError("Socket failed");

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
        handleError("Setsockopt failed");

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Binding the socket
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
        handleError("Bind failed");

    // Listening for connections
    if (listen(server_fd, 3) < 0)
        handleError("Listen failed");

    printf("🧩 Server is listening on port %d...\n", PORT);

    while (1) {
        // Waiting for a client
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0)
            handleError("Accept failed");
        
        read(new_socket, buffer, BUFFER_SIZE);
        printf("🧩 Received puzzle: %s\n", buffer);
        
        // Simple puzzle response
        char* response;
        if (strcmp(buffer, "What has keys but can't open locks?") == 0) {
            response = "A piano!";
        } else {
            response = "Let me ponder that...";
        }

        send(new_socket, response, strlen(response), 0);
        printf("🧩 Sent response: %s\n", response);
        close(new_socket);
    }
}

// Client code
void startClient() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char* question = "What has keys but can't open locks?";
    char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        handleError("Socket creation error");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        handleError("Invalid address/ Address not supported");

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        handleError("Connection failed");

    send(sock, question, strlen(question), 0);
    printf("🧩 Sent question: %s\n", question);

    read(sock, buffer, BUFFER_SIZE);
    printf("🧩 Received answer: %s\n", buffer);

    close(sock);
}

// Main function to decide client/server
int main(int argc, char const* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "server") == 0) {
        startServer();
    } else if (strcmp(argv[1], "client") == 0) {
        startClient();
    } else {
        fprintf(stderr, "Invalid option. Use 'server' or 'client'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}