//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 5

// Server Function
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start Listening
    if (listen(server_fd, BACKLOG) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    printf("🛡️ Server is running on port %d...\n", PORT);

    // Accepting clients
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            exit(EXIT_FAILURE);
        }

        // Communication with the client
        char buffer[BUFFER_SIZE] = {0};
        read(new_socket, buffer, BUFFER_SIZE);
        printf("📬 Message from client: %s\n", buffer);
        
        // Send a response
        char *message = "👋 Hello from the Server!";
        send(new_socket, message, strlen(message), 0);
        close(new_socket);
    }
}

// Client Function
void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("📭 Socket creation error\n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("📭 Invalid address/ Address not supported\n");
        return;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("📭 Connection Failed\n");
        return;
    }

    // Sending message to server
    char *hello = "🌍 Hello from the Client!";
    send(sock, hello, strlen(hello), 0);
    printf("🚀 Message sent from client: %s\n", hello);

    // Waiting to receive the response
    char buffer[BUFFER_SIZE] = {0};
    read(sock, buffer, BUFFER_SIZE);
    printf("📬 Server response: %s\n", buffer);
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <server/client>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        printf("⚠️ Invalid argument. Use 'server' or 'client'.\n");
    }
    return 0;
}