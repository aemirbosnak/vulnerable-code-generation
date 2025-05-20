//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Server code
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handle_error("socket failed");
    }

    // Prepare the sockaddr_in structure
    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
    address.sin_port = htons(SERVER_PORT); // Convert to network byte order

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handle_error("bind failed");
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        handle_error("listen failed");
    }
    printf("Server listening on port %d...\n", SERVER_PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            handle_error("accept failed");
        }

        // Receive message from client
        int bytes_read = read(new_socket, buffer, BUFFER_SIZE);
        if (bytes_read > 0) {
            printf("Message from client: %s\n", buffer);
            // Echo back the received message
            send(new_socket, buffer, bytes_read, 0);
        }

        close(new_socket); // Close the client socket
        memset(buffer, 0, BUFFER_SIZE); // Clear buffer for next message
    }
    
    close(server_fd); // Close the server socket
}

// Client code
void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    
    // Create socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET; // IPv4
    serv_addr.sin_port = htons(SERVER_PORT); // Port

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        handle_error("Invalid address / Address not supported");
    }

    // Try to connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Connection failed");
    }

    printf("Connected to server. Type messages to send:\n");

    while (1) {
        // Get user input
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        // Send message to server
        send(sock, buffer, strlen(buffer), 0);

        // Receive echo from the server
        read(sock, buffer, BUFFER_SIZE);
        printf("Server: %s", buffer);
        memset(buffer, 0, BUFFER_SIZE); // Clear buffer for next message
    }
    
    close(sock); // Close the client socket
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}