//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUF 1024

// Server function
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUF] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);

    // Accept a connection from a client
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Read and process the message
    int valread = read(new_socket, buffer, MAX_BUF);
    printf("Received: %s\n", buffer);
    for (int i = 0; i < valread; i++) {
        buffer[i] = toupper(buffer[i]);
    }
    send(new_socket, buffer, valread, 0);
    printf("Echoed back: %s\n", buffer);

    // Close sockets
    close(new_socket);
    close(server_fd);
}

// Client function
void start_client(const char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection failed \n");
        return;
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    // Receive the response
    int valread = read(sock, buffer, MAX_BUF);
    printf("Response from server: %s\n", buffer);

    // Close socket
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Start server in a separate process
    if (fork() == 0) {
        start_server();
        exit(0);
    }

    // Give the server some time to start before the client sends a message
    sleep(1);

    // Start client with the message from command line
    start_client(argv[1]);

    return 0;
}