//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Romeo's server
void romeo_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("🌹 Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("💔 Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("🚪 Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("🕊️ Romeo awaits his Juliet...\n");

    // Accept a connection from Juliet
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("❌ Failed to accept");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive messages from Juliet
        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            break; // Connection closed
        }
        printf("🎭 Juliet: %s\n", buffer);

        // Respond to Juliet
        memset(buffer, 0, BUFFER_SIZE);
        printf("🌹 Romeo: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);
}

// Juliet's client
void juliet_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("❌ Socket creation error\n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("❌ Invalid address/ Address not supported\n");
        return;
    }

    // Connect to Romeo's server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("💔 Connection failed\n");
        return;
    }

    while (1) {
        // Send messages to Romeo
        printf("🌹 Juliet: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);

        // Receive messages from Romeo
        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(sock, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            break; // Connection closed
        }
        printf("🎭 Romeo: %s\n", buffer);
    }

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc > 1 && strcmp(argv[1], "client") == 0) {
        juliet_client();
    } else {
        romeo_server();
    }
    return 0;
}