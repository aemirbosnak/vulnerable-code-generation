//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Server code
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept a connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Read data from client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Received message: %s\n", buffer);

        // Echo the message back to client
        send(new_socket, buffer, strlen(buffer), 0);
        printf("Echoed message back to client\n");

        close(new_socket);
    }
}

// Client code
void start_client(const char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\n Invalid address/ Address not supported \n");
        return;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Connection Failed \n");
        return;
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    // Read response from server
    read(sock, buffer, BUFFER_SIZE);
    printf("Message received from server: %s\n", buffer);

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <client_message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Run the server in a separate thread (or directly for simplicity)
    if (fork() == 0) {
        start_server();
        return 0;
    }

    // Simulate a delay for the server to start
    sleep(1);

    // Start client
    start_client(argv[1]);
    return 0;
}