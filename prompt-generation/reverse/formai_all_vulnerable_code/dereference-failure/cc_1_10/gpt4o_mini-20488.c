//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to create the wise scribe (server)
void start_wise_scribe() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Wisdom that the scribe shall speak when hailed by a knight
    const char *wisdom = "Hark, brave knight! What wisdom dost thou seek?";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Creation of socket hath failed!");
        exit(EXIT_FAILURE);
    }

    // Attaching the socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Failed to set socket options!");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET; // Use IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(PORT); // Prepare for the chosen port

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Failed to bind the socket!");
        exit(EXIT_FAILURE);
    }

    // Start listening for knights
    if (listen(server_fd, 3) < 0) {
        perror("Failed to listen!");
        exit(EXIT_FAILURE);
    }
    
    printf("The wise scribe waits for knights...\n");

    // Main loop to accept messages from knights
    while (1) {
        printf("A knight approacheth...\n");
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Failed to accept a knight!");
            exit(EXIT_FAILURE);
        }

        // Receiving the knight's message
        read(client_fd, buffer, BUFFER_SIZE);
        printf("The knight hath spoken: %s\n", buffer);

        // Responding with wisdom
        send(client_fd, wisdom, strlen(wisdom), 0);
        printf("Wisdom hath been bestowed unto the knight!\n");

        // Close the connection with noble knight
        close(client_fd);
    }
}

// Function for the brave knight (client)
void brave_knight(const char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    // Creating socket for the brave knight
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Creation of socket failed!\n");
        return;
    }
    
    serv_addr.sin_family = AF_INET; // Use IPv4
    serv_addr.sin_port = htons(PORT); // Connect to the given port

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address or Address not supported!\n");
        return;
    }
    
    // Attempt to connect to the wise scribe
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection to the wise scribe hath failed!\n");
        return;
    }
    
    // Sending the message from the brave knight
    send(sock, message, strlen(message), 0);
    printf("The knight sends: %s\n", message);

    char buffer[BUFFER_SIZE] = {0};
    // Receiving wisdom from the scribe
    read(sock, buffer, BUFFER_SIZE);
    printf("The knight receiveth wisdom: %s\n", buffer);

    // Closing the socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc == 2 && strcmp(argv[1], "knight") == 0) {
        brave_knight("Greetings, wise scribe!");
    } else {
        start_wise_scribe();
    }
    return 0;
}